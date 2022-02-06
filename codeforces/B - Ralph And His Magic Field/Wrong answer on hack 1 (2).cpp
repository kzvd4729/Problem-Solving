/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/19/2017 21:12                        
*  solution_verdict: Wrong answer on hack 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/894/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,k,x,pw,ans,mod=1000000007;
long bigmod(long b,long p)
{
    if(b==0)return 0;
    if(p==0)return 1;
     stack<pair<long,long> >st;
    while(st.size())st.pop();
    st.push(make_pair(1LL,(b+mod)%mod));
    while(true)
    {
        if(st.top().first*2>p)break;
        st.push(make_pair(st.top().first*2,((st.top().second*st.top().second)+mod)%mod));
    }
    pw=st.top().first;
    ans=st.top().second;
    while(st.size())
    {
        if(pw+st.top().first>p)st.pop();
        else
        {
            pw+=st.top().first;
            ans=((ans*st.top().second)+mod)%mod;
            st.pop();
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m>>k;
     if(n==1||m==1)
    {
        cout<<1<<endl;
        return 0;
    }
    n--;
    m--;
     long b=bigmod(2LL,m);
     long z=bigmod(b,n);
     ///cout<<bigmod(78,1)<<endl;
     cout<<z<<endl;
     return 0;
}