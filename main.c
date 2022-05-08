#include "ezfiles.h"
int main(int argc, char const *argv[])
{
    char *readed = readFile("main.c", 100);
    printf("%s\n", readed);
    writeFile("repl.c", readed);
    return 0;
}
