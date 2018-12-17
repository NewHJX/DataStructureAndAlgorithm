#include "SqQueue.h"
#include <stdio.h>
#include <cstring>

int main() {
	struct Queue *queue = create_queue();
	if (queue == NULL) { printf("create_queue failed\n"); return -1; }
	int size = 5;
	char *data = (char*)malloc(size * sizeof(char));
	memcpy(data, "1234\0", size);
	push_queue(queue, data, size);
	printf("size:%d,%s\n", queue->size, top_queue(queue)->data);
	size = 5;
	data = (char*)malloc(size * sizeof(char));
	memcpy(data, "4321\0", size);
	push_queue(queue, data, size);
	printf("size:%d,%s\n", queue->size, top_queue(queue)->data);
	size = 6;
	data = (char*)malloc(size * sizeof(char));
	memcpy(data, "66666\0", size);
	push_queue(queue, data, size);
	printf("size:%d,%s\n", queue->size, top_queue(queue)->data);
	QNode *top = top_queue(queue);
	pop_queue(queue);
	free(top->data);
	free(top);
	printf("size:%d,%s\n", queue->size, top_queue(queue)->data);
	getchar();
	return 0;
}