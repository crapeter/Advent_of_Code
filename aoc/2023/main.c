#include <stdio.h>

void get_number(float *, int);
void get_operation(char *, int);
void clear_buffer();
float exponent(float, float);

int main(int argc, char **argv) {
  float num1, num2, exp;
  char operation;

  get_number(&num1, 1);
  get_number(&num2, 2);
  get_operation(&operation, num2);

  switch (operation) {
    case '+':
      printf("%.3lf + %.3lf = %.3lf\n", num1, num2, num1 + num2);
      break;
    case '-':
      printf("%.3lf - %.3lf = %.3lf\n", num1, num2, num1 - num2);
      break;
    case '*':
      printf("%.3lf * %.3lf = %.3lf\n", num1, num2, num1 * num2);
      break;
    case '/':
      printf("%.3lf / %.3lf = %.3lf\n", num1, num2, num1 / num2);
      break;
    case '^':
      exp = exponent(num1, num2);
      printf("%.3lf ^  %.3lf = %.3lf", num1, num2, exp);
      break;
    default:
      break;
  }
  return 0;
}

void get_number(float *num, int iter) {
  const char* iteration = (iter == 1) ? "first" : "second";
  while (1) {
    printf("Enter the %s number: ", iteration);
    int is_float = scanf("%f", num);
    if (is_float) return;
    else {
      printf("Error: invalid input.\n");
      clear_buffer();
    }
  }
}

void get_operation(char *operation, int num2) {
  while (1) {
    printf("Enter the operation (+, -, *, /, ^): ");
    scanf(" %c", operation);
    if (*operation == '+' || *operation == '-' || *operation == '*' || *operation == '/' || *operation == '^') {
      if (num2 == 0 && *operation == '/') {
        printf("Error: division by zero.\n");
        clear_buffer();
      } else {
        return;
      }
    } else {
      printf("Error: invalid operation.\n");
      clear_buffer();
    }
  }
}

float exponent(float num, float exp) {
 int was_negative = 0;
  if (exp < 0) {
    exp -= 2 * exp;
    was_negative = 1;
  } 
  if (exp == 0) {
    return 0;
  } else if (exp == 1) {
    return num;
  } else {
    if (was_negative) {
      return 1/(num * exponent(num, exp - 1));
    }
    return num * exponent(num, exp - 1);
  }
}

void clear_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
