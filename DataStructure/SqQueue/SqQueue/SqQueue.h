#pragma once
#include <stdlib.h>
//存储队列中的元素
struct QNode {
	int size;
	char *data;
	QNode *next;
};

//队列结构体
struct Queue {
	int size;
	struct QNode *front, *rear;
};
//新建队列元素节点
struct QNode *new_node(char *d, int size);
//创建一个队列
struct Queue *create_queue();
//入队
int push_queue(struct Queue *q, char *d, int size);
//出队
void pop_queue(struct Queue *q);
//返回队首元素
struct QNode *top_queue(struct Queue *q);