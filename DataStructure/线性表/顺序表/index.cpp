//
//  index.cpp
//  DataStructure
//
//  Created by 黄嘉成 on 2019/5/18.
//  Copyright © 2019 黄嘉成. All rights reserved.
//
#include <iostream>
#include <stdlib.h>
#define LIST_INT_SIZE 100    //顺序表初始长度
#define LISTINCREMENT 10    //顺序表增量长度
using namespace std;

typedef struct {
    int *data;  //存储空间基址
    int length; //当前长度
    int listSize;   //当前分配的存储容量
} Sqlist ;

Sqlist* initList(); //初始化顺序表
int locateData(Sqlist L, int data); //查找数据
void listInsert(Sqlist &L, int index, int data);    //插入数据
void listDelete(Sqlist &L, int index);  //删除数据

Sqlist* initList(){
    Sqlist L;
    L.data = (int *)malloc(LIST_INT_SIZE * sizeof(int));
//    判断内存是否分配成功
    if(!L.data){
        cout<<"分配内存失败";
        exit(-1);
    }
    L.length = 0;
    L.listSize = LIST_INT_SIZE;
    return &L;
}

int locateData(Sqlist L, int data){
    int *head = L.data;
    for (int i=0,length=L.length; i<length; i++) {
        head += i;
        if(*head == data){
            return i;
        }
    }
    return -1;
}

void listInsert(Sqlist &L, int position, int data){
//    合法性判断
    if(position < 1 || position > L.length + 1){
        cout<<"插入位置非法！";
        exit(-1);
    }
    
    if(L.length >= L.listSize){
//        若长度已经等于分配的长度，则再分配空间
        L.data = (int *)realloc(L.data, (L.listSize + LISTINCREMENT) * sizeof(int));
//      判断内存是否分配成功
        if(!L.data){
            cout<<"再分配内存失败";
            exit(-1);
        }
        L.listSize += LISTINCREMENT;
    }

    int *insertPosition = L.data + position - 1;
    int *last = L.data + L.length - 1;
    
//    在插入位置右边的元素全部往右移一位
    for (; last>=insertPosition; last--) {
        *(last + 1) = *(last);
    }
    
//    插入元素
    *insertPosition = data;
    L.length++;
}

void listDelete(Sqlist &L, int position){
    //    合法性判断
    if(position < 1 || position > L.length + 1){
        cout<<"需要删除的位置非法！";
        exit(-1);
    }
//    需要删除的位置
    int *deletePostion = L.data + position - 1;
    int *last = L.data + L.length - 1;
    
//    将被删除位置的右部所有元素左移
    for (++deletePostion; deletePostion<=last; deletePostion++) {
        *(deletePostion-1) = *deletePostion;
    }
    L.length--;
}


