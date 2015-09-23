#include <stdio.h>
/* + == 1; - == 0*/

int handle = 0;
bool isfind = false;
int op[16][2];
int count = 0;
int min_count = 16;

// int f[] = { 63624, 62532, 61986, 61713, 36744, 20292, 12066, 7953, 35064, 17652, 
// 	8946, 4593, 34959, 17487, 8751, 4383 };
int f[] = {4383, 8751, 17487, 34959, 4593, 8946, 17652, 35064, 7953, 
	12066, 20292, 36744, 61713, 61986, 62532, 63624};

void output()
{
	int i;
	printf("%d\n", min_count);
	for(i = 0; i < min_count; i++)
	{
		printf("%d %d\n",op[i][0], op[i][1]);
	}
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

	//printf("handle: %d\n", handle);
	// if(handle == 0)//first check;
	// {
	// 	printf("0\n");
	// 	return 0;
	// }

	count = 0;
	int j;
	int k;
	int temp;
	int m = 0;
	temp = handle;
	for(i = 0; i < 65536; i++)//must be 65536,why?...because 0~65535 has 65536 possibility
	{	
		count = 0;
		j = i;
		k = 0;
		while(j)
		{
			if(j & 1)//turn when bit of j is equal 1
			{
				handle = handle ^ f[k];	
				// op[count][0] = (15-k)/4 + 1;
				// op[count][1] = (15-k)%4 + 1;//can't not place op here!!! it will be rewirted
				count++;
			}
			j = j >> 1;
			k++;
		}

		if(handle == 0)
		{
			//printf("handle: %d\n", handle);

			if(min_count >= count)
			{	
				min_count = count;
				m = i;
				//printf("i: %d\n", i);
			}
			
		}
		handle = temp;
	}

	j = m;
	k = 0;
	count = 0;
	//printf("j:%d\n", j);
	while(j)
	{
		if(j & 1)//turn when bit of j is equal 1
		{
			op[count][0] = (15-k)/4 + 1;
		    op[count][1] = (15-k)%4 + 1;
			count++;
		}
		j = j >> 1;
		k++;
	}

	output();
	return 0;
}