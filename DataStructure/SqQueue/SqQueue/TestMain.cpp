#include "SqQueue.h"
#include "CirQueue.h"
#include <stdio.h>
#include <cstring>

int main() {
	//test for 非循环队列
	struct Queue *queue = create_queue();
	if (queue == NULL) { printf("create_queue failed\n"); return -1; }
	int size = 5;
	char *data = (char*)malloc(size * sizeof(char));
	memcpy(data, "1234\0", size);
	push_queue(queue, data, size);
	printf("size:%d,top:%s\n", queue->size, top_queue(queue)->data);
	size = 5;
	data = (char*)malloc(size * sizeof(char));
	memcpy(data, "4321\0", size);
	push_queue(queue, data, size);
	printf("size:%d,top:%s\n", queue->size, top_queue(queue)->data);
	size = 6;
	data = (char*)malloc(size * sizeof(char));
	memcpy(data, "66666\0", size);
	push_queue(queue, data, size);
	printf("size:%d,top:%s\n", queue->size, top_queue(queue)->data);
	QNode *top = top_queue(queue);
	pop_queue(queue);
	free(top->data);
	free(top);
	printf("size:%d,%s\n", queue->size, top_queue(queue)->data);
	//test for 循环队列
	struct CirQueue *cirqueue = create_cirqueue();
	if (cirqueue == NULL) { printf("create_cirqueue failed\n"); return -1; }
	int val = 5;
	push_cirqueue(cirqueue, val);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	val = 6;
	push_cirqueue(cirqueue, val);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	val = 7;
	push_cirqueue(cirqueue, val);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	val = 8;
	push_cirqueue(cirqueue, val);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	val = 9;
	push_cirqueue(cirqueue, val);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	val = 10;
	push_cirqueue(cirqueue, val);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	pop_cirqueue(cirqueue);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	pop_cirqueue(cirqueue);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	pop_cirqueue(cirqueue);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	pop_cirqueue(cirqueue);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	pop_cirqueue(cirqueue);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	pop_cirqueue(cirqueue);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	val = 11;
	push_cirqueue(cirqueue, val);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	val = 12;
	push_cirqueue(cirqueue, val);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	pop_cirqueue(cirqueue);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	val = 13;
	push_cirqueue(cirqueue, val);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	pop_cirqueue(cirqueue);
	printf("size:%d,top:%d\n", cirqueue->size, top_cirqueue(cirqueue));
	getchar();
	return 0;
}