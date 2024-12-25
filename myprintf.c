//
// Created by gottlieb on 12/12/24.
//

#include<stdio.h>
#include<stdarg.h>
#include <string.h>

void myprintf(const char * format, ... ) {
    va_list args;
    va_start(args,format);


    while (*format != '\0') {

        if (*format == 'd') {
            int intArg = va_arg(args,int);
            putc_unlocked((int)intArg,stdout);




           

        }
        else if (*format == 'c') {
            int charArg = va_arg(args,int);
            putchar(charArg);



        }
        ++format;

    }

    va_end(args);


    }

 



int main(void) {
    myprintf("%d %d",50,33);
}
