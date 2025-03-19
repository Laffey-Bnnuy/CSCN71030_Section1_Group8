#define _CRT_SECURE_NO_WARNINGS  // Suppress scanf() warnings in Visual Studio
#include <stdio.h>
#include "calculator.h"

int main() {
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
    return 0;
}