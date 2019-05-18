//
//  index.cpp
//  DataStructure
//
//  Created by 黄嘉成 on 2019/5/18.
//  Copyright © 2019 黄嘉成. All rights reserved.
//

#include <iostream>
using namespace std;

//定义链表节点
typedef struct LNode{
    int data;   //数据域
    LNode *next;    //指针域
} LNode;
//取第i个元素
LNode getElem(LNode head, int position);
//插入元素
void listInsert(LNode &head, int position, LNode newNode);
// 删除元素
void listDelete(LNode &head, int position);
// 重置为空表
void clearList(LNode &head);
//生成含有n个元素的链表
LNode* createList(int n);



//取第i个元素
LNode getElem(LNode head, int position){
    LNode *pointer = head.next;
    int couter = 1; //计数器
    while(pointer->next && couter < position){
        pointer = pointer->next;
        couter++;
    }
    if(!pointer || couter > position){
        cout<<"元素不存在";
        exit(-1);
    }
    
    return *pointer;
}

//在第position个元素之前插入新元素
void listInsert(LNode &head, int position, LNode *newNode){
    LNode *pointer = &head; //头指针
    int couter = 0; //计数器
    while(pointer && couter < position - 1){
        pointer = pointer->next;
        couter++;
    }
    if(!pointer || couter > position){
        cout<<"所要插入的位置不存在";
        exit(-1);
    }
    
    if(newNode == NULL){
        cout<<"要插入的对象不得为空";
        exit(-1);
    }
    newNode->next = pointer->next;
    pointer->next = newNode;
}

// 删除元素
void listDelete(LNode &head, int position){
    LNode *pointer = &head; //头指针
    int couter = 0; //计数器
    while(pointer && couter < position - 1){
        pointer = pointer->next;
        couter++;
    }
    if(!pointer || couter > position){
        cout<<"所要插入的位置不存在";
        exit(-1);
    }
    
    LNode *current = pointer->next;
    LNode *next = current->next;
    current->next = next;
    delete current;
}

// 重置为空表
void clearList(LNode &head){
    LNode *L = &head;
    while(L->next){
        LNode *pointer = L->next;
        L->next = pointer->next;
        delete pointer;
    }
}

//生成含有n个元素的链表
LNode* createList(int n){
    LNode *head = (LNode *)malloc(sizeof(LNode));
    LNode *pointer = head;
    for (int i=0; i<n; i++) {
        LNode *newNode = (LNode *)malloc(sizeof(LNode));
        pointer->next = newNode;
        pointer = pointer->next;
    }
    return head;
}
