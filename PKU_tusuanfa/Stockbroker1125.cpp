#include <stdio.h>
#define NF 999

int graph[101][101];
int n;
int m;
int min;
int s;
void floyd()
{
	int k, i ,j;
	for(k = 0; k < n; k++)
	{
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				if(graph[i][j] > graph[i][k]+graph[k][j])
					graph[i][j] = graph[i][k]+graph[k][j];
			}
		}
	}

	// for(i = 0; i < n; i++)
	// {
	// 	for(j = 0; j < n ; j++)
	// 	{
	// 		printf("%d ", graph[i][j]);
	// 	}
	// 	printf("\n");
	// }
}

void FindMin()
{
	int i;
	int j;
	int tmp;
	min = NF;
	for(i = 0; i < n; i++)
	{
		tmp = -1;
		for(j = 0; j < n; j++)
		{
			if(graph[i][j] > tmp)
			{
				tmp = graph[i][j];
			}
		}
		if(min > tmp)
		{
			min = tmp;
			s = i;
		}
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	int i;
	int j;
	int t;
	while(scanf("%d", &n) && n)
	{
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				graph[i][j] = NF;
				if(i == j)
					graph[i][j] = 0;
			}
		}

		for(i = 0; i < n; i++)
		{
			scanf("%d", &m);
			for(j = 0; j < m; j++)
			{
				scanf("%d", &t);
				t--;
				// printf("t: %d\n", t);
				scanf("%d", &graph[i][t]);
			}
		}
		floyd();
		FindMin();
		if(min >= NF)
			printf("disjoint\n");
		else
			printf("%d %d\n", s+1, min);
	}
	return 0;
}