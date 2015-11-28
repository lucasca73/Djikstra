//
//  heapfy.h
//  heapSort
//
//  Created by Lucas Araujo on 11/27/15.
//  Copyright © 2015 Lucas Araujo. All rights reserved.
//

#ifndef heapfy_h
#define heapfy_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ArrayGeneric.h"

void heapfyNode(int index, int (*getValueForMemberIndex)(int index), void (*switchMembersByIndex)(int indexParent,int indexSon));

void heapfy(int array[], int index);

eIndex addValueAtEnd(int array[], int value);

boolean insertValue(int array[], int value);

void printArray(int array[]);

int* createArrayWithCapacity(int capacity);

#endif /* heapfy_h */
