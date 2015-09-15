#include <stdio.h>
int main(int argc, char const *argv[])
{
	/* code */
	int a, b[101], i;
	int down, up;
	while(1)
	{
		scanf("%d", &a);
		down = 0;
		up = 0;

		if(a == 0)
		{
			break;
		}
		else
		{	
			scanf("%d", &b[0]);
			for(i = 1; i < a; i++)
			{
				scanf("%d", &b[i]);
				if(b[i-1] > b[i])
				{
					down = down+b[i-1]-b[i];
				}
				else
				{
					up = up+b[i]-b[i-1];
				}
			}
		}

		a = down*4 + (up+b[0])*6 + 5*a;
		printf("%d\n", a);
	}
	return 0;
}