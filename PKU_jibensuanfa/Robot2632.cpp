#include <stdio.h>
#include <string.h>
typedef struct Robot
{
	int x;
	int y;
	char ore;
}Robot;

typedef struct Cmd
{
	int num;
	char c;
	int step;
}Cmd;
bool ware[100][100];
bool f;
Robot robot[100];
Cmd cmd;
int index1, index2, ix, iy;
int k, a, b, n, m;
char oreL[4] = {'W', 'S', 'E', 'N'};
char oreR[4] = {'W', 'N', 'E', 'S'};
void Init()
{
	int i, j;
	int x, y;
	for(i = 0; i < a; i++)
	{
		for(j = 0; j < b; j++)
		{
			ware[i][j] = false;
		}
	}
	for(i = 0; i < n; i++)
	{
		x = robot[i].x;
		y = robot[i].y;
		ware[x][y] = true;
	}
}

void DoCmd()
{
	if(f)
		return;
	int i, j;
	int x, y;
	int num = cmd.num;
	char c = cmd.c;
	switch(c)
	{
		case 'L':
			j = 0;
			while(1)
			{
				if(robot[num].ore == oreL[j])
					break;
				j++;
			}
			i = cmd.step%4;
			if(i+j > 4) robot[num].ore = oreL[j+i-4];
			else if(i+j < 4) robot[num].ore = oreL[i+j];
			else;
			printf("ore: %c\n", robot[num].ore);
			break;
		case 'R':
			j = 0;
			while(1)
			{
				if(robot[num].ore == oreR[j])
					break;
				j++;
			}
			i = cmd.step%4;
			if(i+j > 4) robot[num].ore = oreR[j+i-4];
			else if(i+j < 4) robot[num].ore = oreR[i+j];
			else;
			break;
		case 'F':
			x = robot[num].x;
			y = robot[num].y;
			for(i = 0; i < cmd.step; i++)
			{
				printf("x: %d\n", x);
				printf("y: %d\n", y);
				switch(robot[num].ore)
				{
					case 'W':
						if(x-1 >= 0 && !ware[x-1][y])
						{
							x = x-1;
							ware[x][y] = true;
						}
						else
						{
							if(!ware[x-1][y])	x--;
							f = true;
							break;
						}
						break;
					case 'E':
						if(x+1 < a && !ware[x+1][y])
						{
							x = x+1;
							ware[x][y] = true;
						}
						else
						{
							// printf("test\n");
							if(!ware[x+1][y]) x++;
							f = true;
							break;
						}
						break;
					case 'S':
						if(y+1 < b && !ware[x][y+1])
						{
							y = y+1;
							ware[x][y] = true;
						}
						else
						{
							if(!ware[x][y+1]) y++;
							f = true;
							break;
						}
						break;
					case 'N':
						if(y-1 >= 0 && !ware[x][y-1])
						{

							y = y-1;
							ware[x][y] = true;
						}
						else
						{
							if(!ware[x][y-1]) y--;
							f = true;
							break;
						}
						break;
				}
				if(f)
					break;
			}
			break;
	}
	index1 = num;
	robot[num].x = x;
	robot[num].y = y;
	ix = x;
	iy = y;
}

int main(int argc, char const *argv[])
{
	/* code */
	int i;
	int j;
	int x, y;

	char c;
	scanf("%d", &k);
	while(k-- > 0)
	{
		f = false;
		scanf("%d%d%d%d", &a, &b, &n, &m);
		for(i = 0; i < n; i++)
		{	
			scanf("%d%d", &robot[i].x, &robot[i].y);
			robot[i].x = robot[i].x - 1;
			robot[i].y = 4 - robot[i].y;
			c = getchar();
			while(c == ' ' || c == '\n')
				c = getchar();

			robot[i].ore = c;
			// printf("%d %d ", robot[i].x, robot[i].y);
			// printf("%c\n", robot[i].ore);
		}

		Init();
		for(i = 0; i < m; i++)
		{
			scanf("%d", &cmd.num);
			cmd.num = cmd.num - 1;
			c = getchar();
			while(c == ' ' || c == '\n')
				c = getchar();
			cmd.c = c;
			scanf("%d", &cmd.step);

			// printf("%d\n", cmd.num);
			DoCmd();
		}

		if(f)
		{
			if(ix > a || iy > b)
				printf("Robot %d crashes into the wall\n", index1+1);
			else
			{
				for(j = 0; j < n; j++)
				{
					if(robot[j].x == ix && robot[j].y == iy)
					{
						index2 = j;
						break;
					}
				}
				printf("Robot %d crashes into robot %d\n", index1+1, index2+1);
			}
		}
		else 
		{
			printf("OK\n");
		}
		// printf("%d %c %d\n", cmd.num, cmd.c, cmd.step);

	}
	return 0;
}