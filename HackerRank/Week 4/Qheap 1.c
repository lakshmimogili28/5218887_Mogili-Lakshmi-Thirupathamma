#include <stdio.h>
#include <stdlib.h>

#define MAX 100000   // maximum queries

// -------- Min Heap Structure --------
int heap[MAX+5];
int heapSize = 0;

// -------- Helper Functions --------
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyUp(int idx) {
    while (idx > 1 && heap[idx] < heap[idx/2]) {
        swap(&heap[idx], &heap[idx/2]);
        idx /= 2;
    }
}

void heapifyDown(int idx) {
    int smallest = idx;
    int left = 2*idx, right = 2*idx+1;

    if (left <= heapSize && heap[left] < heap[smallest])
        smallest = left;
    if (right <= heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// -------- Operations --------
void insert(int val) {
    heap[++heapSize] = val;
    heapifyUp(heapSize);
}

void deleteVal(int val) {
    // Find index of val
    int idx = -1;
    for (int i = 1; i <= heapSize; i++) {
        if (heap[i] == val) {
            idx = i;
            break;
        }
    }
    if (idx == -1) return;

    // Replace with last element
    heap[idx] = heap[heapSize--];

    // Fix heap
    heapifyUp(idx);
    heapifyDown(idx);
}

int getMin() {
    return heap[1];
}

// -------- Main --------
int main() {
    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int type, v;
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &v);
            insert(v);
        } 
        else if (type == 2) {
            scanf("%d", &v);
            deleteVal(v);
        } 
        else if (type == 3) {
            printf("%d\n", getMin());
        }
    }
    return 0;
}