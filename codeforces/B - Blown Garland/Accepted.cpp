/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/19/2017 22:03                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/758/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[110],str2[110];
    long int len,i,j,x,z,kr,kb,ky,kg;
    while(gets(str))
    {
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]=='R')
            {
                for(j=i;j<len;j=j+4)
                {
                    str2[j]='R';
                }
                for(j=i;j>=0;j=j-4)
                {
                    str2[j]='R';
                }
            }
            else if(str[i]=='B')
            {
                for(j=i;j<len;j=j+4)
                {
                    str2[j]='B';
                }
                for(j=i;j>=0;j=j-4)
                {
                    str2[j]='B';
                }
            }
            else if(str[i]=='Y')
            {
                for(j=i;j<len;j=j+4)
                {
                    str2[j]='Y';
                }
                for(j=i;j>=0;j=j-4)
                {
                    str2[j]='Y';
                }
            }
            else if(str[i]=='G')
            {
                for(j=i;j<len;j=j+4)
                {
                    str2[j]='G';
                }
                for(j=i;j>=0;j=j-4)
                {
                    str2[j]='G';
                }
            }
        }
        /*for(i=0;i<len;i++)
        {
            printf("%c",str[i]);
        }
        printf("\n");
         for(i=0;i<len;i++)
        {
            printf("%c",str2[i]);
        }*/
        kr=0;kb=0;ky=0;kg=0;
        for(i=0;i<len;i++)
        {
            if(str[i]=='!')
            {
                if(str2[i]=='R')kr++;
                else if(str2[i]=='B')kb++;
                else if(str2[i]=='Y')ky++;
                else if(str2[i]=='G')kg++;
            }
        }
        printf("%ld %ld %ld %ld\n",kr,kb,ky,kg);
       }
      return 0;
}