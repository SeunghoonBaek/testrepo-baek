#include "BellmanFord.h"
#include <iostream>

#define INFINITE_DISTANCE INT_MAX

void initializerSingleSource(int* distancePtr, int sizeOfVertex, int numStartVertex){
    
    for(int i = 1 ; i <= sizeOfVertex ; i++){
        distancePtr[i] = INFINITE_DISTANCE;
    }
    
    distancePtr[numStartVertex] = 0;
}

int findWeight(Node* node, int u, int v){
    if(!node){
        // NPE
        return INFINITE_DISTANCE;
    }
    
    Node* testNode = node;
    while(testNode){
        if(testNode->label == v){
            return testNode->heigh;
        }else{
            testNode = testNode->next;
        }
    }
    
    return INFINITE_DISTANCE;
}

void DEBUG_printAllNode_And_SetInfiniteValue(List* sListPtr, int sizeOfVertex){
    printf("========================================\n");
    printf("## DEBUG\n");
    for(int i = 0 ; i < sizeOfVertex ; i++){
        Node* testNode = sListPtr[i].head;
        
        printf("[%d] ", i);
        
        while(testNode){
            if(testNode->heigh == 0){
                testNode->heigh = INFINITE_DISTANCE;
            }
            printf("%d(%d)", testNode->label, testNode->heigh);
            
            if(testNode->next){
                if(testNode->next != sListPtr[i].head)
                    printf(", ");
                testNode = testNode->next;
            } else{
                break;
            }
        }
        
        printf("\n");
    }
    printf("========================================\n");
}

void relax(int* distancePtr, List* weightListPtr, int u, int v){
    
    int weight = findWeight(weightListPtr[u].head, u, v);
    
    if(distancePtr[v] > distancePtr[u] + weight){
        distancePtr[v] = distancePtr[u] + weight;
    }
}

int* getMinDistanceUsingBellmanFord(List* weightListPtr, int sizeOfVertex, int numOftestVertex){
    if(!weightListPtr){
        // NPE
        return NULL;
    }
    
    // Initialize distance array
    int* minDistancePtr = new int[sizeOfVertex + 2];
    initializerSingleSource(minDistancePtr, sizeOfVertex, numOftestVertex);
    
    for(int i = 1 ; i <= sizeOfVertex - 1 ; i++){
        for(int j = 1 ; j <= sizeOfVertex - 1 ; j++){
            if(i == j){
                continue;
            }
            
            relax(minDistancePtr, weightListPtr, i, j);
        }
    }
    
    return minDistancePtr;
}
