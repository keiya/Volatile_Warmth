#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * kstring by Keiya Chinen
 * 1.0a
 * */

char** ksplit(char *text,char *delim) {
  char **splited_ary;
  char *chop_begin,*chop_end;
  char *offset = text;

  splited_ary = (char **)malloc(0);

  int i = 0;
  while(1) {
    chop_begin = strstr(offset,delim);
    if (chop_begin == NULL) break;
    chop_end = chop_begin + strlen(delim);

    int chop_length = chop_begin - offset;

    char *part = malloc(chop_length);
    strncpy(part,offset,chop_length);

    splited_ary[i] = (char *)malloc(sizeof(part));

    strcpy(splited_ary[i],part);

    offset = chop_end;
    ++i;
  }
    return splited_ary;
}
