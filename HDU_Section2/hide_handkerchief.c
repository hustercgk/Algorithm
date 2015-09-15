#include <stdio.h>

int gcd(int a, int b)
{
	int r = a%b;
	if(r == 0)
		return b;
	else
		gcd(b, r);
}
int main(int argc, char const *argv[])
{
	/* code */
	int n, m;
	int r;
	scanf("%d%d", &n, &m);
	while(n != -1 && m != -1)
	{
		r = gcd(n, m);
		if(1 == r)
		{
			printf("YES\n");
		}
		else
		{
			printf("POOR Haha\n");
		}
		scanf("%d%d", &n, &m);
	}

	return 0;
}