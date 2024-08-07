#include <stdio.h>

int main()
{
    char s[101];
    while(scanf("%[^\n]s",s)!=-1)
   {
          printf("%s\n",s);
          getchar();
   }
}
