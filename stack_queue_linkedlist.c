#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

bool push(Stack *stack, int value) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");
        return false;
    }
    stack->data[++stack->top] = value;
    return true;
}

bool pop(Stack *stack, int *value) {
    if (stack->top < 0) {
        printf("Error: Stack underflow\n");
        return false;
    }
    *value = stack->data[stack->top--];
    return true;
}

// Queue implementation
typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool enqueue(Queue *queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Error: Queue overflow\n");
        return false;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->data[++queue->rear] = value;
    return true;
}

bool dequeue(Queue *queue, int *value) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Error: Queue underflow\n");
        return false;
    }
    *value = queue->data[queue->front++];
    return true;
}

// Singly linked list implementation
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node nodes[MAX_SIZE];
    int head;
} LinkedList;

void initializeList(LinkedList *list) {
    list->head = -1;
}

bool insert(LinkedList *list, int value) {
    if (list->head == MAX_SIZE - 1) {
        printf("Error: List full\n");
        return false;
    }
    Node *newNode = &list->nodes[++list->head];
    newNode->data = value;
    newNode->next = NULL;
    return true;
}

bool removeItem(LinkedList *list, int value) {
    if (list->head == -1) {
        printf("Error: List empty\n");
        return false;
    }
    Node *current = &list->nodes[0];
    Node *prev = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                list->head--;
            } else {
                prev->next = current->next;
            }
            return true;
        }
        prev = current;
        current = current->next;
    }
    printf("Error: Value not found in list\n");
    return false;
}

int main() {
    // Example usage
    Stack stack;
    initializeStack(&stack);
    push(&stack, 1);
    push(&stack, 2);
    int popped;
    pop(&stack, &popped);
    printf("Popped from stack: %d\n", popped);

    Queue queue;
    initializeQueue(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    int dequeued;
    dequeue(&queue, &dequeued);
    printf("Dequeued from queue: %d\n", dequeued);

    LinkedList list;
    initializeList(&list);
    insert(&list, 1);
    insert(&list, 2);
    removeItem(&list, 1);
    printf("Size of linked list: %d\n", list.head + 1);

    return 0;
}
