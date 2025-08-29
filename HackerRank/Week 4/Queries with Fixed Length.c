#include <stdio.h>
#include <stdlib.h>

// Deque structure
typedef struct {
    int *data;
    int front, back;
} Deque;

// Initialize deque
void initDeque(Deque *dq, int n) {
    dq->data = (int*)malloc(n * sizeof(int));
    dq->front = 0;
    dq->back = -1;
}

// Check if deque is empty
int isEmpty(Deque *dq) {
    return dq->front > dq->back;
}

// Push index at back (maintain decreasing order of arr values)
void pushBack(Deque *dq, int idx, int arr[]) {
    while (!isEmpty(dq) && arr[dq->data[dq->back]] <= arr[idx]) {
        dq->back--;
    }
    dq->data[++dq->back] = idx;
}

// Pop front if out of window
void popFront(Deque *dq, int idx, int d) {
    if (!isEmpty(dq) && dq->data[dq->front] <= idx - d) {
        dq->front++;
    }
}

// Get front index (max element in window)
int front(Deque *dq) {
    return dq->data[dq->front];
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    while (q--) {
        int d;
        scanf("%d", &d);

        Deque dq;
        initDeque(&dq, n);

        int minOfMax = 1000000000; // large value

        for (int i = 0; i < n; i++) {
            pushBack(&dq, i, arr);
            popFront(&dq, i, d);

            if (i >= d - 1) {
                int windowMax = arr[front(&dq)];
                if (windowMax < minOfMax) {
                    minOfMax = windowMax;
                }
            }
        }

        printf("%d\n", minOfMax);

        free(dq.data);
    }

    return 0;
}