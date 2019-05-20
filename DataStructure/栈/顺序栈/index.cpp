//
//  index.cpp
//  DataStructure
//
//  Created by 黄嘉成 on 2019/5/20.
//  Copyright © 2019 黄嘉成. All rights reserved.
//

#include <iostream>
#include "stdlib.h"
#define STACK_INIT_SIZE 100
#define SIZE_INCREMENT 10
using namespace std;

typedef struct {
    int *base;
    int *top;
    int stackSize;
    int length;
} SqStack;

//初始化栈
SqStack* initStack();
//入栈
void push(SqStack stack,int data);
//出栈
int pop();

//初始化栈
SqStack* initStack(SqStack &stack){
    stack.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    stack.top = stack.base;
    stack.stackSize = STACK_INIT_SIZE;
    stack.length = 0;
    return &stack;
}

//入栈
void push(SqStack &stack,int data){
    if(stack.length >= stack.stackSize){
        stack.base = (int *)realloc(stack.base, sizeof(int) * SIZE_INCREMENT);
    }
    
    *stack.top++ = data;
}

//出栈
int pop(SqStack stack){
    if(stack.length == 0){
        cout<<"栈中没有元素";
        return NULL;
    }
    return *--stack.top;
}

