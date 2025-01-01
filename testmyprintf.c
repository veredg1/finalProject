#include <stdio.h>
#include "myprintf.c"




int main(void) {
    // try empty for each type
    //test int (need for negatives, 0-9, greater than 10, greater than 100 (maybe greater than 1000, or bigger than that even?)
    //test char (a bunch of different char tests)
    //test string (big and small strings)
    //test hex
    // test my own implemented ones
    // try tests that use the wrong type in the myprint

    //int tests
    myprintf("%d %d\n",50,33); //also tests ability to use multiple %s in one thing
    myprintf("%d\n",-123);
    myprintf("%d\n",9);
    myprintf("%d\n",123);
    myprintf("%0-d",123);

    //char tests
    myprintf("%c\n",'A');
    myprintf("%c\n",55);

    //string tests
    myprintf("%s\n","hello my naejfewwef");

    //hexidecimal tests
    myprintf("%x\n",12);
    myprintf("%x \n", 12312);
    myprintf("%x\n",42);
    myprintf("%x negative hex\n",-21);

    //signed magnitude binary tests
    myprintf("%b\n",-32);
    myprintf("%b\n",-4);
    myprintf("%b\n",32);

    //multiple types in one print
    myprintf("char %c int %d\n",'A',32834);

    int test[4];
    test[0] = 1;
    test[1] = 123;
    test[2] = 12341;
    test[3] = 23;
    myprintf("%q",test);



}
