/**
Description : This is an implementation of wc command in linux, written in C
Author : Lalit D. Chandwani
Version : 1.0 , 6 December 2017
Last Modified : 11 December 2017
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  FILE * fin;
  if (argc > 1) {
    //Variables for Word Count functionality.
    char ch, prevChar;
    int w_count = 0, checkPrev = 1, index = 1;
    //Variables for Line Count functionality.
    char lch;
    int l_count = 0;
    //Variables for Character Count functionality.
    int c_count = 0;
    //Checking if specific functionality was asked.
    if (!strcmp(argv[index], "-c")) {
      //Character count
      for(index = 2; index < argc; index++){
        fin = fopen(argv[index],"r");
        if(fin == NULL){
          printf("Incorrect file path or no file path provided!\n");
          return EXIT_FAILURE;
        }
        ch = fgetc(fin);
        while(ch != EOF){
          c_count = c_count + 1;
          ch = fgetc(fin);
        }
        printf("Number of characters in %s: %d\n", argv[index], c_count);
        fclose(fin);
        return EXIT_SUCCESS;
      }
    }
    else if (!strcmp(argv[index], "-l")) {
      //Line count
      for(index = 2; index < argc; index++){
        fin = fopen(argv[index],"r");
        if(fin == NULL){
          printf("Incorrect file path or no file path provided!\n");
          return EXIT_FAILURE;
        }
        lch = fgetc(fin);
        if(lch == EOF){
          printf("Number of lines in %s: %d\n", argv[index], l_count);
          fclose(fin);
          return EXIT_SUCCESS;
        }
        else{
          l_count = l_count + 1;
        }
        while(lch != EOF){
          if(lch == '\n') {
            l_count = l_count + 1;
          }
          lch = fgetc(fin);
        }
        printf("Number of lines in %s: %d\n", argv[index], l_count);
        fclose(fin);
      }
      return EXIT_SUCCESS;
    }
    else if (!strcmp(argv[index], "-w")){
      //Word count
      for(index = 2; index < argc; index++){
        fin = fopen(argv[index],"r");
        if(fin == NULL){
          printf("Incorrect file path or no file path provided!\n");
          return EXIT_FAILURE;
        }
        ch = fgetc(fin);
        if(ch != EOF && !isspace(ch)){
          w_count = w_count + 1;
        }
        while(ch != EOF){
          prevChar = ch;
          ch = fgetc(fin);
          if(isspace(prevChar) && checkPrev != isspace(ch) && ch != EOF){
            w_count = w_count + 1;
          }
        }
        printf("Number of words in %s: %d\n", argv[index], w_count);
        fclose(fin);
      }
      return EXIT_SUCCESS;
    }
    else{
      //All functionalities (FOR LOOP WITH INDEX 1)
      for(index = 1; index < argc; index++){
        fin = fopen(argv[index],"r");
        if(fin == NULL){
          printf("Incorrect file path or no file path provided!\n");
          return EXIT_FAILURE;
        }
        //Word Count
        ch = fgetc(fin);
        if(ch != EOF && !isspace(ch)){
          w_count = w_count + 1;
        }
        while(ch != EOF){
          prevChar = ch;
          ch = fgetc(fin);
          if(isspace(prevChar) && checkPrev != isspace(ch) && ch != EOF){
            w_count = w_count + 1;
          }
        }
        printf("Number of words in %s: %d\n", argv[index], w_count);
        fclose(fin);
        //Line Count and Character Count
        fin = fopen(argv[index],"r");
        lch = fgetc(fin);
        if(lch == EOF){
          printf("Number of lines in %s: %d\n", argv[index], l_count);
          fclose(fin);
          return EXIT_SUCCESS;
        }
        else{
          l_count = l_count + 1;
        }
        while(lch != EOF){
          if(lch == '\n') {
            l_count = l_count + 1;
          }
          c_count = c_count + 1;
          lch = fgetc(fin);
        }
        printf("Number of lines in %s: %d\n", argv[index], l_count);
        printf("Number of characters in %s: %d\n", argv[index], c_count);
        fclose(fin);
      }
      return EXIT_SUCCESS;
    }
  }
  printf("Invalid arguments!\n");
  return EXIT_FAILURE;
}
