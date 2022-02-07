/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-30 23:00:54                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-374
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long bigmod(long b,long p,long m)
{
    if(b==0)return 0;
    if(p==0)return 1%m;
    stack<pair<long,long> >st;
    st.push({1,b%m});
    while(true)
    {
        long x=st.top().first;
        long z=st.top().second;
        x*=2;
        z*=z;
        if(x>p)break;
        st.push({x,z%m});
    }
    long still=st.top().first;
    long ans=st.top().second;
    while(st.size())
    {
        if(still+st.top().first<=p)
        {
            ans=(ans*st.top().second)%m;
            still+=st.top().first;
        }
        st.pop();
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long b,p,m;
    while(cin>>b>>p>>m)
    {
        cout<<bigmod(b,p,m)<<endl;
    }

    return 0;
}