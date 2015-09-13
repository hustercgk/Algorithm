#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	int m;
	char op;
	int a, b;

	scanf("%d", &m);

	int i;
	for(i = 0; i < m; i++)
	{
		op = getchar();
		while(op == ' ' || op == '\n')
			op = getchar();

		scanf("%d%d", &a, &b);
		switch(op)
		{
			case '+':
				printf("%d\n", a+b);
				break;
			case '-':
				printf("%d\n", a-b);
				break;
			case '*':
				printf("%d\n", a*b);
				break;
			case '/':
				/*wrong in this place*/
				if(a%b == 0)//need to consider the integer..
				{
					printf("%d\n", a/b);
				}
				else
				{
					printf("%.2f\n", ((float)a)/((float)b));
				}
				break;
		}
	}
	return 0;
}