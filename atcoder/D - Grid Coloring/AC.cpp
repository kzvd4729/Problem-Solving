/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-06 18:30:10                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 4 ms                                            memory_used: 384 KB                               
*  problem: https://atcoder.jp/contests/arc080/tasks/arc080_b
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int i,n,m,c,color[10004],grid[102][102],j,id;
int main()
{
    cin>>n>>m;
    cin>>c;
    for(i=1;i<=c;i++)cin>>color[i];
    i=0;
    id=0;
    while(true)
    {
        i++;
        if(i%2==1)
        {
            for(j=1;j<=m;j++)
            {
                while(color[id]==0)id++;
                grid[i][j]=id;
                color[id]--;
            }
        }
        else
        {
            for(j=m;j>=1;j--)
            {
                while(color[id]==0)id++;
                grid[i][j]=id;
                color[id]--;
            }
        }
        if(i==n)break;
     }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
       return 0;
}