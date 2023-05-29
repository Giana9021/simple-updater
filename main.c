#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        fputs("Usage:\n"
                      "update.exe [new file] [old file]\n"
                      "[new file] the new Version of the software\n"
                      "[old file] the software to be replaced", stderr);
        exit(-1);
    }
    char* new = argv[1];
    char* old = argv[2];

    if(!DeleteFileA(old))
        printf("1 Error: %lu\n", GetLastError());
    if(!CopyFileA(new, old, 0))
        printf("2 Error: %lu\n", GetLastError());
    if(!DeleteFileA(new))
        printf("3 Error: %lu\n", GetLastError());
}