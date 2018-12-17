#pragma once
#include <stdlib.h>
#define QUEUE_CAPACITY 5
//队列结构体
struct CirQueue {
	int capacity;
	int size;
	int front;
	int rear;
	int data[QUEUE_CAPACITY];
};

//创建一个队列
struct CirQueue *create_cirqueue();
//入队
int push_cirqueue(struct CirQueue *q, int val);
//出队
void pop_cirqueue(struct CirQueue *q);
//返回队首元素
int top_cirqueue(struct CirQueue *q);