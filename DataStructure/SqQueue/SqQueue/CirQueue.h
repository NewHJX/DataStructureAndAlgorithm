#pragma once
#include <stdlib.h>
#define QUEUE_CAPACITY 5
//���нṹ��
struct CirQueue {
	int capacity;
	int size;
	int front;
	int rear;
	int data[QUEUE_CAPACITY];
};

//����һ������
struct CirQueue *create_cirqueue();
//���
int push_cirqueue(struct CirQueue *q, int val);
//����
void pop_cirqueue(struct CirQueue *q);
//���ض���Ԫ��
int top_cirqueue(struct CirQueue *q);