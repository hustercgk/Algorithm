#include <stdio.h>

char point[2001][8];
int graph[2001][2001];
int n;

void MakeGraph()
{
	int i, j;
	int t;
	int tmp;
	for(i = 1; i < n; i++)
	{	
		tmp = 0;
		for(j = i+1; j < n; j++)
		{
			for(t = 0; t < 7; t++)
			{
				tmp += abs(point[i][t]-point[j][t]);
			}
			graph[i][j] = graph[j][i] = tmp;
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	while(scanf("%d", &n) && n)
	{
		int i;
		getchar();
		for(i = 0; i < n; i++)
		{
			gets(point[i]);
		}

		for(i = 0; i < n; i++)
		{
			printf("%s\n", point[i]);
		}

	}
	return 0;
}