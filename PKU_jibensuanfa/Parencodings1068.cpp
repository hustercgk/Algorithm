#include <stdio.h>

typedef struct pare
{
	char c;
	bool b;
}Pare;

int a[21];
int p;
int b[1024];
int q = 0;

Pare pa[1024];
void make(int n)
{
	int i;
	int t;
	for(i = 1, p = 0; i < n+1; i++)
	{
		t = a[i] - a[i-1];
		while(t-- > 0)
		{
			pa[p].c = '(';
			pa[p].b = false;
			p++;
		}
		pa[p].c = ')';
		pa[p].b = false;
		p++;
	}
}

void result()
{
	int i;
	int t;
	int num;
	for(i = 0; i < p; i++)
	{
		if(pa[i].c == '(')
		{
			continue;
		}
		num = 0;
		t = i;
		while(t-- > 0)
		{
			if(pa[t].b && pa[t].c == '(')
			{
				num++;
			}
			if(!pa[t].b && pa[t].c == '(')
			{
				pa[t].b = true;
				b[q++] = num+1;
				break;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int t, n;
	int i;
	scanf("%d", &t);
	while(t-- > 0)
	{	
		q = p = 0;
		scanf("%d", &n);
		for(i = 1; i < n+1; i++)
		{
			scanf("%d", &a[i]);
		}
		make(n);
		result();
		for(i = 0; i < q; i++)
		{
			printf("%d ", b[i]);
		}
		printf("\n");
	}
	return 0;
}