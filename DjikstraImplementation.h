//
//  DjikstraImplementation.h
//  Djikstra
//
//  Created by Lucas Araujo on 11/27/15.
//  Copyright © 2015 Lucas Araujo. All rights reserved.
//

#ifndef DjikstraImplementation_h
#define DjikstraImplementation_h

#include <stdio.h>
#include "heapfy.h"

typedef struct graphNode{
    int id;
    struct aresta **listOfArestas;
    
}*graphNode;

typedef struct aresta{
    graphNode origin;
    graphNode destiny;
    int value;
    
}backAresta;

typedef backAresta *aresta;

typedef graphNode* mist;

typedef aresta* path;
typedef path listOfArestas;

mist createNewMist();

boolean isInsideOfMist(mist nodeMist, graphNode node);

eIndex addNodeToMist(mist nodeMist, graphNode node, listOfArestas list, int pathValue);

boolean setArestaOnNodes(graphNode origin, graphNode destiny, int value);

eIndex add(void** list, void* newElement);

aresta createNewAresta(int value);

eIndex addAresta(listOfArestas list, aresta newAresta);

eIndex addPath(path list, aresta newAresta);

void showDjikstraPath(path list);

void showMist(mist mancha);

graphNode createNewNodeWithId(int id);

eIndex arestaWithSameDestinyAndSmallerValue(listOfArestas list, aresta arestaInProof);

path minorPath(path list);


#endif /* DjikstraImplementation_h */
