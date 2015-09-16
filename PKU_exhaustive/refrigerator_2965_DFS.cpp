#include <stdio.h>
/* + == 1; - == 0*/

int handle = 0;
bool isfind = false;
int op[16][2];
int count = 0;
int min_count = 16;
int t = 0;
int j;
int f[] = { 63624, 62532, 61986, 61713, 36744, 20292, 12066, 7953, 35064, 17652, 
	8946, 4593, 34959, 17487, 8751, 4383 };
// int f[] = {4383, 8751, 17487, 34959, 4593, 8946, 17652, 35064, 7953, 
// 	12066, 20292, 36744, 61713, 61986, 62532, 63624};

void output()
{
	int i;
	printf("%d\n", min_count);
	for(i = 0; i < min_count; i++)
	{
		printf("%d %d\n",op[i][0], op[i][1]);
	}
}

void DFS(int handle, int dep)
{	
	//t++;
	if(handle == 0)
	{
		if(min_count >= count)
		{
			min_count = count;
			j = t;
			return;
		}
	}
	if(16 == dep)
	{
		return;
	}

	int temp = handle;
	handle ^= f[dep];
	t += 1<<dep;
	count++;
	DFS(handle, dep+1);

	count--;
	t -= 1<<dep;
	DFS(temp, dep+1);

	return;
	
}

int main(int argc, char const *argv[])
{
	/* code */	
	int i= 0;
	char c;
	while(1)
	{
		if(i >= 16)
			break;

		c = getchar();
		if(c == '+')
		{
			handle = (handle<<1) ^ 1;
			i++;
		}
		else if(c == '-')
		{
			handle = handle<<1;
			i++;
		}
		else
		{
			continue;
		}
	}

	DFS(handle, 0);
	int k = 0;
	while(j)
	{
		if(j & 1)//turn when bit of j is equal 1
		{
			op[count][0] = (k)/4 + 1;
		    op[count][1] = (k)%4 + 1;
			count++;
		}
		j = j >> 1;
		k++;
	}

	output();
	return 0;
}