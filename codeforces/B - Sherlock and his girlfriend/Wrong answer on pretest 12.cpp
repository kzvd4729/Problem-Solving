/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/23/2017 21:49                        
*  solution_verdict: Wrong answer on pretest 12              language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 2800 KB                              
*  problem: https://codeforces.com/contest/776/problem/B
****************************************************************************************/
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int mark[100005],num[100005];
void seive(void)
{
    memset(mark,0,sizeof(mark));
    int i,j;
    mark[1]=1;
    mark[2]=0;
    for(i=4;i<=100005;i=i+2)
    {
        mark[i]=1;
    }
    for(i=3;i<=100005;i=i+2)
    {
        if(mark[i]==0)
        {
            for(j=i;j<=100005;j=j+i*2)
            {
                if(j!=i)mark[j]=1;
            }
        }
    }
     /*for(i=1;i<=100;i++)
    {
        cout<<mark[i]<<" ";
    }*/
  }
 int main()
{
    int n,i,j;
    seive();
    while(cin>>n)
    {
        cout<<2<<endl;
        for(i=2;i<=n+1;i++)
        {
            if(mark[i]==0)
            {
                num[i]=1;
                for(j=2;  ;j++)
                {
                    if(i*j>n+1)break;
                    else num[i*j]=2;
                }
             }
             cout<<num[i]<<" ";
         }
        cout<<endl;
       }
      return 0;
}