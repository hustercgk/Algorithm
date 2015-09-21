#include <stdio.h>
#include <string.h>
#define MAX 8
int queen[MAX];
int count;
int t = 0;
bool check()
{
	int i, j;
	bool flag = true;
	for(i = 0; i < t; i++)
	{
		for(j = i+1; j < t; j++)
		{
			if(queen[i] == queen[j] || j - i == queen[i]-queen[j] || j - i == queen[j] - queen[i])
			{
				flag = false;
				break;
			}
		}
		if(!flag)
		{
			break;
		}
	}
	return flag;
}

void putqueen(int row)
{

	if(row >= MAX)
	{
		count++;
		return;
	}

	int i;
	for(i = 0; i < MAX; i++)
	{	
		queen[row] = i;
		t++;
		if(check())
		{
			putqueen(row+1);	
		}
		t--;

	}
	return;
}
int main(int argc, char const *argv[])
{
	/*code */
	int i;
	for(i = 0; i < MAX; i++) 
		queen[i] = 8;
	putqueen(0);
	printf("%d\n", count);
	return 0;
}