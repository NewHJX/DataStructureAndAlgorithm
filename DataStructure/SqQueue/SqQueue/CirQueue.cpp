#include "CirQueue.h"
#include "stdio.h"
//创建一个队列
struct CirQueue *create_cirqueue() {
	struct CirQueue *q = (struct CirQueue*)malloc(sizeof(struct CirQueue));
	if (q == NULL) { printf("create cirqueue failed\n"); return NULL; }
	q->capacity = QUEUE_CAPACITY;
	q->size = 0;
	q->front = 0;
	q->rear = 0;
	return q;
}
//入队
int push_cirqueue(struct CirQueue *q, int val) {
	if (q == NULL) { printf("CirQueue is NULL,so push failed\n"); return -2; }
	if (q->size >= q->capacity) { printf("CirQueue overflow,so push failed\n"); return -3; }
	q->size += 1;
	q->data[q->rear] = val;
	q->rear = (q->rear + 1) % QUEUE_CAPACITY;
	return 0;
}
//出队
void pop_cirqueue(struct CirQueue *q) {
	if (q == NULL) { printf("CirQueue is NULL,so pop failed\n"); return; }
	if (q->size <= 0) { printf("size of CirQueue is 0,so pop failed\n"); return; }
	q->size -= 1;
	q->front = (q->front + 1) % QUEUE_CAPACITY;
}
//返回队首元素
int top_cirqueue(struct CirQueue *q) {
	if (q->size <= 0) {
		//maybe You should calculate the size first
		printf("size of CirQueue is 0,so top_cirqueue failed\n");
		return -1;
	}
	return q->data[q->front];
}