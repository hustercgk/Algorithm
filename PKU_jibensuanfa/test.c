#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	int temp[100] = {8};
	// memset(temp, 'c', sizeof(temp));
	int i;
	for(i = 0; i < 100; i++)
		printf("%d ", temp[i]);

	printf("\n");
	return 0;
}