
struct hash_list {
  Fnv32_t hash;
  char datagram[512];
  struct hash_list *next;
};
struct hash_list myList[128];

void dump_all(void);
void create_hashstruct(struct hash_list *ins,char *src, char *datagram);
void insert(struct hash_list *ins);
char* search(char *needle);
