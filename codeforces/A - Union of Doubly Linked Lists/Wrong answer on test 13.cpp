/****************************************************************************************
*  @author: JU_AAA: aniks2645, kzvd4729, prdx9_abir          created: Sep/18/2017 19:18                        
*  solution_verdict: Wrong answer on test 13                 language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/847/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,f,l[105],r[105];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
    }
    f=0;
    for(i=1;i<=n;i++)
    {
        if(f==0&&r[i]==0)
        {
            f=1;
        }
        else if(f==1&&r[i]==0)
        {
            for(j=1;j<=n;j++)
            {
                if(l[j]==0&&j!=i)
                {
                    l[j]=i;
                    r[i]=j;
                    break;
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        cout<<l[i]<<" "<<r[i]<<endl;
    }
     return 0;
}