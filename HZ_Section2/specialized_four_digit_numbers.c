#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	int i, t1, t2, t3;

	int a, b;
	for(i = 1000; i <= 9999; i++)
	{
		b = i;
		t1 = t2 = t3 = 0;

		while((b/10) != 0)
		{	
			a = b%10;
			t3 += a;
			b = b/10;
		}
		t3 += b;

		b = i;
		while((b/12) != 0)
		{	
			a = b%12;
			t1 += a;
			b = b/12;
		}
		t1 += b;
		if(t3 != t1)
		{
			continue;
		}

		b = i;
		while((b/16) != 0)
		{	
			a = b%16;
			t2 += a;
			b = b/16;
		}
		t2 += b;

		if(t1 == t2)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}