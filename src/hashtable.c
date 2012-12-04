#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "fnv.h"
#include "hashtable.h"

void dump_all( void )
{
  struct hash_list *at = myList[0].next;
  while( at != NULL ) {
      printf( "%lu => %s\n", at->hash ,at->datagram);
      at = at->next;
  }
}

char* search(char *needle) {
 Fnv32_t target_hash = fnv_32a_str(needle,0);
 struct hash_list *at = myList[0].next;
  while( at != NULL ) {
      //printf("now at:%p / val: %lu (TGT:%lu)\n",at,at->hash,target_hash);
      if (at->hash == target_hash) {
        //printf("found: %lu\n",at->hash);
        return at->datagram;
      }
      at = at->next;
  }
  return NULL;
}

void create_hashstruct(struct hash_list *ins, char *src, char *datagram) {
  Fnv32_t new_hash = fnv_32a_str(src,0);
  ins->hash = new_hash;
  strcpy(ins->datagram,datagram);
}

void insert(struct hash_list *ins) {
  struct hash_list *at = myList[0].next;
  struct hash_list *prev = &myList[0];
  while (at != NULL) {
    if (ins->hash >= at->hash) {
      ins->next = prev->next;
      prev->next = ins;
      break;
    }
    prev = at;
    at = at->next;
  }
  if (at == NULL) {
    ins->next =NULL;
    prev->next = ins;
  }
  //printf("insert at:%p (prev:%p)\n",ins,prev);
}


