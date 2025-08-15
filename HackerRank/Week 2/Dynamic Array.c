#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;   
    int size;    
    int cap;    
}Sequence;

void add_to_sequence(Sequence *seq, int value) {
    if (seq->size == seq->cap) {
        seq->cap = seq->cap ? seq->cap * 2 : 2;
        seq->data = realloc(seq->data, seq->cap * sizeof(int));
    }
    seq->data[seq->size++] = value;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    // allocate n sequences
    Sequence *arr = calloc(n, sizeof(Sequence));
    int lastAnswer = 0;

    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);

        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            add_to_sequence(&arr[idx], y);
        } 
        else if (type == 2) {
            int pos = y % arr[idx].size;
            lastAnswer = arr[idx].data[pos];
            printf("%d\n", lastAnswer);
        }
    }
    for (int i = 0; i < n; i++) {
        free(arr[i].data);
    }
    free(arr);

    return 0;
}