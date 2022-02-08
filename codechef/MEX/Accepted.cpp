/****************************************************************************************
*  @author: kzvd4729                                         created: 06-10-2017 15:59:13                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.04 sec                                        memory_used: 18.7M                                
*  problem: https://www.codechef.com/OCT17/problems/MEX
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long vis[400014],t,n,x,k;
vector<long>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        v.clear();
        cin>>n>>k;
        while(n--)
        {
            cin>>x;
            vis[x]=1;
        }
        for(long i=0;i<=400010;i++)
        {
            if(vis[i]==0)v.push_back(i);
        }
        cout<<v[k]<<endl;
    }
    return 0;
}