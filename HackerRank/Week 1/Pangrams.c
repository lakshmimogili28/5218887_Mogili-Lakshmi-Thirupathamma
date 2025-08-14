#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char s[1005];
    fgets(s,sizeof(s),stdin);
    int letters[26]={0};
    int count= 0;
    for (int i=0;s[i]!='\0';i++){
        if(isalpha(s[i])){
            char lower =tolower(s[i]);
            int index=lower -'a';
            if(letters[index]==0){
                letters[index]=1;
                count++;
            }
        }
    }
    if (count==26){
        printf("pangram");
    }
    else{
        printf("not pangram");
    
    }
    return 0;

}