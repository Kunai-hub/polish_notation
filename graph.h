#ifndef MAIN_H_
#define MAIN_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define POINT '.'
#define STAR '*'
#define PI acos(-1)

struct stack {
    char ch;
    struct stack *next;
};

// POLISH NOTATION
int check_input(char *input_string);       // Проверяем входную строку
struct stack *push(struct stack *, char);  // Помещаем в стек символ
char delete (struct stack **head);         // Удаляем из стека символ
int priority(char);                        // Возвращаем приоритет для символа
void polish_notation(struct stack *operations, char *input_str,
                     char *output_str);  // Преобразовываем строку в польскую НОТАЦИЮ))!

// CALCULATE DATA
double counter(char *output_str,
               double x);  // Принимает польскую нотацию и значение Х, возвращаем результат выражения
void add_function_on_graph(char **graph, int height, int width,
                           char *polish);  // Добавляем результаты функций на граф

// DRAWING GRAPH
char **init_data(int height, int width);  // Инициализируем данные для графа, то есть создаем массив
void init_graph(char **graph, int height, int width);  // ИИнициализируем граф, заполненный точками
void draw_graph(char **graph, int height);  // Отображаем граф на экране
void free_data(char **graph, int height);
void free_stack(struct stack *head);  // Чистим память!!!

#endif
