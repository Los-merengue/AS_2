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

