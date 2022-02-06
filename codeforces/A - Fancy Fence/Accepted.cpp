/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/09/2017 21:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/270/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,a,vis[200];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>t;
    while(t--)
    {
        for(long i=3;i<=1000;i++)
        {
            long x=(i-2)*180;
            if(x%i==0)vis[x/i]=1;
        }
        cin>>a;
        if(vis[a])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
     }
    return 0;
}
 