#include "stdlib.h"

struct Memory {
    size_t type;
    void* location;
    int priority;
}

struct Memory queue;
int head = 0;
int tail = 0;
int queue_length = 0;

int init_queue(struct Memory heap) {
     heap = calloc(sizeof(struct Memory), 1);
     queue = heap;
     queue_length = 0;
}

int insert(size_t type, void *data, int priority) {
    if (tail == queue_length)
        tail = 1;
    queue[tail].type = type;
    queue[tail].data = data;
    queue[tail].priority = priority;
    tail = tail + 1;
}

struct Memory remove() {
    struct Memory memory;
    memory = queue[head];
    if (head == queue_length)
	head = 1;
    head = head + 1;	
    return memory;
}

int alloc() {

}

int free() {

}
