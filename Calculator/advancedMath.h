#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX_STACK_SIZE 10000

// Stack implementation for double values

void push(double value);

double pop();
// Stack implementation for characters (used in infix to postfix conversion)


void char_push(char value);

char char_pop();

int is_trig_function(char* expression, int index);


int is_operator(char ch);

int precedence(char op);

double parse_number(char* expression, int* index);

double func_calculate(char* func, double operand);
void infix_to_postfix(char* infix, char* postfix);

double evaluate_postfix(char* expression);