/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2017 21:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/863/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[10003],ans=99999999999,n;
vector<long>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    n=2*n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    for(long i=1;i<=n;i++)
    {
        for(long j=i+1;j<=n;j++)
        {
            v.clear();
            long sum=0;
            for(long k=1;k<=n;k++)
            {
                if(k==i||k==j)continue;
                v.push_back(arr[k]);
            }
            sort(v.begin(),v.end());
            for(long id=0;id<v.size();id+=2)
            {
                long x=abs(v[id]-v[id+1]);
                sum+=x;
            }
            ans=min(ans,sum);
        }
    }
    cout<<ans<<endl;
     return 0;
}