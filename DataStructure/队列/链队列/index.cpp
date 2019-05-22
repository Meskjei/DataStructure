//
//  index.cpp
//  DataStructure
//
//  Created by 黄嘉成 on 2019/5/22.
//  Copyright © 2019 黄嘉成. All rights reserved.
//

#include <iostream>

typedef struct QNode {
    int data;
    QNode *next;
} QNode;

//初始化队列
void initQueue(QNode &L, QNode *front, QNode *rear);
//销毁队列
void destroyQueue(QNode &L, QNode *front, QNode *rear);
//进队列
void enQueue(int data, QNode *front, QNode *rear);
//出队列
int deQueue(QNode &L, QNode *front, QNode *rear);



//初始化队列
void initQueue(QNode &L, QNode *front, QNode *rear){
    front = rear = &L;
    L.next = NULL;
}


//销毁队列
void destroyQueue(QNode &L, QNode *front, QNode *rear){
    QNode *p = L.next, *q = NULL;
    while(p != NULL){
        q = p->next;
        delete p;
        p = q;
    }
    rear = front;
}

//进队列
void enQueue(int data, QNode *front, QNode *rear){
    QNode newNode;
    newNode.data = data;
    rear->next = &newNode;
    rear = rear->next;
}

//出队列
int deQueue(QNode &L, QNode *front, QNode *rear){
    QNode *p = front->next;
    int result = p->data;
    front->next = p->next;
    if(p == rear){
        rear = front;
    }
    delete p;
    return result;
}
