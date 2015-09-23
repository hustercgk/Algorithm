#include <cstdio>

using namespace std;

const int N = 105;

struct rob
{
	int x, y, d;
}rob[N];

struct move
{
	int id, tap, times;
}ms[N];

int on[N][N];
int t, m, n, nums, moves;

void input()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			on[i][j] = 0;
	char c;
	scanf("%d %d", &nums, &moves);
	for (int i = 1; i <= nums; ++i)
	{
		scanf("%d %d %c", &rob[i].y, &rob[i].x, &c);
		on[rob[i].x][rob[i].y] = i;
		switch(c)
		{
			case 'S':rob[i].d = 0;break;
			case 'E':rob[i].d = 1;break;
			case 'N':rob[i].d = 2;break;
			case 'W':rob[i].d = 3;break;
		}
	}
	for (int i = 1; i <= moves; ++i)
	{
		scanf("%d %c %d", &ms[i].id, &c, &ms[i].times);
		switch(c)
		{
			case 'L':ms[i].tap = 1;break;
			case 'R':ms[i].tap = 2;break;
			case 'F':ms[i].tap = 3;break;
		}
	}
}

void output(int one, int two, int w)
{
	if (w == 1)
		printf("Robot %d crashes into the wall\n", one);
	else
		printf("Robot %d crashes into robot %d\n", one, two);
}

bool move(int id, int inx, int iny, int times)
{
	int x = rob[id].x;
	int y = rob[id].y;
	on[x][y] = 0;
	for (int i = 0; i < times; ++i)
	{
		x += inx;
		y += iny;
		if (x < 1 || x > n || y < 1 || y > m)
		{
			output(id, 0, 1);
			return false;
		}
		if (on[x][y] != 0)
		{
			output(id, on[x][y], 2);
			return false;
		}
	}
	on[x][y] = id;
	rob[id].x = x;
	rob[id].y = y;
	return true;
}

bool change(int id, int tap, int times)
{
	switch(tap)
	{
		case 1:rob[id].d = (rob[id].d + times) % 4;break;
		case 2:rob[id].d = (rob[id].d + 3 * times) % 4;break;
		case 3:
			switch(rob[id].d)
			{
				case 0:
					if (!move(id, -1,  0, times))
						return false;
					break;
				case 1:
					if (!move(id,  0,  1, times))
						return false;
					break;
				case 2:
					if (!move(id,  1,  0, times))
						return false;
					break;
				case 3:
					if (!move(id,  0, -1, times))
						return false;
					break;
			}
			break;
	}
	return true;
}

void solve()
{
	for (int i = 1; i <= moves; ++i)
		if (!change(ms[i].id, ms[i].tap, ms[i].times))
			return;
	puts("OK");
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		input();
		solve();
	}
	return 0;
}
