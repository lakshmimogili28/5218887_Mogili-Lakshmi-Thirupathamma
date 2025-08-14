#include<stdio.h>
#include<stdint.h>
int cmpAsc(const void*a, const void*b){
    return (*(int*)a-*(int*)b);
}
int cmpDesc(const void *a,const void *b){
    return (*(int *)b-*(int *)a);
}
int main(){
    int q;
    scasnf("%d",&q);
    while(q--){
        int n,k;
        scanf("%d%d",&n,&k);
        int A[n],B[n];
        for (int i=0;i<n;i++) scanf("%d",&A[i]);
        for (int i=0;i<n;i++) scanf("%d",&B[i]);
        qsort(A,n,sizeof(int),cmpAsc);
        qsort(B,n,sizeof(int),cmpDesc);
        int possible =1;
        for (int i=0;i<n;i++){
            if (A[i]+B[i]<k){
                possible=0;
                break;
            }
        }
        if (possible)printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}