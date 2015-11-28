//
//  ArrayGeneric.h
//  Djikstra
//
//  Created by Lucas Araujo on 11/28/15.
//  Copyright © 2015 Lucas Araujo. All rights reserved.
//

#ifndef ArrayGeneric_h
#define ArrayGeneric_h

#include <stdio.h>

typedef unsigned int eIndex;
typedef unsigned int numberOfElements;

typedef enum boolean{
    false,
    true
}boolean;

//Generic
void* removeFirst(void** list);
void* removeLast(void** list);
boolean listHasElement(void** list, void* element);
numberOfElements addElement(void** list, void* element);

#endif /* ArrayGeneric_h */
