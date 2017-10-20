//
//  List.h
//  midTerm
//
//  Created by YoonSeijung on 2017. 10. 10..
//  Copyright © 2017년 YoonSeijung. All rights reserved.
//

#ifndef List_h
#define List_h
#include<iostream>
#include "Node.h"
using namespace std;

class List{
public:
    Node* head;
    Node* cur;
    
    List(void){
        head = NULL;
        cur = NULL;
    }
    
    void insertReverse(const Node* _node){
        Node* temp = new Node(*_node);
        
        if(head==NULL){
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }
    
    void insertNode(const Node* _node){
        
        Node* temp = new Node(*_node);
        
        if(head==NULL){
            head = temp;
            cur = temp;
        } else{
            cur->next = temp;
            cur = temp;
        }
    }
    
    void visitAllNodes(){
        if(head==NULL){
            cout << endl;
            return;
        }
        
        Node* temp = head;
        
        while(temp != NULL){
            cout << temp->label << " -> ";
            temp = temp->next;
        }
        
        cout << endl;
        
    }
    
};


#endif /* List_h */
