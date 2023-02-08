#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

unsigned HashIndex(const char* key) {
    unsigned sum = 0;
    for (size_t i = 0; i < strlen(key); i++) {
        sum += (unsigned)key[i];
    }
    return sum % MAP_MAX;
}

HashMap* HashInit() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    if (!map) {
        return NULL;
    }
    memset(map->data, 0, sizeof(map->data));
    return map;
}

void HashAdd(HashMap *map,PairValue *value) {
    if (!map || !value) {
        return;
    }
    unsigned idx = HashIndex(value->KeyName);
    value->Next = map->data[idx];
    map->data[idx] = value;
}

PairValue* HashFind(HashMap *map, const char* key) {
    if (!map || !key) {
        return NULL;
    }
    unsigned idx = HashIndex(key);
    for( PairValue* val = map->data[idx]; val != NULL; val = val->Next ) {
        if (strcmp(val->KeyName, key) == 0) {
            return val;
        }
    }
    return NULL; 
}

void HashDelete(HashMap *map, const char* key) {
    if (!map || !key) {
        return;
    }
    unsigned idx = HashIndex(key);
    PairValue *prev = NULL;
    for( PairValue* val = map->data[idx]; val != NULL; prev = val, val = val->Next ) {
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
    if (!map) {
        return;
    }
    for( unsigned i = 0; i < MAP_MAX; i++ ) {
        for( PairValue* val = map->data[i]; val != NULL; val = val->Next ) {
            printf("%s\n", val->KeyName);
        }
    }
}
