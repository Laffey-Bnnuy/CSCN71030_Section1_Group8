#include "advancedMath.h"

int main(void) {
    
    char infix[MAX_STACK_SIZE];
    char postfix[MAX_STACK_SIZE * 2];

    printf("Enter an infix expression: ");

    fgets(infix, MAX_STACK_SIZE, stdin);

    // Remove the newline character from the input
    infix[strcspn(infix, "\n")] = '\0';

    // Convert infix to postfix
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    double result = evaluate_postfix(postfix);
    printf("Result: %.5f\n", result);
    free_stack;
    return 0;
}