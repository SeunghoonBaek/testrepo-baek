//
//  Graph.h
//  midTerm
//
//  Created by YoonSeijung on 2017. 10. 10..
//  Copyright © 2017년 YoonSeijung. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#define WHITE 0
#define GRAY 1
#define BLACK 2

class Graph{
public:
    int size;
    int* parent;
    int* color;
    List* adjList;
    List* sList;
    
    Graph(int n){
        size = n;
        sList = new List[size];
        adjList = new List[size];
        parent = new int[size];
        color = new int[size];
        
        for(int i=0;i<size;i++){
            adjList[i].head = NULL;
            adjList[i].cur = NULL;
            parent[i] = -1;
            color[i] = WHITE;
        }
    }
};



#endif /* Graph_h */
