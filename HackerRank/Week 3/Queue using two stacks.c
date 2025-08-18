#include <stdio.h>
#include <stdlib.h>

// Define stack structure
typedef struct {
    long long *arr;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (long long*)malloc(capacity * sizeof(long long));
    return stack;
}

// Check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push element into stack
void push(Stack* stack, long long value) {
    stack->arr[++stack->top] = value;
}

// Pop element from stack
long long pop(Stack* stack) {
    return stack->arr[stack->top--];
}

// Peek top element of stack
long long peek(Stack* stack) {
    return stack->arr[stack->top];
}

// Queue using two stacks
typedef struct {
    Stack* inStack;
    Stack* outStack;
} Queue;

// Create queue
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->inStack = createStack(capacity);
    q->outStack = createStack(capacity);
    return q;
}

// Move elements from inStack to outStack if needed
void shiftStacks(Queue* q) {
    if (isEmpty(q->outStack)) {
        while (!isEmpty(q->inStack)) {
            push(q->outStack, pop(q->inStack));
        }
    }
}

// Enqueue operation
void enqueue(Queue* q, long long value) {
    push(q->inStack, value);
}

// Dequeue operation
void dequeue(Queue* q) {
    shiftStacks(q);
    if (!isEmpty(q->outStack)) {
        pop(q->outStack);
    }
}

// Print front element
void printFront(Queue* q) {
    shiftStacks(q);
    if (!isEmpty(q->outStack)) {
        printf("%lld\n", peek(q->outStack));
    }
}

// Main function
int main() {
    int q;
    scanf("%d", &q);

    Queue* queue = createQueue(q);

    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            long long x;
            scanf("%lld", &x);
            enqueue(queue, x);
        } else if (type == 2) {
            dequeue(queue);
        } else if (type == 3) {
            printFront(queue);
        }
    }

    return 0;
}