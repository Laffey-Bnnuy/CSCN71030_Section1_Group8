#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "calculator.h"
#include "advancedMath.h"
#include "matrix.h"
#include "graph.h"

// Main program entry point
int main() {
    printf("Welcome to the Scientific Calculator!\n");

    // Call the UI to handle user interactions and route inputs to the correct module
    handleUserChoice();

    printf("Exiting calculator. Goodbye!\n");
    return 0;
}
