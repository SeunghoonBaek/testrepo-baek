//
//  main.cpp
//  midTerm
//
//  Created by YoonSeijung on 2017. 10. 10..
//  Copyright © 2017 YoonSeijung. All rights reserved.
//

/*
  원래 Node&으로 정의하고, 밑에도 그래서 ref.~~였음
 
 2. Tobological sorted List를 이용하여 edge Release >> 최장경로 찾기
 cf) Bellman-Ford Algorithm
 */


#define WHITE 0
#define GRAY 1
#define BLACK 2

#include "List.h"
#include "Node.h"
#include "Graph.h"
#include "DFS.h"
#include "BellmanFord.h"
#include <iostream>
using namespace std;

void printAllNode(List* sListPtr, int sizeOfVertex);
int* getMinDistanceUsingBellmanFord(List* weightListPtr, int sizeOfVertex, int numOftestVertex);

int main(int argc, const char * argv[]) {
    
    int nVertex;
    int f, h, w;
    
    freopen("input.txt", "r", stdin);
    scanf("%d", &nVertex);
    
    Node* boxes = new Node[nVertex+2];
    Graph* g = new Graph(nVertex+2); // -> why 2 instance should be created?
    int* rslt = new int(nVertex+2);
    
    
    /* Input data to Boxes (vertex information) */
    boxes[0].setData(0, 1000, 0, 1000);
    g->adjList[0].insertNode(&boxes[0]);
    
    for(int i=1;i<=nVertex;i++){
        scanf("%d", &f);
        scanf("%d", &h);
        scanf("%d", &w);
        
        boxes[i].setData(i, f, h, w);
        
        g->adjList[i].insertNode(&boxes[i]);
    }
    
    boxes[nVertex+1].setData(nVertex+1, 0, 0, 0);
    g->adjList[nVertex+1].insertNode(&boxes[nVertex+1]);
    
    
    
    /* Define Graph::AdjList (edge information) */
    for(int i=0;i<=nVertex;i++){
        for(int j=1;j<=nVertex+1;j++){
            if((boxes[i].floor > boxes[j].floor) && (boxes[i].weigh > boxes[j].weigh)){
                Node* temp = new Node(boxes[j]);    //Node* temp = new Node(boxes[j].label, boxes[j].floor, boxes[j].heigh, boxes[j].weigh);
                g->adjList[i].insertNode(temp);
                //g->adjList[i].insertNode(&boxes[j]);

            }
        }
    }
    
    /* Print ADJ list of all vertex */
    for(int i=0;i<=nVertex+1;i++){
        g->adjList[i].visitAllNodes();
    }
    
    
    DFS(g);
    cout<<endl<<endl;
    
    /* Print Topological Sorted List */
    g->sList->visitAllNodes();
    
    /* Shortest path */
    for(int i=0;i<nVertex+2;i++){
        rslt[i] = 0;
    }
    
    DEBUG_printAllNode_And_SetInfiniteValue(g->adjList, nVertex);
    
    int testVertex = 1;
    int* minDistance = getMinDistanceUsingBellmanFord(g->adjList, nVertex, testVertex);

    for(int i = 0 ; i <= nVertex ; i++){
        printf("[%d] : %d\n", i, minDistance[i]);
    }
    
    delete[] minDistance;
    
    
    return 0;
}
