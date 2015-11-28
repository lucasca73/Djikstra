//
//  main.c
//  Djikstra
//
//  Created by Lucas Araujo on 11/27/15.
//  Copyright © 2015 Lucas Araujo. All rights reserved.
//

#include "DjikstraImplementation.h"

int getValueForArestaIndex(eIndex index);
void switchArestasForIndex(eIndex parentIndex, eIndex sonIndex);
graphNode settingGraph();

static listOfArestas list;

int main(int argc, const char * argv[]) {
    
    list = calloc(20, sizeof(backAresta));
    
    mist mistOfNodes = createNewMist();
    
    // Setting graph
    graphNode firstNode = settingGraph();
    
    // adding first element
    eIndex index = addNodeToMist(mistOfNodes, firstNode, list, 0);
    
    boolean isFinal = false;
    path result = calloc(20, sizeof(backAresta));
    
    do {
        heapfyNode(index, getValueForArestaIndex, switchArestasForIndex);
        
        printf("\n --- heap\n");
        showDjikstraPath(list);
        printf(" --- end\n\n");
        

        aresta removed =(aresta) removeFirst((void**)list);
        index--;

        if(!removed){
            printf("there is no way to destiny node\n");
            break;
        }
        
        isFinal = removed->destiny->id == 6;
        index += addNodeToMist(mistOfNodes, removed->destiny, list, removed->value);
        
        addAresta(result, removed);
        showDjikstraPath(result);
        
    } while (!isFinal);
    
    printf("\n\nMinor path:\n");
    
    showDjikstraPath(minorPath(result));

    return 0;
}


// interface for generic heap
int getValueForArestaIndex(eIndex index){
    
    if(!list){
        return 0;
    }
    
    return list[index]->value;
}

// interface for generic heap
void switchArestasForIndex(eIndex parentIndex, eIndex sonIndex){
    
    if(!list){
        return;
    }
    
    //Havent validated if blows index array
    aresta swap = list[parentIndex];
    list[parentIndex] = list[sonIndex];
    list[sonIndex] = swap;
    
    eIndex count = 0;

}

graphNode settingGraph(){
    
    graphNode firstNode = createNewNodeWithId(1);
    graphNode node2 = createNewNodeWithId(2);
    graphNode node3 = createNewNodeWithId(3);
    graphNode node4 = createNewNodeWithId(4);
    graphNode node5 = createNewNodeWithId(5);
    graphNode node6 = createNewNodeWithId(6);
    graphNode node7 = createNewNodeWithId(7);

    setArestaOnNodes(firstNode, node2, 10);
    setArestaOnNodes(firstNode, node3, 15);
    setArestaOnNodes(firstNode, node7, 5);

    setArestaOnNodes(node2, node5, 20);
    
    setArestaOnNodes(node3, node4, 25);
    
    setArestaOnNodes(node5, node7, 30);
    setArestaOnNodes(node5, node6, 35);
    
    setArestaOnNodes(node4, node7, 5);
    setArestaOnNodes(node4, node6, 38);
    
    setArestaOnNodes(node7, node3, 2);
    setArestaOnNodes(node7, node2, 2);
    setArestaOnNodes(node7, node6, 88);
    
    return firstNode;
}


