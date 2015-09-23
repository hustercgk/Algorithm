nclude <cstdio>
#include <iostream>
using namespace std ;

int f[16]={19,39,78,140,305,626,1252,2248,4880,10016,20032,35968,12544,29184,58368,51200} ;
int min_times = 16, times = 0 ;
bool is_find = false ;
int begin = 0 ;
// void DFS(int val,int dep)
// {
//     if( val == 65535 || val == 0 )
//     {
//         is_find = true ;
//         if( times < min_times )
//         min_times = times ;
//     }
//     if( dep == 16 ) return ;  
//     int temp = val ;
//     val = val ^ f[dep] ;
//     times++ ;
//     DFS(val,dep+1) ;
//     times-- ;
//     DFS(temp,dep+1) ;
// }
///
int main()
{
    char ch ;
    for( int i = 0; i < 16; )
    {
        cin.get(ch) ;
    if( ch == 'b' )
    {
        begin += (1<<i) ;
        i++ ;
        }
    else if( ch == 'w' )
    {
        i++ ;
        } 
    }
    if( begin == 65535 || begin == 0 )
    {
        printf("0\n") ;
    }
    else
    {
       // int a[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        int i, j, k;
        int temp;
        int count = 0;
        int t = 1 << 16;
        temp = begin;
        for (i = 0; i < t; i++)
        {
                j = i;
                k = 0;
                count = 0;
              //  printf("{");
                while (j)
                {
                        if (j & 1)
                        {
                               // printf("%d", a[k]);
                            begin = begin ^ f[k];
                            count++;
                        }
                        j >>= 1;
                        ++k;
                }
                if( begin == 65535 || begin == 0 )
                {
                    if(min_times > count)
                            min_times = count;
                    is_find = true;
                   // break;
                }

                begin = temp;
               // printf("}\n");
        }
        // DFS(begin,0) ;
        if( is_find )
        {
            printf("%d\n",min_times) ;
        }
        else
        printf("Impossible\n") ;
    }
    return 0 ;
}
