CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
BUILD=../build/

all: graph

graph: graph.c polish_notation.c data.c calculate_data.c
	$(CC) $(FLAGS) graph.c polish_notation.c data.c calculate_data.c -o $(BUILD)graph -lm

rebuild: clean graph

clean:
	rm -rf $(BUILD)graph
