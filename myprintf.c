//
// Created by gottlieb on 12/12/24.
//

#include<stdio.h>
#include<stdarg.h>



void myprintf(const char * format, ... ) {
    va_list args;
    va_start(args,format);

    // print formatting %[flags][width][.precision][length]specifier


    _Bool wasPercent = 0; // start looking for formatters if a % is found.
    _Bool wasFormat = 0; //figure out if the last thing was a formatter
    _Bool isBackSlash = 0; // if it's a backslash that might need to work properly to modify certain things


    //need to implement my own stuff. arrays, binary

    while (*format != '\0') {
        if (format == "%d") { // works if the integer is less than 10
            int intArg = va_arg(args,int);
            int intArgCopy = intArg;
            int intLength = 0;
            while (intArg!= 0) {

               intArg = intArg / 10;
                intLength ++;

            }
            char printVal [intLength];
            for (int i = intLength - 1; i > -1; i--) {
                int intVal =  (intArgCopy % 10);
                char charVal = intVal + '0';

                printVal[i] = charVal;
                intArgCopy = intArgCopy / 10;
            }
            for (int i = 0; i < intLength; i++) {
                putchar(printVal[i]);
            }









        }

        else if (format == "%c") {
            int charArg = va_arg(args,int);
            putchar(charArg);
        }


        else if (format == "%s") { // seems to work
            char * strArg = va_arg(args,char*); // gets the string

            puts(strArg); //prints out the string
        }
        else if (format == "%x") {

        }

        //while current character of format we are looking at isn't null, meaning that we haven't reahed the end of the format string yet
        else {
            if (*format == '%' && !(wasPercent)) { //first sign of a modifier
                wasPercent = 1;

            }

            if (wasPercent ) {
                //


                if (*format == 'd') {
                    int intArg = va_arg(args,int);
                    //putchar(intArg); // this isn't working. supposed to take the argument associated with this format
                    wasPercent = 0; //this format is ended

                }
                else if (*format == 'c') {
                    int charArg = va_arg(args,int);
                    putchar(charArg); // this is good
                    wasPercent = 0; // this format is ended, look at the next one

                }
                else if (*format == 's') {
                    int strArg = va_arg(args,int);

                }
            }
        }
        // check modifiers and if the last thing was a format.
        ++format;
    }


    va_end(args);
}


 



int main(void) {
   myprintf("%d %d",50,33);
    myprintf("%c",'A');
    myprintf("%s","hello my naejfewwef");
    myprintf("%d",9);
    myprintf("%d",123);



}
