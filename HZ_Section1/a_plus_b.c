#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	/* code */
	// char *buf = (char*)malloc(sizeof(char)*4);
	// int a, b;
	// int c[20];
	// int i = 0;
	// int j = 0;
	// while(gets(buf) != NULL)
	// {
	// 	a = buf[0]-'0';
	// 	b = buf[2]-'0';
	// 	c[i] = a+b;
	// 	i++;
	// }
	// for(j=0; j<i; j++)
	// {
	// 	printf("%d\n", c[j]);
	// }

	/*网上找的....*/
	int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    printf("%d\n",a+b);
	return 0;
}