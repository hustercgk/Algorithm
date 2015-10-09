#include <stdio.h>
#include <string.h>
/*to kengdie!!! notice the axi changes, notice the ware need to be false noce the robot out of it position, 
	notice how to update the W, S, E, N*/
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
bool ware[200][200];
bool f_out;
bool f_copy;
bool f;
Robot robot[200];
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
	return;
}

void DoCmd()
{
	if(f_copy || f_out)
		return;
	int i, j;
	int x, y;
	int num = cmd.num;
	char c = cmd.c;
	// printf("num: %d\n", num);
	// printf("robot_x: %d\n", robot[num].x);
	// printf("robot_y: %d\n", robot[num].y);

	f = false;
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
			if(i+j >= 4) robot[num].ore = oreL[j+i-4];
			else if(i+j < 4) robot[num].ore = oreL[i+j];
			else;
			f = true;
			// printf("ore: %c\n", robot[num].ore);
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
			if(i+j >= 4) robot[num].ore = oreR[j+i-4];
			else if(i+j < 4) robot[num].ore = oreR[i+j];
			else;
			f = true;
			// printf("ore: %c\n", robot[num].ore);

			break;
		case 'F':
			x = robot[num].x;
			y = robot[num].y;
			for(i = 0; i < cmd.step; i++)
			{
				
				switch(robot[num].ore)
				{
					case 'W':
						if(x-1 >= 0)
						{	
							if(!ware[x-1][y])
							{	
								ware[x-1][y] = true;
								ware[x][y] = false;
							}
							else
							{
								f_copy = true;
							}
						}
						else
						{
							f_out = true;
						}
						x = x-1;
						break;
					case 'E':
						if(x+1 < a)
						{
							if(!ware[x+1][y])
							{
								ware[x+1][y] = true;
								ware[x][y] = false;
							}
							else
							{
								f_copy = true;
							}
						}
						else
						{
							f_out = true;
						}
						x = x+1;
						break;
					case 'S':
						if(y+1 < b)
						{
							if(!ware[x][y+1])
							{
								ware[x][y+1] = true;
								ware[x][y] = false;
							}
							else
							{
								f_copy = true;
							}
						}
						else
						{
							f_out = true;
						}
						y = y+1;
						break;
					case 'N':
						if(y-1 >= 0)
						{
							// printf("y-1: %d\n", y-1);
							if(!ware[x][y-1])
							{
								ware[x][y-1] = true;
								ware[x][y] = false;
							}
							else
							{
								f_copy = true;
							}
						}
						else
						{
							f_out = true;
						}
						y = y-1;
						break; 
				}
				// printf("x: %d\n", x);
				// printf("y: %d\n", y);
				// printf("num: %d\n", num);
				if(f_copy | f_out)
					break;
			}
			break;
	}
	if(!f)
	{
		index1 = num;
		robot[num].x = x;
		robot[num].y = y;
		ix = x;
		iy = y;
	}
	return;

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
		f_copy = false;
		f_out = false;
		scanf("%d%d%d%d", &a, &b, &n, &m);
		for(i = 0; i < n; i++)
		{	
			scanf("%d%d", &robot[i].x, &robot[i].y);
			robot[i].x = robot[i].x - 1;
			robot[i].y = b - robot[i].y;//use b ,not 4!!!
			c = getchar();
			while(c == ' ' || c == '\n')
				c = getchar();

			robot[i].ore = c;
			// printf("init x, y:%d %d ", robot[i].x, robot[i].y);
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

			// printf("cmd: %d\n", cmd.step);
			DoCmd();
		}

		if(f_out)
		{
			printf("Robot %d crashes into the wall\n", index1+1);
		}

		else if(f_copy)
		{
			index2 = 0;
			for(j = 0; j < n; j++)
			{
				if(robot[j].x == ix && robot[j].y == iy && index1 != j)
				{
					index2 = j;
					break;
				}
			}
			printf("Robot %d crashes into robot %d\n", index1+1, index2+1);
		}
		else 
		{
			printf("OK\n");
		}
		// printf("%d %c %d\n", cmd.num, cmd.c, cmd.step);

	}
	return 0;
}