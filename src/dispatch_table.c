/**
 * @file dispatch_table.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void function1(){
    printf("function1\n");
}

void function2(int input){
    printf("function2, %d\n", input);
}

void function3a(int input1, int input2){
    printf("function3, %d, %d\n", input1, input2);
}

void function3b(int input1, int input2){
    printf("function3b, %d, %d, %d\n", input1, input2, input1 + input2);
}

void function4(double input1, int input2, int input3){
    printf("function4, %f, %d, %c\n", input1, input2, (char)input3);
}

int useFunction(int Select, int numArgs, ...){
    // Var args prep
    va_list vList;
    va_start(vList, numArgs);

    // Function Pointers Creation
    typedef void (*Function1Pointer)();
    Function1Pointer func1p = &function1;
    
    typedef void (*Function2Pointer)(int a);
    Function2Pointer func2p = &function2;

    typedef void (*Function3Pointer)(int a, int b);

    Function3Pointer func3Table[] =
    {
        function3a,
        function3b
    };

    typedef void (*Function4Pointer)(double a, int b, int c);
    Function4Pointer func4p = &function4;

    // Find what function we want and call it.
    switch(Select){
        case 0:
            func1p();
            break;
        case 1:
            func2p(va_arg(vList, int));
            break;
        case 2:
            func3Table[0](va_arg(vList, int), va_arg(vList, int));
            break;
        case 3:
            func3Table[1](va_arg(vList, int), va_arg(vList, int));
            break;
        case 4:
            func4p(va_arg(vList, double), va_arg(vList, int), va_arg(vList, int));
            break;
        default:

            break;
    }

    return 1;
}

int main(){
    printf("MAIN: Normal function calls.\n");
    function1();
    function2(0);
    function3a(1, 2);
    function3b(3, 4);
    function4(4.2, 5, 'c');

    printf("\nMAIN: Lookup function calls.\n");
    useFunction(0, 0);
    useFunction(1, 1, 0);
    useFunction(2, 2, 1, 2);
    useFunction(3, 2, 3, 4);
    useFunction(4, 3, 4.2, 5, 'c');
}