#include <stdio.h>
#include <math.h>

#define NF 9999999
typedef struct 
{
	int x;
	int y;
	bool flag;
}Point;

typedef struct 
{
	int u;
	int v;
	double dis;
}Edge;
Point point[201];
Edge edge[201];

int n;
double graph[201][201];
double primdis[201];

int ct;

void distance()
{
	int i, j;
	double x2, y2;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i == j)
			{
				graph[i][j] = NF;
				continue;
			}
			x2 = (double)((point[i].x - point[j].x)*(point[i].x - point[j].x));
			y2 = (double)((point[i].y - point[j].y)*(point[i].y - point[j].y));
			graph[i][j] = sqrt(x2+y2);
		}
	}
}

void prim()
{
	int i, j;
	point[0].flag = true;
	int index = 0;
	for(i = 0; i < n; i++)
	{
		dis = NF;
		if(now == 1) break;
		for(j = 0; j < n; j++)
		{

		}
	}
}

double findmin()
{
	int i;
	double tmp = 0;
	for(i = 0; i < ct; i++)
	{
		// printf("%.3lf\n", primdis[i]);
		if(tmp < primdis[i])
			tmp = primdis[i];
	}
	if(tmp > graph[0][1])
		tmp = graph[0][1];
	return tmp;
}

int main(int argc, char const *argv[])
{
	/* code */
	int i, j;
	int count = 1;
	while(scanf("%d", &n) && n != 0 && n >= 2)
	{
		ct = 0;
		// mindis = NF;
		for(i = 0; i < n; i++)
		{
			scanf("%d%d", &point[i].x, &point[i].y);
			point[i].flag = false;
		}
		distance();	
		prim();
		printf("Scenario #%d\n", count);
		count++;
		printf("Frog Distance = %.3lf\n", findmin());
		printf("\n");

	}
	return 0;
}