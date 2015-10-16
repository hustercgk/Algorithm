#include <cstdio>
#include <cstring>
using namespace std;

bool isScramble(char* s1, char* s2) {
    int map1[256];
    int map2[256];
    int len = strlen(s1);
    int i = 0;
    bool flag = true;
    for(i = 0; i < 256; i++)
    {
    	map1[i] = map2[i] = 0;
    }
    for(i = 0; i < len; i++)
    {
    	int j = int(s1[i]);
    	map1[j] = map1[j]+1;
    	j = int(s2[i]);
    	map2[j] = map2[j]+1;
    }
    for(i = 0; i < 256; i++)
    {
    	if(map1[i] == map2[i])
    	{
    		continue;
    	}
    	else
    	{
    		flag = false;
    		break;
    	}
    }

    return flag;
}
int main(int argc, char const *argv[])
{
	/* code */
	 char* s1 = "great";
	 char* s2 = "rgtae";

	if(isScramble(s1, s2))
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}