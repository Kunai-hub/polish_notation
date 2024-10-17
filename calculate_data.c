#include "graph.h"

double counter(char *output_str, double x) {
    int n = strlen(output_str);
    double num1;
    double num2;
    double operations[50] = {};
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        if (output_str[i] == 'x') {
            operations[ptr] = x;  // Замена Х на переданное значение
            ptr++;
        } else if (output_str[i] >= '0' && output_str[i] <= '9') {
            operations[ptr] = output_str[i] - '0';  // Преобразование символа в соответсующее число
            ptr++;
        } else if (output_str[i] == '+') {
            num2 = operations[ptr - 1];
            num1 = operations[ptr - 2];
            ptr -= 2;
            operations[ptr] = num1 + num2;  // Сложение
            ptr++;
        } else if (output_str[i] == '-') {
            num2 = operations[ptr - 1];
            num1 = operations[ptr - 2];
            ptr -= 2;
            operations[ptr] = num1 - num2;  // Вычитание
            ptr++;
        } else if (output_str[i] == '*') {
            num2 = operations[ptr - 1];
            num1 = operations[ptr - 2];
            ptr -= 2;
            operations[ptr] = num1 * num2;  // Умножение
            ptr++;
        } else if (output_str[i] == '/') {
            num2 = operations[ptr - 1];
            num1 = operations[ptr - 2];
            if (num2 != 0) {
                ptr -= 2;
                operations[ptr] = num1 / num2;  // Деление
                ptr++;
            } else {
                ptr -= 2;
                operations[ptr] = 1000;  // Делить на ноль нельзя!!!!!
                ptr++;
            }
        } else if (output_str[i] == 's') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = sin(num1);  // Синус
        } else if (output_str[i] == 'c') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = cos(num1);  // Косинус
        } else if (output_str[i] == 't') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = tan(num1);  // Тангенс
        } else if (output_str[i] == 'g') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = 1 / tan(num1);  // Котангенс
        } else if (output_str[i] == 'q') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = sqrt(num1);  // Корень
        } else if (output_str[i] == 'l') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = log(num1);  // Логарифм
        }
    }
    ptr--;
    return operations[ptr];  // Последний результат возвращаем
}

void add_function_on_graph(char **graph, int height, int width, char *polish) {
    for (int x = 1; x < width; x++) {
        int y = height / 2 + 10 * counter(polish, x / PI);
        if (y > 0 && y < 25) graph[y][x] = STAR;  // Добавили звездочку :)
    }
}
