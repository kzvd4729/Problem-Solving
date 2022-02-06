/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2017 15:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/629/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,i,j;
struct data
{
    char c;
    int a;
    int b;
}arr[5005];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)cin>>arr[i].c>>arr[i].a>>arr[i].b;
    int ans=0;
    for(i=1;i<=366;i++)
    {
        int m=0;
        int f=0;
        for(j=1;j<=n;j++)
        {
            if(i>=arr[j].a&&i<=arr[j].b)
            {
                if(arr[j].c=='M')m++;
                else f++;
            }
        }
        ans=max(ans,(min(m,f)*2));
    }
     cout<<ans<<endl;
     return 0;
}