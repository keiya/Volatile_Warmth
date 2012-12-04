typedef struct {
  char **splited_ary;
  int count;
} t_split;

t_split* ksplit(char *text,char *delim);
