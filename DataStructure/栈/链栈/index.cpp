//
//  index.cpp
//  DataStructure
//
//  Created by 黄嘉成 on 2019/5/20.
//  Copyright © 2019 黄嘉成. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node *next;
} StackNode;
StackNode *globalPointer = NULL;
//初始化栈
void initStack(StackNode &stack);
//入栈
void push(StackNode &stack,int data);
//出栈
int pop(StackNode &stack);

//初始化栈
void initStack(StackNode &stack, int data){
    stack.data = data;
    globalPointer = &stack;
}

//入栈
void push(StackNode &stack,int data){
    if(&stack == NULL){
        cout<<"请先初始化栈";
        return;
    }
    StackNode node;
    node.data = data;
    globalPointer->next = &node;
    globalPointer = globalPointer->next;
}

//出栈
int pop(StackNode &stack){
    if(&stack == NULL){
        cout<<"请先初始化栈";
        return NULL;
    }
    
    int result = globalPointer->data;
    
    StackNode *pointer = &stack;
    while(pointer->next != globalPointer){
        pointer = pointer->next;
    }
    delete globalPointer;
    globalPointer = pointer;
    return result;
}
