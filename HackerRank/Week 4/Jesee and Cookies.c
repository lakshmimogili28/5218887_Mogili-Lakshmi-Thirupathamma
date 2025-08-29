#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000   // max number of cookies (from constraints)

long long heap[MAX+5];
int heapSize = 0;

// ---------- Min-Heap Helper Functions ----------
void swap(long long *a, long long *b) {
    long long t = *a; *a = *b; *b = t;
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

void insert(long long val) {
    heap[++heapSize] = val;
    heapifyUp(heapSize);
}

long long extractMin() {
    if (heapSize == 0) return -1; // empty
    long long root = heap[1];
    heap[1] = heap[heapSize--];
    heapifyDown(1);
    return root;
}

long long getMin() {
    if (heapSize == 0) return -1;
    return heap[1];
}

// ---------- Solve Jesse and Cookies ----------
int main() {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);

    for (int i = 0; i < n; i++) {
        long long x;
        scanf("%lld", &x);
        insert(x);
    }

    int operations = 0;

    while (heapSize > 1 && getMin() < k) {
        long long least = extractMin();
        long long second = extractMin();

        long long newSweet = least + 2*second;
        insert(newSweet);
        operations++;
    }

    if (getMin() >= k)
        printf("%d\n", operations);
    else
        printf("-1\n");

    return 0;
}