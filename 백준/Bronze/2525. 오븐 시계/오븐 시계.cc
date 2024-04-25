#include<stdio.h> 

int main(void){
  int h,m,t;
  scanf("%d %d %d",&h,&m,&t);
  int ans = (h*60)+m+t;
  ans %= 24*60;
  printf("%d %d",ans/60,ans%60);
  return 0;  
}