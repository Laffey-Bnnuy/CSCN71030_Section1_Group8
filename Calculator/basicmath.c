
#include <stdio.h>
#include "basicmath.h"

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
            return result;  // Return the previous result unchanged
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
        while (getchar() != '\n');
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '=')
            return op;
        printf("Invalid operator! Enter +, -, *, / or =: ");
    }
}
void basic_math_main() {
    double result, num;
    char operation;

    // Get the first number
    printf("Enter the first number: ");
    result = getNumber();

    while (1) {
        // Get operation from user
        printf("Enter operation (+, -, *, /) or '=' to finish: ");
        operation = getOperation();

        if (operation == '=') break; // Exit when '=' is pressed

        // Get the next number
        printf("Enter next number: ");
        num = getNumber();

        // Perform the operation
        result = calculate(result, operation, num);
    }

    printf("Final Result: %.6f\n", result);
    
}