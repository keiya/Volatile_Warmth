typedef struct {
  char port[7];
} s_options;

#ifndef EXTERN_CORE
#define EXTERN_CORE

extern void* sock_boot(void *v_options);

extern char received_data_queue[128][512];
extern int received_data_queue_head,received_data_queue_tail;

extern char send_data_queue[128][512];
extern int send_data_queue_head,send_data_queue_tail;

#endif

#define MAX_RECEIVE_QUEUE 64
#define MAX_SEND_QUEUE 64
