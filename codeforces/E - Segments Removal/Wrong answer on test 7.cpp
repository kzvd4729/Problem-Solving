/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2017 19:47                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 9100 KB                              
*  problem: https://codeforces.com/contest/899/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[200005],l;
set<pair<long,pair<long,long> > >st;
vector<pair<long,pair<long,long> > >v[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    arr[n+1]=-1;
    l=1;
    for(long i=2;i<=n+1;i++)
    {
        if(arr[i]!=arr[l])
        {
            st.insert({-(i-l),{l,i-1}});
            v[l].push_back({-(i-l),{l,i-1}});
            v[i-1].push_back({-(i-l),{l,i-1}});
            l=i;
        }
    }
    long ans=0;
    while(st.size())
    {
        pair<long,pair<long,long> >p,p1,p2;
        p=*st.begin();
        ans++;
        st.erase(p);
        if(!st.size())break;
         if(p.second.first==1||p.second.second==n)continue;
        if(arr[p.second.first-1]==arr[p.second.second+1])
        {
            long id=p.second.first-1;
            p1=v[p.second.first-1][0];
            p2=v[p.second.second+1][0];
            st.erase(p1);
            st.erase(p2);
            st.insert({p1.first+p2.first,{p1.second.first,p2.second.second}});
        }
     }
    cout<<ans<<endl;
    return 0;
}