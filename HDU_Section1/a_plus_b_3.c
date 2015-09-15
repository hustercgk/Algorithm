#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	int a, b, c;
	c = 0;
	while(1)
	{
		scanf("%d", &a);
		if(a != 0)
		{
			for(b = a; b > 0; b--)
			{
				scanf("%d", &a);
				c = c + a;
			}
			printf("%d\n", c);
			c = 0;
		}
		else
		{
			break;
		}
	}
	return 0;
}