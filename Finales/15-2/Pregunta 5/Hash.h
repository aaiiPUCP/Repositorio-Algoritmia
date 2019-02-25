/* 
 * File:   Hash.h
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2015, 01:28 PM
 */

#ifndef HASH_H
#define	HASH_H

#include "Lists.h"

typedef struct hash
{
    int size;
    int nElements;
    TLista* table;   
}t_hash;

void Hash_New(t_hash* hash,int size);

void Hash_addContact(t_hash* hash,TKey key,TElem num);

TElem Hash_searchContact(t_hash* hash,TKey tkey);



#endif	/* HASH_H */

