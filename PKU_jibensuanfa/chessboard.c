#include <stdio.h>
#include <string.h>
/*# = 1, . = 0*/
bool checkboard[8][8];
int n, k;
int m;

void exchange(bool temp1[8][8], bool temp2[8][8], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			temp1[i][j] = temp2[i][j];
		}
	}
}

void putcheck(int t, int dep)
{
	if(t >= k)
	{
		m++;
		return;
	}

	int i, j;
	for(i = dep; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			bool temp[8][8];
			if(checkboard[i][j])
			{	
				exchange(temp, checkboard, n);
				int k;
				for(k = i+1; k < n; k++)
				{
					if(checkboard[k][j]) checkboard[k][j] = false;
				}
				putcheck(t+1, dep+1);
			}
			exchange(checkboard, temp, n);
		}
	}

}
int main(int argc, char const *argv[])
{
	/* code */
	int i;
	int j;
	int count;
	char c;
	scanf("%d%d", &n, &k);
	while(n != -1 && k != -1)
	{
		i = 0;
		j = 0;
		count = 0;
		while(1)
		{
			if(count > n*n-1)
			{
				break;
			}

			c = getchar();
			if(c == '#')
			{
				checkboard[i][j] = true;
				if(j >= n)
				{
					j = 0;
					i++;
				}
				else
				{
					j++;
				}
				count++;
			}
			else if(c == '.')
			{
				checkboard[i][j] = false;
				if(j >= n)
				{
					j = 0;
					i++;
				}
				else
				{
					j++;
				}
				count++;
			}
			else
			{
				continue;
			}
		}
		
		putcheck(0, 0);
		printf("%d\n", m);
		scanf("%d%d", &n, &k);
	}

	return 0;
}