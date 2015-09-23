/*wrong !!!*/
#include <stdio.h>
#include <string.h>
bool stack[101];
char str[101];
bool flag = false;
bool a[5];
int top;
void DFS(int t)
{
	
	if(flag)
	{
		// printf("test\n");
		return;
	}

	if(t < 0)
	{
		return;
	}

	int tmp = top;
	if(str[t] == 'p')
	{
		stack[top++] = false;
		DFS(t-1);
		top = tmp;
		stack[top++] = true;
		DFS(t-1);
	}
	else if(str[t] == 'q')
	{
		stack[top++] = false;
		DFS(t-1);
		top = tmp;
		stack[top++] = true;
		DFS(t-1);
	}
	else if(str[t] == 'r')
	{
		stack[top++] = false;
		DFS(t-1);
		top = tmp;
		stack[top++] = true;
		DFS(t-1);
	}
	else if(str[t] == 's')
	{
		stack[top++] = false;
		DFS(t-1);
		top = tmp;
		stack[top++] = true;
		DFS(t-1);
	}
	else if(str[t] == 't')
	{
		stack[top++] = false;
		DFS(t-1);
		top = tmp;
		stack[top++] = true;
		DFS(t-1);
	}
	// if(str[t] == 'p' || str[t] == 'q' || str[t] == 'r' || 
	// 	str[t] == 's' || str[t] == 't')
	// {
	// 		stack[top++] = false;
	// 		DFS(t-1);
	// 		top = tmp;
	// 		stack[top++] = true;
	// 		DFS(t-1);
	// }
	else
	{
		top--;
		if(str[t] == 'K')
		{
			stack[top-1] = (stack[top] & stack[top-1]);
		}
		else if(str[t] == 'A')
		{
			stack[top-1] = (stack[top] | stack[top-1]);
		}	
		else if(str[t] == 'N')
		{
			stack[top] = !stack[top];
			top++;
		}
		else if(str[t] == 'C')
		{
			stack[top-1] = ((!stack[top-1]) | stack[top]);
		} 
		else
		{
			stack[top-1] = (stack[top] == stack[top-1]);
		}

		if(top == 1 && !stack[top-1])
		{
			flag = true;
		}
		DFS(t-1);
	}

	return;
}
int main(int argc, char const *argv[])
{
	/* code */
	int n;
	memset(str, 0, 101);
	int i;
	while(scanf("%s", str) && str[0] != '0')
	{	
		for(i = 0; i < 5; i++)
		{
			a[i] = false;
		}
		flag = false;
		top = 0;
		n = strlen(str);
		DFS(n-1);
		// printf("%c\n", str[n-1]);
		if(!flag)
		{
			printf("tautology\n");
		}
		else
		{
			printf("not\n");
		}
		memset(str, 0, 101);
	}
	return 0;
}