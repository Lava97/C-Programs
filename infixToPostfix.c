/**
Description : Infix to Postfix converter
Author : Lalit D. Chandwani
Version : 1.0 , 24 October 2017
*/
#include<stdio.h>
#include <stdlib.h>
char stack[50];
int top = -1;

//Function to push characters to Stack.
void push(char x){
  stack[++top] = x;
}

//Function to pop characters out of the Stack.
char pop(){
  if(top == -1){
    return -1;
  }
  else{
    return stack[top--];
  }
}

//Function to check priority of "special characters".
int priority(char x){
  if(x == '('){
    return 0;
  }
  if(x == '+' || x == '-'){
    return 1;
  }
  if(x == '*' || x == '/'){
    return 2;
  }
}

int main(){
  char expression[50];
  char *expPtr, character;
  printf("Enter the expression: ");
  scanf("%s", expression);
  expPtr = expression;
  //Running loop from start of expression till end of expression.
  while(*expPtr != '\0'){
    //Checking if character is number or alphabet.
    if(isalnum(*expPtr)){
      printf("%c",*expPtr);
    }
    else if(*expPtr == '('){
      push(*expPtr);
    }
    else if(*expPtr == ')')        {
      while((character = pop()) != '('){
        printf("%c", character);
      }
    }
    else{
      while(priority(stack[top]) >= priority(*expPtr)){
        printf("%c",pop());
      }
      push(*expPtr);
    }
    expPtr++;
  }
  //Pop everything out of stack till stack is empty.
  while(top != -1){
    printf("%c",pop());
  }
  //Printing new line.
  printf("\n");
  //Terminating program successfully.
  return EXIT_SUCCESS;
}
