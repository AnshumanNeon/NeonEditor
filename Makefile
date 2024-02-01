INCLUDE_DIRS = -I./deps/vector/

all:
	gcc -Wall -Wextra -Werror -pedantic -std=c99 $(INCLUDE_DIRS) ./main.c -lncurses -o ./main
