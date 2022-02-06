/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/19/2017 20:32                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 9700 KB                              
*  problem: https://codeforces.com/contest/894/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long vis[1000006],arr[1004],n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i];
        vis[arr[i]]=1;
    }
    long gcd,f=0;
    for(long i=1;i<=n;i++)
    {
        gcd=0;
        for(long j=i;j<=n;j++)
        {
            gcd=__gcd(gcd,arr[j]);
            if(vis[gcd]==0)f=1;
        }
    }
    if(f==0)
    {
        cout<<n<<endl;
        for(long i=1;i<=n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    else cout<<-1<<endl;
     return 0;
}