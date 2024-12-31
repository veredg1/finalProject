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

    //if (format == "%d") { // works if the integer is less than 10
       // int intArg = va_arg(args,int);
        // char printval = intArg + '0';
        //putchar(printval);


    //}

     if (format == "%c") {
         int charArg = va_arg(args,int);
         putchar(charArg);
     }
    // else if (format == "%d") { //survey says I hate ints
    //     int intArg = va_arg(args,int);
    //
    //     char  printval[] = ;
    //
    //
    //     puts(printval);
    //     }
         // some research shows that apparently this is how you can convert a character to an int


    else if (format == "%s") { // seems to work
        char * strArg = va_arg(args,char*); // gets the string

        puts(strArg); //prints out the string
    }
    else if (format == "%x") {

    }
    //need to implement my own stuff. arrays, binary
     else {
        while (*format != '\0') {
            //while current character of format we are looking at isn't null, meaning that we haven't reahed the end of the format string yet


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

            // check modifiers and if the last thing was a format.
            ++format;


        }
    }

    va_end(args);



    }

 



int main(void) {
   // myprintf("%d %d",50,33);
    myprintf("%c",'A');
    myprintf("%s","hello my naejfewwef");


}
