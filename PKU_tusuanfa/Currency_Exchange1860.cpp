#include <stdio.h>

typedef struct Point
{
	/* data */
	int f;
	int e;
	double rfe;
	double cfe;
	double ref;
	double cef;
}Point;

Point point[101];
double value[101];
int N, M, S;
double V;
int flag = 0;
int main(int argc, char const *argv[])
{	
	/* code */
	scanf("%d%d%d%lf", &N, &M, &S, &V);
	int i;
	int j;
	for(i = 1; i <= M; i++)
	{
		scanf("%d%d%lf%lf%lf%lf", &point[i].f, &point[i].e, 
			&point[i].rfe, &point[i].cfe, &point[i].ref, 
			&point[i].cef);
	}

	value[S] = V;
	for(i = 1; i <= N; i++)
	{
		for(j = 1; j <= M; j++)
		{
			int f = point[j].f;
			int e = point[j].e;
			double v = (value[f]-point[j].cfe)*point[j].rfe;
			if(v > value[e]) value[e] = v;
			v = (value[e]-point[j].cef)*point[j].ref;
			if(v > value[f]) value[f] = v;
		}

		if(value[S] > V)
		{
			flag = 1;
			break;
		}
	}

	/*if value[S] is not bigger than V, it may esxit a + loop, it can loop many many times 
	until it is bigger than V*/
	if(flag == 0)
	{
		for(j = 1; j <= M; j++)
		{
			int f = point[j].f;
			int e = point[j].e;
			double v = (value[f]-point[j].cfe)*point[j].rfe;
			if(v > value[e])
			{
				flag = 1;
				break;
			}
			v = (value[e]-point[j].cef)*point[j].ref;
			if(v > value[f]) 
			{
				flag = 1;
				break;
			}
		}
	}

	if(flag == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}