int STRLEN(char* str){
  int length = 0;
  int index;
  for(index=0;str[index]!='\0';index++){
    length = length + 1;
  }
  return length;
}
