#define _CRT_SECURE_NO_WARNINGS
#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"     // Basic math functions
#include "advancedMath.h"   // Advanced math functions
#include "matrix.h"         // Matrix operations
#include "graph.h"          // Graph computations

// Function to display the calculator menu
void displayMenu() {
    printf("\n--- Scientific Calculator ---\n");
    printf("1. Basic Math Operations (+, -, *, /)\n");
    printf("2. Advanced Math Functions (sin, cos, tan, sqrt, log, ln)\n");
    printf("3. Matrix Operations\n");
    printf("4. Graph Computations\n");
    printf("5. Exit\n");
}

// Function to handle user choices in the menu
void handleUserChoice() {
    int choice;
    double num1, num2, result;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            handleError("Invalid choice. Please enter a number.");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (choice == 5) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        switch (choice) {
        case 1:
            printf("Enter two numbers separated by a space: ");
            if (scanf("%lf %lf", &num1, &num2) != 2) {
                handleError("Invalid input. Please enter two valid numbers.");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            char op;
            printf("Enter operation (+, -, *, /): ");
            scanf(" %c", &op);
            result = calculate(num1, op, num2);
            break;
        case 2:
            printf("Enter an infix expression: ");
            char infix[MAX_STACK_SIZE];
            char postfix[MAX_STACK_SIZE * 2];
            scanf(" %s", infix);
            infix_to_postfix(infix, postfix);
            result = evaluate_postfix(postfix);
            break;
        case 3:
            matrix_main();
            continue;
        case 4:
            point_area_perimeter();
            continue;
        default:
            handleError("Invalid selection.");
            continue;
        }
        displayResult(result);
    }
}

// Function to display the computed result
void displayResult(double result) {
    printf("Result: %.10g\n", result);
}

// Function to handle and display error messages
void handleError(const char* errorMessage) {
    fprintf(stderr, "Error: %s\n", errorMessage);
}
