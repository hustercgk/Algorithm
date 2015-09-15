#include <stdio.h>

int  main(int argc, char const *argv[])
{
	/* code */
	int a, b, i, c;
	scanf("%d", &c);
	
	for(i = 0; i < c; i++)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", a+b);
	}
	return 0;
}