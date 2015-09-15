#include <stdio.h>
#include <string.h>
typedef struct Student
{
	/* data */
	char name[21];
	int m;
	int p[10];
	int score;
}Student;

int G;
int insertrank(Student stu[], int m)
{
	int i;
	int j;
	int t = 0;
	Student tmp;
	if(stu[0].score >= G)
		t++;
	for(i = 1; i < m; i++)
	{
		tmp = stu[i];
		if(tmp.score >= G)
			t++;
		for(j = i - 1; j >= 0 ; j--)
		{
			if(tmp.score > stu[j].score)
			{
				stu[j+1] = stu[j];
			}
			else if(tmp.score < stu[j].score)
			{
				break;
			}
			else
			{
				if(strcmp(tmp.name, stu[j].name) < 0)
				{
					stu[j+1] = stu[j];
					//printf("%s\n", tmp.name);
				}
				else
				{
					break;
				}
			}
		}
		stu[j+1] = tmp;//important line@
	}

	return t;
}

int main(int argc, char const *argv[])
{
	/* code */
	Student stu[1000];
	int N;
	int M;
	int i;
	int score[10];

	scanf("%d", &N);
	while(N != 0)
	{
		scanf("%d%d", &M, &G);
		for(i = 0; i < M; i++)
		{
			scanf("%d", &score[i]);
		}

		char c;
		int j;
		i = 0;
		while((c = getchar())==' ' || c == '\n')
		{
			if(c == '\n')
				i++;	
			if(1 == i)//why i = 1? not 2?
				break;
		}

		for(i = 0; i < N; i++)
		{
			j = 0;	
			while((c=getchar()) != ' ')
			{	
				stu[i].name[j] = c;
				j++;
			}
			stu[i].name[j] = '\0';

			scanf("%d", &(stu[i].m));

			stu[i].score = 0;
			for(j = 0; j < stu[i].m; j++)
			{
				scanf("%d", &(stu[i].p[j]));
				stu[i].score += score[stu[i].p[j]-1];
			}

			while(getchar() != '\n')
				;
		}

	
		printf("%d\n", 	insertrank(stu, N));
		/*test*/
		for(i = 0; i < N; i++)
		{	
			if(stu[i].score >= G)
			{
				printf("%s ", stu[i].name);
			//	printf("%d ", stu[i].m );
				printf("%d\n", stu[i].score);
			}
		}
		scanf("%d", &N);
	}
	return 0;
}