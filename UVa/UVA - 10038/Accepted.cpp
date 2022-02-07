/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-10 21:23:00                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10038
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int arr[3003],vis[3003],i,j,n,x;
int main()
{
    while(cin>>n)
    {
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(i=0;i<n-1;i++)
        {
            vis[abs(arr[i+1]-arr[i])]=1;
        }
        int f=0;
        for(i=1;i<n;i++)
        {
            if(vis[i]==0)
            {
                f=1;
                break;
            }
        }
        if(f==1)cout<<"Not jolly"<<endl;
        else cout<<"Jolly"<<endl;

    }
    return 0;
}