//
// Created by gottlieb on 12/12/24.
//

#include<stdio.h>
#include<stdarg.h>
#include <string.h>

void myprintf(const char * format, ... ) {
    va_list args;
    va_start(args,format);

    _Bool wasPercent = 0; // start looking for formatters if a % is found.
    _Bool wasFormat = 0; //figure out if the last thing was a formatter
    _Bool isBackSlash = 0; // if it's a backslash that might need to work properly to modify certain things
    

    while (*format != '\0') {

        printf("%c\n",*format);


        if (*format == '%' && !(wasPercent)) { //first sign of a modifier
            wasPercent = 1;
        }
        if (*format == 'd' && wasPercent) { // then check for later modifiers
            int intArg = va_arg(args,int);
            putchar(intArg);
            wasFormat = 1;
            wasPercent = 0;

        }
        else if (*format == 'c' && wasPercent) { // then check for existing modifiers
            int charArg = va_arg(args,int);
            putchar(charArg);
            wasFormat = 1;
            wasPercent = 0;


        }
        // check modifiers and if the last thing was a format.
        ++format;

    }

    va_end(args);


    }

 



int main(void) {
    myprintf("%d %d",50,33);
}
