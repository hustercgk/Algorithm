#include <stdio.h>
#include <string.h>

bool stack[101];
bool flag;
char str[101];
int map[26];
char szc[5] = {'p', 'q', 'r', 's', 't'};

void check(int p, int n)
{
	int i;
	int j;
	int top = 0;
	char c;
	for(i = n-1; i >= 0; i--)
	{
		c = str[i];
		if(c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't')
		{
			j = map[c-'a'];
			// printf("c:%c\n", c);
			// printf("j: %d\n", j);
			stack[top++] = ((p >> j) & 1);
			// printf("%d\n", stack[top-1]);
		}
		else
		{
			top--;
			if(c == 'K')
			{
				stack[top-1] = (stack[top] & stack[top-1]);
			}
			else if(c == 'A')
			{
				stack[top-1] = (stack[top] | stack[top-1]);
			}	
			else if(c == 'N')
			{
				stack[top] = !stack[top];
				top++;
			}
			else if(c == 'C')
			{
				stack[top-1] = ((!stack[top-1]) | stack[top]);
			} 
			else
			{
				// printf("else: %c\n", c);
				stack[top-1] = (stack[top] == stack[top-1]);
			}
		}
	}
	if(!stack[top-1])
	{
		flag = true;
	}

	return ;
}

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	int i;
	for(i = 0; i < 5; i++)
	{
		map[szc[i]-'a'] = i;
	}

	while(scanf("%s", str) && str[0] != '0')
	{	
		flag = false;
		n = strlen(str);
		// printf("%c\n", str[n]);
		for(i = 0; i < 32; i++)
		{
			check(i, n);
			if(flag)
				break;

		}
		if(!flag)
		{
			printf("tautology\n");
		}
		else
		{
			printf("not\n");
		}
	}
	return 0;
}