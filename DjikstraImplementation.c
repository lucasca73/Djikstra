//
//  DjikstraImplementation.c
//  Djikstra
//
//  Created by Lucas Araujo on 11/27/15.
//  Copyright © 2015 Lucas Araujo. All rights reserved.
//

#include "DjikstraImplementation.h"

boolean isInsideOfMist(mist nodeMist, graphNode node){
    
    int count = 0;
    while (nodeMist[count]) {
        
        if(nodeMist[count] == node){
            return true;
        }
    }
    
    return false;
}


// return the number of arestas that have been added
eIndex addNodeToMist(mist nodeMist, graphNode node, listOfArestas list, int pathValue){
    int count = 0;
    
    if(!listHasElement(nodeMist, node)){
        
        // add to the mist
        addElement(nodeMist, node);
        
        eIndex leavingArestas = 0;
        aresta nodeAresta;
        
        int count = 0;
        
        // all arestas from node
        do{
            nodeAresta = node->listOfArestas[leavingArestas];
            
            if(nodeAresta){
                nodeAresta->value += pathValue;
            }
            
            if(!arestaWithSameDestinyAndSmallerValue(list, nodeAresta)){

                if(!addAresta(list, nodeAresta)){
                    break;
                }
                else{
                    
                    count++;
                }
            }
            
            leavingArestas++;
            
        }while (nodeAresta);
        
        return count;
    }

        
    return false;
}

eIndex addPath(path list, aresta newAresta){
    
    eIndex count = 0;
    
    if(!list[count]){
        list[0] = newAresta;
        return count;
    }
    
    while (list[count]) {
        
        count++;
        
        if(!list[count] && list[count-1] != newAresta){
            list[count] = newAresta;
            return count;
        }
    }
    
    return false;
}

path minorPath(path list){
    
    if(!list[0]){
        return NULL;
    }
    
    aresta firstAresta = list[0];
    aresta lastAresta;
    eIndex count = 0;
    
    while (list[count]) {
        if(!list[count+1]){
            lastAresta = list[count];
            break;
        }
        count++;
    }
    
    path minorPath = calloc(20, sizeof(backAresta));
    
    do {
        graphNode origin = lastAresta->origin;
        addAresta(minorPath, lastAresta);
        
        count = 0;
        
        while (list[count]) {
            if(list[count]->destiny == origin){
                lastAresta = list[count];
                break;
            }
            count++;
        }
        
        if(origin == firstAresta->origin){
            break;
        }
        
    }while(1);
    
    return minorPath;
}

eIndex add(void** list, void* newElement){
    
    eIndex count = 0;
    
    if(!list[count]){
        list[0] = newElement;
        return count;
    }
    
    while (list[count]) {
        
        count++;
        
        if(!list[count] && list[count-1] != newElement){
            list[count] = newElement;
            return count+1;
        }
        
    }
    
    return false;
}



eIndex addAresta(listOfArestas list, aresta newAresta){
    
    if(!newAresta){
        return false;
    }
    
    eIndex count = 0;
        
    if(!listHasElement(list, newAresta)){
    
        return addElement(list, newAresta);
    }

    return false;
}

boolean arestaWithSameDestinyAndSmallerValue(listOfArestas list, aresta arestaInProof){
    
    if(!list[0]){
        return false;
    }
    
    if(arestaInProof && list){
        
        int count = 0;
        
        do {
            
            //if arestas aren`t the same
            if(list[count] != arestaInProof){
                
                //if destinys are the same
                if(list[count]->destiny == arestaInProof->destiny){
                    
                    //and value is smaller
                    if(list[count]->value >= arestaInProof->value){
                        //return the index that is bigger
                        list[count] = arestaInProof;
                        return true;
                    }
                }
            }
            
            count++;
        }while((list[count]));
    }
    
    return false;
}



graphNode createNewNodeWithId(int id){
    
    graphNode newNode = malloc(sizeof(struct graphNode));
    newNode->listOfArestas = calloc(10, sizeof(aresta));
    newNode->id = id;
    
    return newNode;
}

mist createNewMist(){
    
    mist newMist = calloc(40,(sizeof(struct graphNode)));
    
    return newMist;
}

boolean setArestaOnNodes(graphNode origin, graphNode destiny, int value){
    
    if(!origin || !destiny || value <= 0){
        printf("invalid args\n");
        return false;
    }
    
    aresta new = createNewAresta(value);
    
    new->origin = origin;
    new->destiny = destiny;
    addAresta(origin->listOfArestas, new);
    
    if (new) {
        return true;
    }
    
    return false;
}

aresta createNewAresta(int value){
    
    aresta new = malloc(sizeof(backAresta));
    new->value = value;
    new->destiny = NULL;
    new->origin = NULL;
    
    return new;
}

void showDjikstraPath(path list){
    
    int count = 0;
    
    while (list[count]) {
        
        printf("%d->%d:%d\n", list[count]->origin->id, list[count]->destiny->id, list[count]->value);
        
        count++;
    }
    
}

void showMist(mist mancha){
    
    int count = 0;
    
    while (mancha[count]) {
        
        if(mancha[count]){
            printf("%d->", mancha[count]->id);
        }
        else {
            printf("%d", mancha[count]->id);
        }
        
        count++;
    }
    
}

