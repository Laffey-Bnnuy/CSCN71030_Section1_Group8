#define _CRT_SECURE_NO_WARNINGS
#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include "basicmath.h"     // Basic math functions
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
            // Clear input buffer
            continue;
        }
        while (getchar() != '\n');
        if (choice == 5) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        switch (choice) {
        case 1:
            basic_math_main();
            break;
        case 2:
            advanced_math();
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
        
    }
}

void acceptUserInput(char* inputBuffer, int bufferSize) {
    if (fgets(inputBuffer, bufferSize, stdin) == NULL) {
        handleError("Error reading input.");
        return;
    }

    // Remove newline character if present
    size_t len = strlen(inputBuffer);
    if (len > 0 && inputBuffer[len - 1] == '\n') {
        inputBuffer[len - 1] = '\0';
    }
}

// Function to validate user input
bool validateInput(const char* expression) {
    if (expression == NULL || strlen(expression) == 0) {
        return false;
    }

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (!(isdigit(ch) || strchr("+-*/().", ch))) {
            return false; // Invalid character found
        }
    }

    return true; // Input is valid
}
// Function to display the computed result
void displayResult(double result) {
    printf("Result: %.10g\n", result);
}

// Function to handle and display error messages
void handleError(const char* errorMessage) {
    fprintf(stderr, "Error: %s\n", errorMessage);
}