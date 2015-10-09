#include <stdio.h>
/*the edge is bidirection!!!*/
#define NF 10001
typedef struct 
{
	/* data */
	int u;
	int v;
	int w;
}Edge;

Edge edge[6000];
int dis[1000];
int F, N, M, W;

bool bellman()
{
	int i;
	int j;
	dis[1] = 0;
	for(i = 2; i <= N; i++)
	{
		dis[i] = NF;
	}
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			if(dis[edge[j].v] > dis[edge[j].u]+edge[j].w)
			{
				dis[edge[j].v] = dis[edge[j].u]+edge[j].w;
			}
			if(dis[edge[j].u] > dis[edge[j].v]+edge[j].w)
			{
				dis[edge[j].u] = dis[edge[j].v]+edge[j].w;
			}
		}
		for(; j < M+W; j++)
		{
			if(dis[edge[j].v] > dis[edge[j].u]+edge[j].w)
			{
				dis[edge[j].v] = dis[edge[j].u]+edge[j].w;
			}
		}
	}

		for(j = 0; j < M; j++)
		{
			if(dis[edge[j].v] > dis[edge[j].u]+edge[j].w)
			{
				return true;
			}
			if(dis[edge[j].u] > dis[edge[j].v]+edge[j].w)
			{
				return true;
			}
		}
		for(; j < M+W; j++)
		{
			if(dis[edge[j].v] > dis[edge[j].u]+edge[j].w)
			{
				return true;
			}
		}
	return false;
}

int main(int argc, char const *argv[])
{
	/* code */
	int i;
	int j;
	scanf("%d", &F);
	for(i = 0; i < F; i++)
	{
		scanf("%d%d%d", &N, &M, &W);
		for(j = 0; j < M; j++)
		{
			scanf("%d%d%d", &edge[j].u , &edge[j].v, & edge[j].w);
		}
		for(; j < M+W; j++)
		{
			scanf("%d%d%d", &edge[j].u, &edge[j].v, &edge[j].w);
			edge[j].w = -edge[j].w;
		}
		if(bellman())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}

		// int t;
		// for(t = 1; t <= N; t++)
		// {
		// 	printf("%d\n", dis[t]);
		// }

	}
	return 0;
}