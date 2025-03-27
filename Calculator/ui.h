#pragma once
#include <stdbool.h>

// Function to display the calculator menu
void displayMenu();

// Function to handle user choices in the menu
void handleUserChoice();

// Function to accept user input
void acceptUserInput(char* inputBuffer, int bufferSize);

// Function to validate user input
bool validateInput(const char *expression);

// Function to send expression to computation module
double sendToComputationModule(const char* expression);

//Function do display the compued result
void displayResult(double result);

// Function to hanlde and display error messages
void handleError(const char* errorMessage);

