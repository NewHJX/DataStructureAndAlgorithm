#pragma once
#include <stdlib.h>
//�洢�����е�Ԫ��
struct QNode {
	int size;
	char *data;
	QNode *next;
};

//���нṹ��
struct Queue {
	int size;
	struct QNode *front, *rear;
};
//�½�����Ԫ�ؽڵ�
struct QNode *new_node(char *d, int size);
//����һ������
struct Queue *create_queue();
//���
int push_queue(struct Queue *q, char *d, int size);
//����
void pop_queue(struct Queue *q);
//���ض���Ԫ��
struct QNode *top_queue(struct Queue *q);