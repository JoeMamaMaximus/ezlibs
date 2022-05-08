#pragma once
#include <stdio.h>
#include <stdlib.h>
char* readFile(char* filename, int maxChars){
   char *buffer = NULL;
   int string_size, read_size;
   FILE *handler = fopen(filename, "r");

   if (handler)
   {
       fseek(handler, 0, SEEK_END);
       string_size = ftell(handler);
       rewind(handler);
       buffer = (char*) malloc(sizeof(char) * (string_size + 1) );
       read_size = fread(buffer, sizeof(char), string_size, handler);
       buffer[string_size] = '\0';

       if (string_size != read_size)
       {
           free(buffer);
           buffer = NULL;
       }
       fclose(handler);
    }

    return buffer;
}
void writeFile(char* filename, char* content){
    FILE *out=fopen(filename,"w");
	fputs(content,out);
	fclose(out);
}