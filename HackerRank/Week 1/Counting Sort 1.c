#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int freq[100]={0};
    for (int i=0;i<n;i++){
        int num;
        scanf('%d',&num);
        freq[num]++;
    }
    for (int i=0;i<100;i++){
        printf("%d",freq[i]);
        if (i<99) printf(" ");
    }
    return 0;
    
    
}