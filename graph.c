#include "graph.h"

int main() {
    char **graph = init_data(HEIGHT, WIDTH + 1);  // Создаем граф, двумерный массив
    struct stack *operations =
        NULL;  // Указатель на стек, инициализируем как НУЛЛ, для хранения операций преобразования
    char input_formula[100],
        polish_formula[100];  // Массивы для хранения строку формулы из инпута и формулы в польской нотации
    do {
        system("clear");  // Чистим консоль
        printf("Введите формулу: ");
        for (int i = 0; i < 100; i++) {
            char symbol = getchar();
            if (symbol == '\n') {
                input_formula[i] = '\0';
                break;
            }
            if (symbol != ' ')
                input_formula[i] = symbol;
            else
                i--;  // Читаем формулу игнор пробелов
        }
    } while (!check_input(input_formula));  // Проверка на нормальные символы
    polish_notation(operations, input_formula,
                    polish_formula);  // Преобразовываем входную строку в польскую штучку!
    printf("Формула в польской нотации: %s\n", polish_formula);
    init_graph(graph, HEIGHT, WIDTH);  // Инициализируем граф, связываем его с массивом graph
    add_function_on_graph(graph, HEIGHT, WIDTH, polish_formula);  // Размещаем звездочки в матрицу graph
    draw_graph(graph, HEIGHT);                                    // Рисуем график
    free_data(graph, HEIGHT);
    free_stack(operations);  // Чистим память матрицы!!!
    return 0;
}
