#include <stdio.h>
int main(int argc, char const *argv[])
{
	/* code */
	int n, u, d;
	int det, s, t;
	scanf("%d%d%d", &n, &u, &d);

	while(n != 0)
	{
		det = u - d;
		s = n - u;//from 0!!!!not 1
		if(s%det != 0)
		{
			t = (s/det+1)*2 + 1;
		}
		else
		{
			t = (s/det)*2 + 1;
		}
		printf("%d\n", t);
		scanf("%d%d%d", &n, &u, &d);
	}
	return 0;
}