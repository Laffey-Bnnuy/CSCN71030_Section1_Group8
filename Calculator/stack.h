#include <stdlib.h>
#include <stdio.h>
#pragma once
struct Stack {
    int top, cap;
    int a[100];
};

struct Stack* createStack(int cap);

void deleteStack(struct Stack* stack);

int isFull(struct Stack* stack);

int isEmpty(struct Stack* stack);

int push(struct Stack* stack, int x);

int pop(struct Stack* stack);

int peek(struct Stack* stack);