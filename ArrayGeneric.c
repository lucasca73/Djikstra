//
//  ArrayGeneric.c
//  Djikstra
//
//  Created by Lucas Araujo on 11/28/15.
//  Copyright © 2015 Lucas Araujo. All rights reserved.
//

#include "ArrayGeneric.h"

void* removeFirst(void** list){
    
    if(!list[0]){
        return NULL;
    }
    
    void* firstElement = *list;
    
    int count = 0;
    
    do {
        if(list[count+1])
            list[count] = list[count+1];
        else
            list[count] = NULL;
        
        count++;
    } while (list[count]);
    
    return firstElement;
}

void* removeLast(void** list){
    
    if(!list[0]){
        return NULL;
    }
    
    int count = 0;
    
    do {
        if(list[count+2])
            list[count] = list[count+1];
        else{
            void* last = list[count+1];
            list[count+1] = NULL;
            
            return last;
        }
        
        count++;
    } while (list[count]);
    
    return NULL;
}

boolean listHasElement(void** list, void* element){
    
    if(!list[0]){
        return false;
    }
    
    int count = 0;
    
    do {
        if(list[count] == element)
            return true;
        
        count++;
    } while (list[count]);
    
    return false;
}


//Number of elements
numberOfElements addElement(void** list, void* element){
    
    numberOfElements count = 0;

    do{
        
        if(!list[count]){
            list[count] = element;
            return count+1;
        }
        count++;
        
    }while(list[count-1]);
    
    return false;
}