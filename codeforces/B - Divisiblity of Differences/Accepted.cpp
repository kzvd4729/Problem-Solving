/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/16/2017 17:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 4800 KB                              
*  problem: https://codeforces.com/contest/876/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,m,x;
vector<long>v[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k>>m;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        long xx=(x+m)%m;
        v[xx].push_back(x);
    }
    for(long i=0;i<m;i++)
    {
        if(v[i].size()>=k)
        {
            cout<<"Yes"<<endl;
            for(long j=0;j<k;j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}