#include "graph.h"

char **init_data(int height, int width) {
    char **matrix;
    matrix = (char **)malloc(height * sizeof(char *));
    for (int y = 0; y < height; y++) {
        matrix[y] = (char *)malloc((width + 1) * sizeof(char));
        memset(matrix[y], ' ', width);
        matrix[y][width] = '\0';
    }
    return matrix;
}

void init_graph(char **matrix, int height, int width) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            matrix[y][x] = POINT;
        }
    }
    for (int y = 0; y < HEIGHT; y++) {
        matrix[y][width + 1] = '\0';
    }
}

void draw_graph(char **matrix, int height) {
    for (int y = 0; y < height - 1; y++) {
        puts(matrix[y]);
    }
}

void free_data(char **matrix, int height) {
    for (int y = 0; y < height; y++) free(matrix[y]);
    free(matrix);
}

void free_stack(struct stack *head) {
    struct stack *current = head;
    struct stack *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
