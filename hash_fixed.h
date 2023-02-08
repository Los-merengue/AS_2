/**
*
* @Name : hash.h
* This is the fixed to the vulnerable header file for c
**/

#ifndef __HASH__
#define __HASH__


#ifndef __HASH__
#define __HASH__

    typedef struct {               //Vulnerability will depend on how the 
        #define KEY_STRING_MAX 255 //function here is implemented.
		char KeyName[KEY_STRING_MAX];
		int  ValueCount;               
        struct PairValue* Next;        
	} PairValue;

	typedef struct {        //Similarly no vulnerabilities exist here but they can
        #define MAP_MAX 128 // become vulnerable depending on how the 
		PairValue* data[MAP_MAX]; //function is implemented
	} HashMap;                    

    HashMap* HashInit();
    void HashAdd(HashMap *map, PairValue *value); 
    void HashDelete(HashMap *map, const char* key); 
    void PairValue* HashFind(char *map, const char *key, size_t 255) { //Sanitize
        strncpy(key, map, 255-1); //the input of data that goes into this code block
        dest[255-1] = '\0';       //Ensuring maximum size.
    }
    void HashDump(HashMap *map);
#endif