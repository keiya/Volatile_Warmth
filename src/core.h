typedef struct {
  char port[7];
} s_options;

#ifndef EXTERN_CORE
#define EXTERN_CORE

//extern int i;
//extern void test();

extern void* sock_boot(void *v_options);

#endif


