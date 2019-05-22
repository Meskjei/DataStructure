//
//  index.cpp
//  DataStructure
//
//  Created by 黄嘉成 on 2019/5/22.
//  Copyright © 2019 黄嘉成. All rights reserved.
//

#include <iostream>
using namespace std;

#define MAXSIZE 100 //最大队列长度

typedef struct {
    int *base;
    int front;
    int rear;
    int queueSize;
} SqQueue;

//初始化循环队列
void initQueue(SqQueue &Q);
//进队列
void enQueue(SqQueue &Q, int data);
//出队列
void deQueue(SqQueue &Q);


//c初始化循环队列
void initQueue(SqQueue &Q){
    Q.base = new int[MAXSIZE];
    if(!Q.base){
        cout<<"无法为队列分配空间";
        exit(-1);
    }
    Q.queueSize = MAXSIZE;
    Q.front = Q.rear = 0;
}

//进队列
void enQueue(SqQueue &Q, int data){
    if((Q.rear + 1) % MAXSIZE == Q.front){
        cout<<"队列已满，无法添加";
        return;
    }
    Q.base[Q.rear] = data;
    Q.rear = (Q.rear + 1) % Q.queueSize;
}

//出队列
void deQueue(SqQueue &Q, int &data){
    if(Q.front == Q.rear){
        cout<<"队列为空";
        return;
    }
    data = Q.base[Q.front];
    Q.front = (Q.front + 1) % Q.queueSize;
}
