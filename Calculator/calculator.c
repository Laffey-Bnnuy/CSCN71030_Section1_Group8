#include <stdio.h>
#include "calculator.h"
#include <math.h>

// Function to perform the calculation based on operation
double calculate(double result, char operation, double num) {
    switch (operation) {
    case '+': return result + num;
    case '-': return result - num;
    case '*': return result * num;
    case '/':
        if (num != 0)
            return result / num;
        else {
            printf("Error: Division by zero is not allowed!\n");
            return NAN;  // Return the previous result unchanged
        }
    default:
        printf("Invalid operator! Use +, -, *, / or =\n");
        return result;
    }
}

// Function to get a valid number input
double getNumber() {
    double num;
    while (scanf_s("%lf", &num) != 1) {
        printf("Invalid input! Enter a valid number: ");
        while (getchar() != '\n'); // Clear the input buffer
    }
    return num;
}

// Function to get a valid operation input
char getOperation() {
    char op;
    while (1) {
        scanf_s(" %c", &op, 1);
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '=')
            return op;
        printf("Invalid operator! Enter +, -, *, / or =: ");
    }
}