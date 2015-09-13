#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	/* code */
	int m;
	int a;
	int i;
	scanf("%d", &m);

	char *p = (char*)malloc(sizeof(char)*(m+1));
	for(i = 0 ; i < m; i++)
	{
		scanf("%d", &a);
		p[i] = a;
	}
	p[i] = '\0';
	printf("%s", p);
	return 0;
}