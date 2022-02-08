/****************************************************************************************
*  @author: kzvd4729                                         created: 17-05-2017 14:14:19                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/MAY17/problems/UNICOURS
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long t,n,a[100005],i,vis[100005],cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            vis[a[i]]=1;
        }
        cnt=0;
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}