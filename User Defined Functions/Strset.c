char *STRSET(char *string, char c){
  while('\0' != *string){
    *string++ = c;
  }
  *string = '\0';
  return string;
}
