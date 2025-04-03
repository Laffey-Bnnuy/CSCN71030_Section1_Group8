#include "advancedMath.h"
#include "matrix.h"
#include "fileHandling.h"
#include "graph.h"
#include <string.h>
#include "basicmath.h"
#include "UI.h"

void handle_cmd_argument(char* argument);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n<command>: UI, matrix, save_matrices, load_matrices, point_area, distance_2d, distance_3d, advanced_math, adv_math_history, adv_math_wipe, basic_math", argv[0]);
        return 1;
    }

    // Check the command-line argument
    
    
    char buffer[100];
    strncpy(buffer, argv[1], 100);
    buffer[strcspn(buffer, "\n")] = '\0';
    
    while (1) {
       
        handle_cmd_argument(buffer); 
        printf("\n<command>: UI, matrix, save_matrices, load_matrices, point_area, distance_2d, distance_3d, advanced_math, adv_math_history, adv_math_wipe, basic_math\nEnter your <command>:");
        gets_s(buffer, 100); 
       
        if (strcmp(buffer ,"0") == 0) {
            exit(0);
        }
    }
    return 0;
}

void handle_cmd_argument(char* argument) {
    if (strcmp(argument, "matrix") == 0) {
        matrix_main();
    }
    // You can add other commands as needed.
    else if (strcmp(argument, "save_matrices") == 0) {
        save_matrices_to_file();
    }
    else if (strcmp(argument, "load_matrices") == 0) {
        load_matrices_from_file();
    }
    else if (strcmp(argument, "point_area") == 0) {
        point_area_perimeter();
    }
    else if (strcmp(argument, "distance_2d") == 0) {
        distance_2D_main();
    }
    else if (strcmp(argument, "distance_3d") == 0) {
        distance_3D_main();
    }
    else if (strcmp(argument, "advanced_math") == 0) {
        advanced_math();
    }
    else if (strcmp(argument, "adv_math_history") == 0) {
        load_from_file_postfix();
    }
    else if (strcmp(argument, "adv_math_wipe") == 0) {
        advanced_math_wipe();
    }
    else if (strcmp(argument, "basic_math") == 0) {
        basic_math_main();
    }
    else if (strcmp(argument, "UI") == 0) {
        
        handleUserChoice();
    }
    else {
        printf("Unknown command: %s\n", argument);
       
    }
}
