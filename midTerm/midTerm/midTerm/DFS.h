//
//  DFS.h
//  midTerm
//
//  Created by YoonSeijung on 2017. 10. 19..
//  Copyright © 2017년 YoonSeijung. All rights reserved.
//

#ifndef DFS_h
#define DFS_h

#include "Node.h"
#include "List.h"
#include "Graph.h"

void DFS_visit(Graph* g, int u){
    g->color[u] = GRAY;
    
    /* ADJList의 헤드노드는 해당 정점정보를 위해 항상 있으므로, 헤드노드의 next node부터가 실제 연결된 vertex */
    Node* tmp = g->adjList[u].head;
    
    if(tmp->next == NULL){
        g->color[u] = BLACK;
        g->sList->insertReverse(new Node(*tmp));
        return;
    }
    
    tmp = tmp->next;
    
    while (tmp != NULL){
        if(g->color[tmp->label] == WHITE){
            g->parent[tmp->label] = u;
            DFS_visit(g, tmp->label);
        }
        tmp = tmp->next;
    }
    
    if(g->color[u] != BLACK){
        g->color[u] = BLACK;
        tmp = new Node(*g->adjList[u].head);
        tmp->next = NULL;
        g->sList->insertReverse(tmp);
    }
    
    
}


void DFS(Graph* g){
    for(int u=0;u<g->size;u++){
        if(g->color[u] == WHITE)
            DFS_visit(g, u);
    }
    
}

#endif /* DFS_h */
