
#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "calculator.h"
#include "advancedMath.h"
#include "fileHandling.h"
#include "matrix.h"
#include "graph.h"

// Main program entry point
int main() {
    printf("Welcome to the Scientific Calculator!\n");

    // Call the UI to handle user interactions and route inputs to the correct module
    handleUserChoice();

    printf("Exiting calculator. Goodbye!\n");
 
    
    //advanced_math();
    matrix_main();
    //save_matrices_to_file();
   // load_matrices_from_file();
   // load_from_file_postfix();
    //point_area_perimeter();

    //distance_2D_main();
    return 0;
}
