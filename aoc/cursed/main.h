#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// before functions
#define e ;
#define ee {
#define eee }
#define eeee (
#define eeeee )

// int main()
#define m int
#define mm main
#define mmm float
#define mmmm num1
#define mmmmm num2
#define mmmmmm char
#define mmmmmmm operatmon
#define mmmmmmmm &num1
#define mmmmmmmmm &num2
#define mmmmmmmmmm &operatmon
#define mmmmmmmmmmm printf
#define mmmmmmmmmmmm "%.2lf + %.2lf = %.2lf\n"
#define mmmmmmmmmmmmm "%.2lf - %.2lf = %.2lf\n"
#define mmmmmmmmmmmmmm "%.2lf * %.2lf = %.2lf\n"
#define mmmmmmmmmmmmmmm "%.2lf / %.2lf = %.2lf\n"
#define mmmmmmmmmmmmmmmm switch
#define mmmmmmmmmmmmmmmmm case
#define mmmmmmmmmmmmmmmmmm break
#define mmmmmmmmmmmmmmmmmmm '+'
#define mmmmmmmmmmmmmmmmmmmm '-'
#define mmmmmmmmmmmmmmmmmmmmm '*'
#define mmmmmmmmmmmmmmmmmmmmmm '/'
#define mmmmmmmmmmmmmmmmmmmmmmm default
#define mmmmmmmmmmmmmmmmmmmmmmmm return
#define mmmmmmmmmmmmmmmmmmmmmmmmm 0
#define mmmmmmmmmmmmmmmmmmmmmmmmmm 1
#define mmmmmmmmmmmmmmmmmmmmmmmmmmm 2

// calling the functions
#define c get_number
#define cc get_operation

// get_number()
#define n void
#define nn get_number
#define nnn float*
#define nnnn num
#define nnnnn int
#define nnnnnn iter
#define nnnnnnn const
#define nnnnnnnn char*
#define nnnnnnnnn iteration
#define nnnnnnnnnn 1
#define nnnnnnnnnnn "first"
#define nnnnnnnnnnnn "second"
#define nnnnnnnnnnnnn while
#define nnnnnnnnnnnnnn printf
#define nnnnnnnnnnnnnnn "Enter the %s number: "
#define nnnnnnnnnnnnnnnn is_float
#define nnnnnnnnnnnnnnnnn scanf
#define nnnnnnnnnnnnnnnnnn "%f"
#define nnnnnnnnnnnnnnnnnnn if
#define nnnnnnnnnnnnnnnnnnnn return
#define nnnnnnnnnnnnnnnnnnnnn else
#define nnnnnnnnnnnnnnnnnnnnnn "Error: invalid input\n"
#define nnnnnnnnnnnnnnnnnnnnnnn clear_buffer

// get_operation()
#define o void
#define oo get_operation
#define ooo char*
#define oooo operation
#define ooooo int
#define oooooo num2
#define ooooooo while
#define oooooooo 1
#define ooooooooo printf
#define oooooooooo "Enter the operation (+, -, *, /): "
#define ooooooooooo scanf
#define oooooooooooo " %c"
#define ooooooooooooo if
#define oooooooooooooo *operation == '+'
#define ooooooooooooooo *operation == '-'
#define oooooooooooooooo *operation == '*'
#define ooooooooooooooooo *operation == '/'
#define oooooooooooooooooo "Error: division by zero\n"
#define ooooooooooooooooooo clear_buffer
#define oooooooooooooooooooo else
#define ooooooooooooooooooooo return
#define oooooooooooooooooooooo "Error: invalid input\n"
#define ooooooooooooooooooooooo 0

// clear_buffer()
#define cb void
#define cbcb clear_buffer
#define cbcbcb int
#define cbcbcbcb ch
#define cbcbcbcbcb while
#define cbcbcbcbcbcb getchar
#define cbcbcbcbcbcbcb '\n'
#define cbcbcbcbcbcbcbcb EOF

#endif
