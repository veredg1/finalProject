//
// Created by gottlieb on 12/12/24.
//

#include <endian.h>
#include<stdio.h>
#include<stdarg.h>


void myprintf(const char * format, ... ) {
    va_list args;
    va_start(args,format);

    // print formatting %[flags][width][.precision][length]specifier - specifier mostly done

    _Bool wasPercent = 0; // start looking for formatters if a % is found.
    _Bool hasFlag = 0; //was there a flag
    char flag;
    _Bool haswidth = 0; //is there width thingy?
    _Bool hasPrecision = 0; //is there precision thingy?
    _Bool hasLength = 0; //is there a length modification
    _Bool isBackSlash = 0; // if it's a backslash that might need to work properly to modify certain things



    //look through the entire desired format arguments
    while (*format != '\0') {
        //while current character of format we are looking at isn't null, meaning that we haven't reahed the end of the format string yet

        if (*format == '%' && !(wasPercent)) { //first sign of a modifier
            wasPercent = 1; //looking at modifiers or specifiers

        }

        if (wasPercent) { //if we are in a formatting situation
            // flags (only want to allow one flag in this implementation)

            if (*format == '-') {
                flag = '-';
                hasFlag = 1;


            }
            if (*format == '+') {

                flag = '+';
                hasFlag = 1;

            }
            if (*format == ' ') {
                hasFlag = 1;

            }
            if (*format == '#') {
                hasFlag = 1;

            }
            if (*format == '0') {

                if (!(hasFlag && flag == '-' )) {
                    hasFlag = 1;
                    flag = '0';
                }


            }

            //width

            //length



            // the following if statements are for specifiers
            if (*format == 'd') { //if we are looking at an integer

                int intArg = va_arg(args,int); //chopped up to find integer length
                int intArgCopy = intArg; //chopped up to put into the print array properly
                int intLength = 0;
                _Bool isNegative = 0;

                if (intArg < 0) { //if it's negative, make sure we know it's negative
                    isNegative = 1;
                    intArg = intArg *  -1;
                    intArgCopy = intArgCopy * -1; //switch it to positive

                }
                if (hasFlag) { //check for flags
                    if (flag == '+' )
                        if ( !(isNegative)) { //if the flag is + and should be used

                            putchar('+'); //then add a +.
                        }
                    if (flag == ' ' && !(isNegative)) {
                        putchar(' ');

                    }
                }


                while (intArg!= 0) { //while we still have part of the integer left


                    intArg = intArg / 10; //chop it up
                    intLength ++; //figure out how long the integer is

                }
                char printVal [intLength]; //to store the print value

                for (int i = intLength - 1; i > -1; i--) { //put appropriate values in the integer printout array
                    //it's reversed so that the values are inserted from biggest to smallest

                    int intVal =  (intArgCopy % 10); //get the right integer
                    char charVal = intVal + '0'; //allows it to print out right in char form


                    printVal[i] = charVal; //put the integer in the right place in the printout
                    intArgCopy = intArgCopy / 10; //look at the next part of the integer
                }
                if (isNegative) {
                    putchar('-'); //if it's negative, add a negative sign at the beginning
                }

                for (int i = 0; i < intLength; i++) { //print out the int
                    putchar(printVal[i]);
                }
                hasFlag = 0;
                haswidth = 0;
                hasPrecision = 0;
                hasLength = 0;
                isBackSlash = 0;
                wasPercent = 0;
            }
            else if (*format == 'c') { //if it's a char
                int charArg = va_arg(args,int);
                putchar(charArg); //print out the char
                hasFlag = 0;
                haswidth = 0;
                hasPrecision = 0;
                hasLength = 0;
                isBackSlash = 0;
                wasPercent = 0;

            }

            else if (*format == 's') {//if it's a string
                char * strArg = va_arg(args,char*); // gets the string
                puts(strArg); //prints out the string
                hasFlag = 0;
                haswidth = 0;
                hasPrecision = 0;
                hasLength = 0;
                isBackSlash = 0;
                wasPercent = 0;

            }

            else if (*format == 'x') {//if it's supposeod to be printed out in hexadecimal
                int intArg = va_arg(args,int);
                int intArgCopy = intArg;

                if (intArg < 0) { //unsigned so no negative numbers
                    puts("Error: Negative Number ");
                    return;

                }

                int intLength = 0;
                //same process as with an integer except because hex is in base 16, chop off in base 16
                while (intArg!= 0) {

                    intArg = intArg / 16;
                    intLength ++;

                }

                char printVal [intLength];

                for (int i = intLength - 1; i > -1; i--) {
                    int intVal =  (intArgCopy % 16);

                    char charVal;

                    //convert decimal values 10 - 15 to appropriate hex values
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

                if (hasFlag && flag == '#') { //if this flag is used, print out 0x before the hex number
                    putchar('0');
                    putchar('x');
                }

                for (int i = 0; i < intLength; i++)
                {
                    putchar(printVal[i]); //prints out the hex number
                }

                hasFlag = 0;
                haswidth = 0;
                hasPrecision = 0;
                hasLength = 0;
                isBackSlash = 0;
                wasPercent = 0;
            }

               else if (*format == 'b') { //signed binary
                   //signed binary (last bit is 0 if positive, 1 if negative)
                   int intArg = va_arg(args,int);
                   int intArgCopy = intArg;
                   int binLength = 0;
                   _Bool isNegative = 0;
                   if (intArg < 0) { //if the number is negative, note that it is
                       isNegative = 1;
                       intArg = intArg *  -1;
                       intArgCopy = intArgCopy * -1;
                   }


                   //again use a similar process to that of an integer, except do the work in base 2, not base 10
                   while (intArg!= 0) {


                       intArg = intArg / 2;
                       binLength ++;

                   }
                   char printVal [binLength];

                   for (int i = binLength - 1; i > -1; i--) {

                       int intVal =  (intArgCopy % 2);
                       char charVal = intVal + '0';


                       printVal[i] = charVal;
                       intArgCopy = intArgCopy / 2;
                   }
                   if (isNegative) {


                       putchar('1'); //leading number is 1
                   }
                   else { //if it's positive
                       putchar('0'); //leading number is 0
                   }

                   for (int i = 0; i < binLength; i++) {
                       putchar(printVal[i]);
                   }



                   hasFlag = 0;
                   haswidth = 0;
                   hasPrecision = 0;
                   hasLength = 0;
                   isBackSlash = 0;
                   wasPercent = 0;
               }
            else if (*format != 'q') //array of ints
            {
                int * intArg = va_arg(args,int *);

                //printf("%d",*intArg);
                // while (*intArg != '\0'){
                //    int intArgCopy = *intArg;
                //     int intLength = 0;
                //     _Bool isNegative = 0;
                //
                //     if (*intArg < 0) { //if it's negative, make sure we know it's negative
                //         isNegative = 1;
                //         *intArg = *intArg *  -1;
                //         intArgCopy = intArgCopy * -1; //switch it to positive
                //
                //     }
                //     if (hasFlag) { //check for flags
                //         if (flag == '+' )
                //             if ( !(isNegative)) { //if the flag is + and should be used
                //
                //                 putchar('+'); //then add a +.
                //             }
                //         if (flag == ' ' && !(isNegative)) {
                //             putchar(' ');
                //
                //         }
                //     }
                //
                //
                //     while (*intArg!= 0) { //while we still have part of the integer left
                //
                //
                //         *intArg = *intArg / 10; //chop it up
                //         intLength ++; //figure out how long the integer is
                //
                //     }
                //     char printVal [intLength]; //to store the print value
                //
                //     for (int i = intLength - 1; i > -1; i--) { //put appropriate values in the integer printout array
                //         //it's reversed so that the values are inserted from biggest to smallest
                //
                //         int intVal =  (intArgCopy % 10); //get the right integer
                //         char charVal = intVal + '0'; //allows it to print out right in char form
                //
                //
                //         printVal[i] = charVal; //put the integer in the right place in the printout
                //         intArgCopy = intArgCopy / 10; //look at the next part of the integer
                //     }
                //     if (isNegative) {
                //         putchar('-'); //if it's negative, add a negative sign at the beginning
                //     }
                //
                //     for (int i = 0; i < intLength; i++) { //print out the int
                //         putchar(printVal[i]);
                //     }
                //
                //     *intArg ++;
                // }

            }
        }



        else { //deals with characters that aren't covered by a formatter because they aren't format but should still be printed out
                putchar(*format);

            }


            ++format;
        }


        va_end(args);
    }




 



