//
//  Node.h
//  midTerm
//
//  Created by YoonSeijung on 2017. 10. 10..
//  Copyright © 2017년 YoonSeijung. All rights reserved.
//

#ifndef Node_h
#define Node_h

class Node{
public:
    int label;
    int floor;
    int heigh;
    int weigh;
    Node* next;
    
    Node(){
        setData(0, 1000, 1000, 1000);
        next = NULL;
    }
    
    
    Node(const Node*& ref){
        this->label = ref->label;
        this->floor = ref->floor;
        this->weigh = ref->weigh;
        this->heigh = ref->heigh;
        this->next = ref->next;
        //setData(ref.label, ref.floor, ref.heigh, ref.weigh);
    }
    
    Node(int l, int f, int h, int w){
        setData(l, f, h, w);
        next = NULL;
    }
    
    void setData(int l, int f, int h, int w){
        label = l;
        floor = f;
        heigh = h;
        weigh = w;
    }
};

#endif /* Node_h */
