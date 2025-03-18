#include"advancedMath.h"

// Stack implementation for double values
double stack[MAX_STACK_SIZE];
int top = -1;
char char_stack[MAX_STACK_SIZE];
int char_top = -1;

void push(double value) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

double pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}


void char_push(char value) {
    if (char_top >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    char_stack[++char_top] = value;
}

char char_pop() {
    if (char_top < 0) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return char_stack[char_top--];
}

int is_trig_function(char* expression, int index) {
    if (strncmp(&expression[index], "sin", 3) == 0 ||
        strncmp(&expression[index], "cos", 3) == 0 ||
        strncmp(&expression[index], "tan", 3) == 0) {
        return 3;
    }
    else if (strncmp(&expression[index], "ln", 2) == 0){
        return 2;
    }
    else if (strncmp(&expression[index], "sqrt", 4) == 0) {
        return 4;
    }
    else if (strncmp(&expression[index], "log", 3) == 0) {
        return 5;
    }
    return 0;
}

int is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

double parse_number(char* expression, int* index) {
    double result = 0.0;
    double fraction = 1.0;
    int is_fraction = 0;

    while (expression[*index] != '\0' &&
        (isdigit(expression[*index]) || expression[*index] == '.')) {
        if (expression[*index] == '.') {
            is_fraction = 1;
        }
        else {
            if (is_fraction) {
                fraction *= 0.1;
                result += (expression[*index] - '0') * fraction;
            }
            else {
                result = result * 10 + (expression[*index] - '0');
            }
        }
        (*index)++;
    }

    return result;
}

double func_calculate(char* func, double operand) {
    if (strncmp(func, "sin", 3) == 0) {
        return sin(operand);
    }
    if (strncmp(func, "cos", 3) == 0) {
        return cos(operand);
    }
    if (strncmp(func, "tan", 3) == 0) {
        return tan(operand);
    }
    if (strncmp(func, "sqrt", 4) == 0) {
        return sqrt(operand);
    }
    if (strncmp(func, "ln", 2) == 0) {
        return log(operand);
    }
    return 0.0; // Default return value
}
double log_calculate(double x, double base) {
    return log(x) / log(base);
}
void infix_to_postfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char ch;
    char func[5];
   // stack = (double*)malloc(sizeof(double));
    //char_stack = (char*)malloc(sizeof(char));
    while ((ch = infix[i++]) != '\0') {
        if (isdigit(ch) || ch == '.') {
            postfix[j++] = ch;
        }
        else if (is_trig_function(infix, i - 1) == 3) {
            strncpy(func, &infix[i - 1], 3);
            func[3] = '\0';
            i += 2;
            char_push(func[2]);
            char_push(func[1]);
            char_push(func[0]);
            char_push(' ');
            char_push('?');

        }
        else if (is_trig_function(infix, i - 1) == 4) {
            strncpy(func, &infix[i - 1], 4);
            func[4] = '\0';
            i += 3;
            char_push(func[3]);
            char_push(func[2]);
            char_push(func[1]);
            char_push(func[0]);
            char_push(' ');
            char_push('?');
           
        }
        else if (is_operator(ch)) {
            postfix[j++] = ' ';
            while (char_top >= 0 && precedence(char_stack[char_top]) >= precedence(ch)) {
                postfix[j++] = char_pop();
                postfix[j++] = ' ';
            }

            char_push(ch);
            
        }
        else if (ch == '(') {
            char_push(ch);
        }
        else if (ch == ')') {
            while (char_top >= 0 && char_stack[char_top] != '(') {
                // postfix[j++] = ' ';
                postfix[j++] = char_pop();

            }
            if (char_top >= 0 && char_stack[char_top] == '(') {
                char_pop();
            }
            if (char_top >= 0 && char_stack[char_top] == '?') {
                char_pop();
                postfix[j++] = char_pop();
                postfix[j++] = char_pop();
                postfix[j++] = char_pop();
                postfix[j++] = char_pop();

            }

        }
        else if (isspace(ch)) {
            continue;
        }
        else {
            printf("Invalid character in expression: %c\n", ch);
            exit(EXIT_FAILURE);
        }

    }

    while (char_top >= 0) {
        //postfix[j++] = ' ';
        postfix[j++] = char_pop();

    }

    postfix[j] = '\0';
}

double evaluate_postfix(char* expression) {
    int i = 0;
    double operand1, operand2, result;
    char ch;
    char func[5];

    while (expression[i] != '\0') {
        ch = expression[i];

        if (isdigit(ch)) {
            double num = parse_number(expression, &i);
            push(num);
        }
        else if (is_trig_function(expression, i) == 3 ) {
            strncpy(func, &expression[i], 3);
            func[3] = '\0';
            operand1 = pop();
            push(func_calculate(func, operand1));
            i += 3;
        }
        else if (is_trig_function(expression, i) == 4) {
            strncpy(func, &expression[i], 4);
            func[4] = '\0';
            operand1 = pop();
            push(func_calculate(func, operand1));
            i += 4;
        }
        else if (is_operator(ch)) {
            operand2 = pop();
            operand1 = pop();

            switch (ch) {
            case '+': result = operand1 + operand2; break;
            case '-': result = operand1 - operand2; break;
            case '*': result = operand1 * operand2; break;
            case '/': result = operand1 / operand2; break;
            default:  printf("Invalid operator\n"); exit(EXIT_FAILURE);
            }

            push(result);
            i++;
        }
        else if (isspace(ch)) {
            i++;
        }
        else {
            printf("Invalid character in expression: %c\n", ch);
            exit(EXIT_FAILURE);
        }
    }
   
    return pop(); 
}

void free_stack() {
    free(char_stack);
    free(stack);
}