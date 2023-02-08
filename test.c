#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

unsigned HashIndex(const char* key) {
    unsigned sum = 0;
    size_t len = strlen(key);
    for (size_t i = 0; i < len; i++) {
        sum += key[i];
    }
    return sum;
}

HashMap* HashInit() {
    HashMap *map = malloc(sizeof(HashMap));
    if (map == NULL) {
        perror("malloc");
        return NULL;
    }
    memset(map->data, 0, sizeof(map->data));
    return map;
}

void HashAdd(HashMap *map, PairValue *value) {
    unsigned idx = HashIndex(value->KeyName) % MAP_MAX;

    value->Next = map->data[idx];
    map->data[idx] = value;	
}

PairValue* HashFind(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key) % MAP_MAX;
    
    for (PairValue *val = map->data[idx]; val != NULL; val = val->Next) {
        if (strcmp(val->KeyName, key) == 0)
            return val;
    }
    
    return NULL; 
}

void HashDelete(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key) % MAP_MAX;
    
    for (PairValue *val = map->data[idx], *prev = NULL; val != NULL; prev = val, val = val->Next) {
        if (strcmp(val->KeyName, key) == 0) {
            if (prev) {
                prev->Next = val->Next;
            } else {
                map->data[idx] = val->Next;
            }
            free(val);
            break;
        }
    }
}

void HashDump(HashMap *map) {
    for (unsigned i = 0; i < MAP_MAX; i++) {
        for (PairValue *val = map->data[i]; val != NULL; val = val->Next) {
            printf("%s\n", val->KeyName);
        }
    }
}
