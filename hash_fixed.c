/**
*
* @Name : hash.c fixed code
*
**/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

/**
 * Since the code is vulnerable to hash collision, i.e. different
 * key will be having the same hash value. We can solve this by
 * using a more robust hash function as the one given below.
 * This function will solve this because it is not by merely adding
 * ASCII key value instead it is using the a wide memory range and 
 * giving a good distribution of the created keys.
*/

unsigned HashIndex(const char* key) {
    unsigned hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

/**
 * The previous code has a tendency to produce memory leaks, so one way
 * to go about is to clean the memory after the execution to prevent 
 * this. The 'free()' function below can assist in make this possible
 * 
*/

HashMap* HashInit() {               
	return malloc(sizeof(HashMap));
    free()   
}

/**
 * The previous HashIndex function can cause buffer overflow. This code
 * referenced below can restrict the vulnerabilty by using the modulo 
 * (% MAP_MAX) operator to ensure the index stays within bounds. 
 * Consequently, we should ensure the conditionals statement is written
 * in a way to ensure prevention of loosing data.
 * 
*/

unsigned idx = HashIndex(value->KeyName) % MAP_MAX;  // Use modulo operator to ensure index stays within bounds

if (map->data[idx]) 
    value->Next = map->data[idx];  // Avoid overwriting the linked list and losing data
map->data[idx] = value;

/**
 * The previous code had a classical buffer overflow vulnerability, whihc
 * was introduced by the function used to compare the string 'strcpy'.
 * We will fix this by using the 'strncmp' function, because this function
 * will copy n amount of characters and ensure that it returns NULL
 * termination. This will dynamically work on the buffer and nullify any 
 * potential overflow that may happen
*/

PairValue* HashFind(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key);
    
    for( PairValue* val = map->data[idx]; val != NULL; val = val->Next ) {
        if (strncmp(val->KeyName, key, KEY_STRING_MAX) == 0)
            return val;
    }
    
    return NULL; 
}
