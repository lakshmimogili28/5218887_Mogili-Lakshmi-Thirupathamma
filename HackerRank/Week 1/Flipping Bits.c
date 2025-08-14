#include<stdio.h>
#include<stdint.h>
unsigned long flippingBits(unsigned long n){
    return n ^ 0xFFFFFFFF;
}
int main(){
    int q;
    scanf("%d",&q);
    unsigned long numbers[q];
    for (int i=0;i<q;i++){
        scanf("%lu",&numbers[i]);
    }
    for (int i=0;i<q;i++){
        printf("%lu\n",flippingBits(numbers[i]));
    }
    return 0;
}