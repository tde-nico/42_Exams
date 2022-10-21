clang++ -Wall -Wextra -Werror -W -std=c++98 *.cpp -o start && \
./start > out.txt && \
diff test.txt out.txt && \
rm start out.txt