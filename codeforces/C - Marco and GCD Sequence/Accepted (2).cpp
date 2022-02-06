/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2017 14:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 8000 KB                              
*  problem: https://codeforces.com/contest/894/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long vis[1000006],arr[10004],n,gcd;
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
        gcd=__gcd(gcd,arr[i]);
    }
    if(vis[gcd]==0)cout<<-1<<endl;
    else
    {
        cout<<2*n<<endl;
        for(long i=1;i<=n;i++)
        {
            cout<<gcd<<" "<<arr[i]<<" ";
        }
        cout<<endl;
    }
     return 0;
}