#include <stdio.h>
int main(int argc, char const *argv[])
{
	/* code */
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF)
	{
		printf("%d\n", a+b);
		printf("\n");
	}
	return 0;
}