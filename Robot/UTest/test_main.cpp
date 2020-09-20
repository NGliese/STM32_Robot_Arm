
#include "CppUTest/CommandLineTestRunner.h"

#include "CppUTest/TestHarness.h"



int main(int argc, char **argv) {

#if 0
    char *arg[10];
    arg[1] = "-v";
   // arg[2] = "-sg";
    return CommandLineTestRunner::RunAllTests(2, arg);
#else
    return CommandLineTestRunner::RunAllTests(argc, argv);
#endif

}

