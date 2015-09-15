#include <stdio.h>

int adjust(int a[], int f, int e)
{
	int v = a[f];
	int i = f;
	int j = e;
	while(i < j)
	{
		while(i < j && a[j] < v)
			j--;
		if(i < j)
		{
			a[i] = a[j];
			i++;
		}
		else
			break;

		while(i < j && a[i] > v)
			i++;
		if(i < j)
		{
			a[j] = a[i];
			j--;
		}
		else
			break;
	}

	a[i] = v;
	return i;
}

void quickrank(int a[], int f, int e)
{
	if(f >= e)
		return;
	int i = adjust(a, f, e);
	quickrank(a, f, i-1);
	quickrank(a, i+1, e);
	return;
}

int main(int argc, char const *argv[])
{
	/* code */
	int plus;
	int minus ;

	int m;
	int t[1000];
	int k[1000];

	scanf("%d", &m);
	int f1,f2;
	int e1,e2;
	int i;
	while(0 != m)
	{
		plus = minus = 0;
		for(i = 0; i < m; i++)
		{	
			scanf("%d", &t[i]);
		}	
		for(i = 0 ; i < m ;i++)
		{
			scanf("%d", &k[i]);
		}

		quickrank(t, 0, m-1);
		quickrank(k, 0, m-1);

		f1 = f2 = 0;
		e1 = e2 = m-1;
		while(f1 <= e1 && f2 <= e2)
		{
			if(t[f1] > k[f2])
			{
				plus++;
				f2++;
				f1++;
			}
			else if(t[f1] < k[f2])
			{
				e1--;
				f2++;
				minus++;
			}
			else
			{
				if(t[e1] > k[e2])
				{
					plus++;
					e1--;
					e2--;
				}
				else if(t[e1] == k[f2])
				{
					e1--;
					f2++;
				}
				else
				{
					minus++;
					e1--;
					f2++;
				}
			}
		}

		printf("%d\n", 200*plus-200*minus); 
		scanf("%d", &m);
	}
	return 0;
}