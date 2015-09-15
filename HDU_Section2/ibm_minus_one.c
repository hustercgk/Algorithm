#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	/* code */
	char s[51];
	int m;
	scanf("%d", &m);
	while(getchar() != '\n')
		;
	int i;
	int len;

	for(i = 0; i < m; i++)
	{
		gets(s);
		len = strlen(s);

		while(--len >= 0)
		{
			if(s[len] == 'Z')//need to consider Z!!!
			{
				s[len] = 'A';
			}
			else
			{
				s[len] += 1;
			}
		}

		printf("String #%d\n", i+1);
		printf("%s\n", s);
		printf("\n");
		
	}
	return 0;
}