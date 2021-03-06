#ifndef TASK_HASHTAB_H
#define TASK_HASHTAB_H

#include <stdlib.h>
#include <string.h>

#define HASHTAB_SIZE 200000
#define HASHTAB_MUL 31

struct listnode {
    char key[32];
    int value;
    struct listnode* next;
};

int hashtab_hash(char *key);

void hashtab_init(struct listnode** hashtab);

void hashtab_add(struct listnode** hashtab, char* key, int value);

struct listnode* hashtab_lookup(struct listnode** hashtab, char* key);

void hashtab_delete(struct listnode** hashtab, char* key);

#endif
