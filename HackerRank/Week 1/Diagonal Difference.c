#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    int a[n][n];
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            
        }
    }
    int primarySum=0,secondarySum=0;
    for(i=0;i<n;i++){
        primarySum+=a[i][i];
        secondarySum+=a[i][n-i-1];
    }
    int difference = abs(primarySum-secondarySum);
    printf("%d\n",difference);
    return 0;
    
}
