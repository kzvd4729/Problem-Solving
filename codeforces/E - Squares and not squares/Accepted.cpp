/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2017 11:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 7500 KB                              
*  problem: https://codeforces.com/contest/898/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[200005],cnt;
vector<long>v,tmp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     for(long i=0; i<=100000; i++)
    {
        v.push_back(i*i);
    }
    cin>>n;
    for(long i=1; i<=n; i++)
    {
        cin>>arr[i];
        if(binary_search(v.begin(),v.end(),arr[i]))cnt++;
    }
    if(cnt==n/2)
    {
        cout<<0<<endl;
        return 0;
    }
    if(cnt<n/2)
    {
        for(long i=1; i<=n; i++)
        {
            if(arr[i]==0||arr[i]==1)
            {
                tmp.push_back(0);
                continue;
            }
            long id=upper_bound(v.begin(),v.end(),arr[i])-v.begin();
            long dif=min(abs(v[id]-arr[i]),abs(v[id-1]-arr[i]));
            tmp.push_back(dif);
        }
        sort(tmp.begin(),tmp.end());
        long ans=0;
        for(long i=0; i<n/2; i++)
        {
            ans+=tmp[i];
        }
        cout<<ans<<endl;
    }
    else
    {
        for(long i=1; i<=n; i++)
        {
            if(arr[i]==0)
            {
                tmp.push_back(2);
                continue;
            }
            if(binary_search(v.begin(),v.end(),arr[i]))tmp.push_back(1);
            else tmp.push_back(0);
        }
        sort(tmp.begin(),tmp.end());
        long ans=0;
        for(long i=0;i<n/2;i++)
        {
            ans+=tmp[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}