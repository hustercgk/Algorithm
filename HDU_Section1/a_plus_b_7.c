#include <stdio.h>
int main(int argc, char const *argv[])
{
	/* code */
	int a, b, c;
	int i;
	scanf("%d", &i);
	for(; i>0; i--)
	{
		scanf("%d", &a);
		{	
			c = 0;
			for(; a>0; a--)
			{
				scanf("%d", &b);
				c = c + b;
			}
			printf("%d\n", c);
		}
		if(i > 1)
			printf("\n");
	}
	return 0;
}