#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "kstring.h"

/*
 * kstring by Keiya Chinen
 * 1.0a
 * */

t_split* ksplit(char *text,char *delim) {
  char **splited_ary;
  t_split *result;
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

    splited_ary[i] = (char *)malloc(strlen(part));

    strcpy(splited_ary[i],part);

    offset = chop_end;
    ++i;
  }
  result = (t_split *)malloc(sizeof(t_split *));
  result->splited_ary = splited_ary;
  result->count = i;
  return result;
}
