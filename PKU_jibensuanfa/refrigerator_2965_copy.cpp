#include<stdio.h>
#include<iostream>
using namespace std;
int dir[16]={4383,8751,17487,34959,4593,8946,17652,35064,7953,12066,20292,36744,61713,61986,62532,63624};
int main()
{
      //  freopen("in","r",stdin);
        char ch;
        int va=0,minn=17,ans;
        for(int i=0;i<16;i++)
        {
                cin>>ch;
                if(ch=='+')
                        va+=1<<i;
        }
        printf("av: %d\n", va);
        for(int i=0;i<65536;i++)
        {
                int a=va,num=0;
                for(int j=0;j<16;j++)
                {
                        if(i&(1<<j))
                        {
                                a^=dir[j];
                                num++;
                        }
                }
                if(a==0)
                  if(num<minn)
                     {
                      //  printf("a: %d\n", a);
                        minn=num;
                        ans=i;
                     }
        }
        //10000000000010
        //100000000000100
        printf("%d\n",minn);
        for(int i=0;i<16;i++)
                if(ans&(1<<i))
                        printf("%d %d\n",i/4+1,i-i/4*4+1);
}
