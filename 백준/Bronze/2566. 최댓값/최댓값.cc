#include<stdio.h>

int main()
{
    int n[9][9], mx=0, res;
    for(int i=0; i<81; i++){
        scanf("%d", &n[i/9][i%9]);
        if(mx<=n[i/9][i%9]){
            mx=n[i/9][i%9];
            res=i;
        }
    }
    printf("%d\n%d %d", mx, res/9+1, res%9+1);
    return 0;
}