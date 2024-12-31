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
        if (format == "%d") { // works!!!!
            int intArg = va_arg(args,int);
            int intArgCopy = intArg;
            int intLength = 0;
            _Bool isNegative = 0;

            if (intArg < 0) {
                isNegative = 1;
                intArg = intArg *  -1;
                intArgCopy = intArgCopy * -1;

            }


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
            if (isNegative) {
                putchar('-');
            }
            for (int i = 0; i < intLength; i++) {
                putchar(printVal[i]);
            }
            wasPercent = 0;





        }

        else if (format == "%c") {
            int charArg = va_arg(args,int);
            putchar(charArg);
        }


        else if (format == "%s")
            { // seems to work
            char * strArg = va_arg(args,char*); // gets the string

            puts(strArg); //prints out the string
        }
        else if (format == "%x") { //works


        }

        //while current character of format we are looking at isn't null, meaning that we haven't reahed the end of the format string yet
        else {
            if (*format == '%' && !(wasPercent)) { //first sign of a modifier
                wasPercent = 1;

            }

            if (wasPercent ) {

                if (*format == 'd') {

                    int intArg = va_arg(args,int);
                    int intArgCopy = intArg;
                    int intLength = 0;
                    _Bool isNegative = 0;
                    if (intArg < 0) {
                        isNegative = 1;
                        intArg = intArg *  -1;
                        intArgCopy = intArgCopy * -1;

                    }


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
                    if (isNegative) {
                        putchar('-');
                    }
                    for (int i = 0; i < intLength; i++) {
                        putchar(printVal[i]);
                    }
                    wasPercent = 0;
                }
                else if (*format == 'c') {
                    int charArg = va_arg(args,int);
                    putchar(charArg);
                    wasPercent = 0; // this format is ended, look at the next one

                }
                else if (*format == 's') {
                    char * strArg = va_arg(args,char*); // gets the string
                    puts(strArg); //prints out the string
                    wasPercent = 0;

                }
                else if (*format == 'x') {
                    int intArg = va_arg(args,int);
                    int intArgCopy = intArg;
                    int intLength = 0;
                    while (intArg!= 0) {

                        intArg = intArg / 16;
                        intLength ++;

                    }

                    char printVal [intLength];

                    for (int i = intLength - 1; i > -1; i--) {
                        int intVal =  (intArgCopy % 16);

                        char charVal;
                        switch (intVal) {
                            case 0:
                                case 1:
                            case 2 :
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                            case 7 :
                            case 8:
                            case 9:

                                charVal = intVal + '0';
                            break;

                            case 10:
                            {
                                charVal = 'A';
                                break;
                            }
                            case 11: {
                                charVal = 'B';
                                break;
                            }
                            case 12: {
                                charVal = 'C';
                                break;
                            }
                            case 13: {
                                charVal = 'D';
                                break;
                            }
                            case 14: {
                                charVal = 'E';
                                break;
                            }
                            case 15: {
                                charVal = 'F';
                                break;
                            }



                        }


                        printVal[i] = charVal;
                        intArgCopy = intArgCopy / 16;

                    }

                    for (int i = 0; i < intLength; i++)
                    {
                        putchar(printVal[i]);
                    }

                    wasPercent = 0;
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
    myprintf("%d",-123);
    myprintf("%c",'A');
    myprintf("%s","hello my naejfewwef");
    myprintf("%d",9);
    myprintf("%d",123);
    myprintf("%x",12);
    myprintf("%x", 12312);
    myprintf("%x",42);



}
