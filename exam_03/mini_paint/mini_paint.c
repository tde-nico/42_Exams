#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_zone
{
	int		width;
	int		height;
	char	background;
}	t_zone;

typedef struct s_shape
{
	char			type;
	float			x;
	float			y;
	float			radius;
	char			color;
}	t_shape;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	str_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	clear(FILE *file, char *drawing, char *str)
{
	if (file)
		fclose(file);
	if (drawing)
		free(drawing);
	if (str)
		str_error(str);
	return (1);
}

char	*get_zone(FILE *file, t_zone *zone)
{
	int		i;
	char	*drawing;

	if (fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background) != 3)
		return (NULL);
	if (!(zone->width > 0 && zone->width <= 300 && zone->height > 0 && zone->height <= 300))
		return (NULL);
	drawing = malloc(sizeof(drawing) * zone->width * zone->height);
	if (!drawing)
		return (NULL);
	i = -1;
	while (++i < (zone->width * zone->height))
		drawing[i] = zone->background;
	return (drawing);
}

int	in_circle(float x, float y, t_shape *shape)
{
	float	dist;

	dist = sqrtf(powf(x - shape->x, 2.0) + powf(y - shape->y, 2.0));
	if (dist <= shape->radius)
	{
		if ((shape->radius - dist) < 1.00000000)
			return (2);
		return (1);
	}
	return (0);
}

void	draw_shape(char *drawing, t_shape *shape, t_zone *zone)
{
	int	i;
	int	j;
	int	ret;

	i = -1;
	while (++i < zone->height)
	{
		j = -1;
		while (++j < zone->width)
		{
			ret = in_circle((float)j, (float)i, shape);
			if ((shape->type == 'c' && ret == 2)
				|| (shape->type == 'C' && ret))
				drawing[(i * zone->width) + j] = shape->color;
		}
	}
}

int	draw_shapes(FILE *file, char *drawing, t_zone *zone)
{
	t_shape	shape;
	int		ret;

	while ((ret = fscanf(file, "%c %f %f %f %c\n", &shape.type, &shape.x, &shape.y, &shape.radius, &shape.color)) == 5)
	{
		if (!(shape.radius > 0.00000000 && (shape.type == 'c' || shape.type == 'C')))
			return (0);
		draw_shape(drawing, &shape, zone);
	}
	if (ret != -1)
		return (0);
	return (1);
}

void	draw_drawing(char *drawing, t_zone *zone)
{
	int	i;

	i = -1;
	while (++i < zone->height)
	{
		write(1, drawing + (i * zone->width), zone->width);
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	t_zone	zone;
	FILE	*file;
	char	*drawing;

	zone.width = 0;
	zone.height = 0;
	zone.background = 0;
	if (argc != 2)
		return (str_error("Error: argument\n"));
	file = fopen(argv[1], "r");
	if (!file)
		return (str_error("Error: Operation file corrupted\n"));
	drawing = get_zone(file, &zone);
	if (!drawing)
		return (clear(file, NULL, "Error: Operation file corrupted\n"));
	if (!draw_shapes(file, drawing, &zone))
		return (clear(file, drawing, "Error: Operation file corrupted\n"));
	draw_drawing(drawing, &zone);
	clear(file, drawing, NULL);
	return (0);
}
