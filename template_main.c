#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define check_digit(a) do { if (!isdigit(a)) {fprintf(stderr, "Input entered is not a digit!");return 1;}} while (0)

char* math(char n1d1, char n1d2, char op, char n2d1, char n2d2);

void flush() {
    while (getc(stdin) != '\n');
}

int main() {
    char n1d1[2];
    char n1d2[2];
    char op[2];
    char n2d1[2];
    char n2d2[2];

    // Get the first digit for the first number
    printf("Enter a digit: ");

    fgets(n1d1, 2, stdin);
    check_digit(n1d1[0]);
    flush();

    // Get the second digit for the first number
    printf("Enter the second digit: ");
    fgets(n1d2, 2, stdin);
    check_digit(n1d2[0]);
    flush();

    printf("You have entered the number %c%c!\n", n1d1[0], n1d2[0]);

    // Get the desired operation
    printf("Enter your desired operation (+ - x /): ");
    fgets(op, 2, stdin);

    if (!(op[0] == 'x' || op[0] == '/' || op[0] == '+' || op[0] == '-'))
    {
        fprintf(stderr, "That's not a valid operation character!"); 
    }
    flush();

    // Get the first digit for the second number
    printf("Enter a digit: ");

    fgets(n2d1, 2, stdin);
    check_digit(n2d1[0]);
    flush();

    // Get the second digit for the second number
    printf("Enter the second digit: ");
    fgets(n2d2, 2, stdin);
    check_digit(n2d2[0]);
    flush();

    printf("You have entered the number %c%c!\n", n2d1[0], n2d2[0]);

    printf("Proceeding with the operation %c%c %c %c%c\n", n1d1[0], n1d2[0], op[0], n2d1[0], n2d2[0]);

    char* result = math(n1d1[0], n1d2[0], op[0], n2d1[0], n2d2[0]);

    printf("The result is %s!", result);

    free(result);
    return 0;
}

char* math(char n1d1, char n1d2, char op, char n2d1, char n2d2) {
    // Protect against buffer overflow attacks.
    char* result = malloc(INT_MAX);
    memset(result, 0, INT_MAX);

    {!!}

    return result;
}