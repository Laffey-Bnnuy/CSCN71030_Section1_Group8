#define _CRT_SECURE_NO_WARNINGS
#include "ui.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "calculator.h"     // Basic math functions
#include "advancedMath.h"   // Advanced math functions


// Function to display the calculator menu
void displayMenu() {
    printf("\n--- Scientific Calculator ---\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Sine (sin)\n");
    printf("6. Cosine (cos)\n");
    printf("7. Tangent (tan)\n");
    printf("8. Square Root (sqrt)\n");
    printf("9. Logarithm Base 10 (log)\n");
    printf("10. Natural Log (ln)\n");
    printf("11. Exit\n");
}
 

// Function to handle user choices in the menu
void handleUserChoice() {
    int choice;
    char inputBuffer[100];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");

        // Read user input and validate if it's a number
        if (scanf("%d", &choice) != 1) {
            handleError("Invalid choice. Please enter a number.");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        while (getchar() != '\n'); // Clear input buffer

        if (choice == 11) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        // Prompt user for input
        if (choice >= 1 && choice <= 4) {
            printf("Enter two numbers separated by a space: ");
        }
        else {
            printf("Enter a number: ");
        }

        acceptUserInput(inputBuffer, sizeof(inputBuffer));

        if (validateInput(inputBuffer)) {
            double result = sendToComputationModule(inputBuffer);
            displayResult(result);
        }
        else {
            handleError("Invalid input. Please enter a valid number.");
        }
    }
}

// Function to accept user input
void acceptUserInput(char* inputBuffer, int bufferSize) {
    if (fgets(inputBuffer, bufferSize, stdin) != NULL) {
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; // Remove newline
    }
}

// Function to validate user input (numbers and basic operators allowed)
bool validateInput(const char* expression) {
    if (expression == NULL || strlen(expression) == 0) {
        return false;
    }

    for (int i = 0; expression[i] != '\0'; i++) {
        if (!(isdigit(expression[i]) || expression[i] == '.' || expression[i] == '-' ||
            expression[i] == ' ' || expression[i] == '+')) {
            return false;
        }
    }

    return true;
}

double sendToComputationModule(int choice, double value1, double value2) {
    char expression[50];  // Store user input for advanced math

    switch (choice) {
    case 1: return calculate(value1, '+', value2);
    case 2: return calculate(value1, '-', value2);
    case 3: return calculate(value1, '*', value2);
    case 4: return calculate(value1, '/', value2);
    case 5:
        snprintf(expression, sizeof(expression), "sin(%lf)", value1);
        return evaluate_postfix(expression);
    case 6:
        snprintf(expression, sizeof(expression), "cos(%lf)", value1);
        return evaluate_postfix(expression);
    case 7:
        snprintf(expression, sizeof(expression), "tan(%lf)", value1);
        return evaluate_postfix(expression);
    case 8:
        snprintf(expression, sizeof(expression), "sqrt(%lf)", value1);
        return evaluate_postfix(expression);
    case 9:
        snprintf(expression, sizeof(expression), "log(%lf)", value1);
        return evaluate_postfix(expression);
    case 10:
        snprintf(expression, sizeof(expression), "ln(%lf)", value1);
        return evaluate_postfix(expression);
    default:
        handleError("Invalid operation.");
        return 0.0;
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
