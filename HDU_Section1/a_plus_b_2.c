#include <stdio.h>
int main(int argc, char const *argv[])
{
	/* code */
	int a, b, c;
	while(scanf("%d%d", &a, &b) != EOF)
	{
		c = a+b;
		if(c != 0)
		{
			printf("%d\n", c);
		}
	}
	return 0;
}