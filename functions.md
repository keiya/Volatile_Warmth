# hashtable.c
    struct hash_list a;
    struct hash_list b;

    // create_hashstruct(ptr_to_hash_node,key_name,val);
    create_hashstruct(&a,"asdf","###DATAGRAM###");
    create_hashstruct(&b,"lkjh","===DATAGRAM===");
    // insert(ptr_to_hash_node)
    insert(&a);
    insert(&b);
    // restore data search(key_name)
    char *datagram = search("asdf");
    printf("%s",datagram);

