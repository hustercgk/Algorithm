#include <stdio.h>
int main(int argc, char const *argv[])
{
	/* code */
	int a, b, c;
	while(scanf("%d", &a) != EOF)
	{	
		c = 0;
		for(; a>0; a--)
		{
			scanf("%d", &b);
			c = c + b;
		}
		printf("%d\n", c);
	}
	return 0;
}