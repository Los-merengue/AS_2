/**
*
* @Name : hash.c
*
**/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

/**
 The below HashIndex function has been implemented improperly.
 It is just summing the ASCII characters in the keys within
 the function, this can lead to hash collision affect the 
 integrity and availability of the code.

 **/
unsigned HashIndex(const char* key) {
    unsigned sum = 0;
    for (char* c = key; c; c++){
        sum += *c;
    }
    
    return sum;
}

/**
 * Potential memory leaks can occur in this Hashinit function
 * since the function dynamically allocate pointers. This vulnrability
 * can lead to breach in data Integrity according to CIA triad.
 * This function is not initialized and this can result to access of
 * uninitialized memory
*/
/*
This HahInit function also comes with a potential data corruption flaw,
since it carries an unintialized malloc function. This would affect
data integrity.
*/
HashMap* HashInit() {               
	return malloc(sizeof(HashMap));   
}

/**
 * There is lack of error handling in this HashAdd function, this is
 * not so good of a coding practice because this can result to faulty 
 * confidentiality within the software that is been built.
 * 
*/

void HashAdd(HashMap *map,PairValue *value) {
    unsigned idx = HashIndex(value->KeyName);
    
    if (map->data[idx]) 
        value->Next = map->data[idx]->Next;
    map->data[idx] = value;	
}

/**
 * The HashFind Function given below also have a security problem.
 * This problem is as a result of using the 'strcpy' function in
 * the code. This has a tendency to result to a buffer overflow, which
 * can affect both confidentiality, integrity and availability.
 * 
 * **/

PairValue* HashFind(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key);
    
    for( PairValue* val = map->data[idx]; val != NULL; val = val->Next ) {
        if (strcpy(val->KeyName, key))
            return val;
    }
    
    return NULL; 
}

/**
 * The HashDelete function below also carries it vulnerability. From
 * what we can see, within the 'for loop' there is a data handling.
 * This loop does not handle the first element of the list well which
 * can result to memory leaks. Memory leaks is usually will affect
 * the integrity of the CIA triad. This is because in the cause of 
 * data storage, some part of the data can be lost. 
 * The function also carries the 'strcpy' function instead of the
 * 'strcmp' function which can result to buffer overflow 
 * 
**/

void HashDelete(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key);
    
    for( PairValue* val = map->data[idx], *prev = NULL; val != NULL; prev = val, val = val->Next ) {
        if (strcpy(val->KeyName, key)) {
            if (prev)
                prev->Next = val->Next;
            else
                map->data[idx] = val->Next;
        }
    }
}

/**
 * Looking at the HashDump function below, a printf prompt will be used
 * to output some set of strings, and the amount of data this string
 * can output is not stated. This has the potential of causing buffer
 * overflow, which can also affect configentiality, availability and
 * Intergrity.
*/

void HashDump(HashMap *map) {
    for( unsigned i = 0; i < MAP_MAX; i++ ) {
        for( PairValue* val = map->data[i]; val != NULL; val = val->Next ) {
            printf(val->KeyName);
        }
    }
}
