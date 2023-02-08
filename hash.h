/**
*
* @Name : hash.h
* This is a header file for the hash.c file, it contains some macro
* definition of the functions in the c program.
**/

#ifndef __HASH__
#define __HASH__

    typedef struct {
        #define KEY_STRING_MAX 255
		char KeyName[KEY_STRING_MAX];  //unsanitize KeyName data can lead to injections, and the
		int  ValueCount;               //possibility that it could lead to buffer overflow, causing
        struct PairValue* Next;        //unavalability of data.
	} PairValue;

	typedef struct {
        #define MAP_MAX 128
		PairValue* data[MAP_MAX]; //unsanitize data type and lack of input validation can lead 
	} HashMap;                    //to injection, affecting confidentaility, integrity and availability

    HashMap* HashInit();
    void HashAdd(HashMap *map, PairValue *value); // lack of Error handling, affecting confidentiality
    void HashDelete(HashMap *map, const char* key); // Inappropriate Data handling, leading to memory leaks and affecting integrity
    PairValue* HashFind(HashMap *map, const char* key); //Potential buffer overflow
    void HashDump(HashMap *map);
#endif