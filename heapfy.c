//
//  heapfy.c
//  heapSort
//
//  Created by Lucas Araujo on 11/27/15.
//  Copyright © 2015 Lucas Araujo. All rights reserved.
//

#include "heapfy.h"

void heapfyNode(int index, int (*getValueForMemberIndex)(int index), void (*switchMembersByIndex)(int indexParent,int indexSon)){
    
    if(index > 1){
        int parentIndex = (int) floor(index/2) -1;
        index--;
        
        int valueSon = getValueForMemberIndex(index);
        int valueParent = getValueForMemberIndex(parentIndex);
        
        // minor is on top!
        if(valueParent > valueSon){
            switchMembersByIndex(parentIndex, index);
            
            heapfyNode(parentIndex, getValueForMemberIndex, switchMembersByIndex);
        }
    }
    else {
        
    }
}

void heapfy(int array[], int index){
    
    if(index > 1){
        int parentIndex = (int) floor(index/2) -1;
        index--;
        
        if(array[parentIndex] < array[index]){
            int swap = array[index];
            array[index] = array[parentIndex];
            array[parentIndex] = swap;
            
            heapfy(array, parentIndex+1);
        }
    }
    else {
        
    }
}

eIndex addValueAtEnd(int array[], int value){
    
    int count = 0;
    
    if(!array[count]){
        array[0] = value;
        return 1;
    }
    
    while (array[count]) {
        
        count++;
        
        if(!array[count] && array[count-1] != value){
            array[count] = value;
            return count+1;
        }
        
    }
    
    return false;
}

boolean insertValue(int array[], int value){
    
    int index = addValueAtEnd(array, value);
    
    if(index > 0){
        heapfy(array, index);
        return true;
    }
    
    return false;
}

void printArray(int array[]){
    
    if(array[0] == 0){
        printf("array is empty\n");
    }
    
    int count = 0;
    while (array[count] != 0) {
        
        
        if(array[count+1] != 0){
            printf("%d,", array[count]);
        }
        else{
            printf("%d", array[count]);
        }
        
        count++;
    }
    printf("\n");
}

int* createArrayWithCapacity(int capacity){
    
    int *newArray = calloc(capacity, sizeof(int));
    
    if(!newArray){
        printf("can`t create array\n");
    }
    
    return newArray;
}
