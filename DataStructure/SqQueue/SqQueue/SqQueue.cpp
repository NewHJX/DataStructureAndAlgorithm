#include "SqQueue.h"
//�½�����Ԫ�ؽڵ�
struct QNode *new_node(char *d, int size) {
	struct QNode* node = (struct QNode*)malloc(sizeof(struct QNode));
	if (node == NULL) return NULL;
	node->data = d;
	node->size = size;
	return node;
}
//����һ������
struct Queue *create_queue() {
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
	if (q == NULL) return NULL;
	q->front = q->rear = NULL;
	q->size = 0;
	return q;
}
//���
int push_queue(struct Queue *q, char *d, int size) {
	if (q == NULL || d == NULL) return -2;
	struct QNode *node = new_node(d, size);
	if (node == NULL) return -1;
	q->size += 1;
	if (q->rear == NULL) {
		q->front = q->rear = node;
		return 0;
	}
	q->rear->next = node;
	q->rear = node;
	return 0;
}
//����
void pop_queue(struct Queue *q) {
	if (q == NULL) return;
	if (q->front == NULL) { q->size = 0; return; }
	q->front = q->front->next;
	q->size -= 1;
	if (q->front == NULL) {
		q->size = 0;
		q->rear = NULL;
	}
}
//���ض���Ԫ��
struct QNode *top_queue(struct Queue *q) {
	if (q == NULL) return NULL;
	if (q->front == NULL) { q->size = 0; return NULL; }
	return q->front;
}