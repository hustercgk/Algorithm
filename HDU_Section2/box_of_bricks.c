#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	/* code */
	int m,c;
	int t;
	int a;
	int i = 0;
	int *p = NULL;

	c = 0;
	while(1)
	{
		scanf("%d", &m);
		p = (int*)malloc(sizeof(int)*m);

		if(0 == m)
		{
			break;
		}

		c++;
		t = 0;
		for(i=0; i < m; i++)
		{
			scanf("%d", &p[i]);
			t = t + p[i];
		}

		a = t/m;
		t = 0;

		for(i=0; i < m; i++)
		{
			if(p[i] > a)
			{
				t = t + p[i]- a;
			}
		}
		free(p);
		printf("Set #%d\n", c);
		printf("The minimum number of moves is %d.\n", t);
		printf("\n");
	}

	return 0;
}