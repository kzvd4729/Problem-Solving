/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-19 23:42:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 76                                         memory_used (MB): 2.5                             
*  problem: https://vjudge.net/problem/LightOJ-1083
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,n,x,ans,z;
struct data
{
    long rid;
    long fid;
    long val;
};
stack<data>st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        while(st.size())st.pop();
        st.push({0,0,0});
        ans=0;
        cin>>n;
        for(long i=1;i<=n;i++)
        {
            cin>>x;
            if(x>=st.top().val)st.push({i,i,x});
            else
            {
                while(st.top().val>x)
                {
                    z=(i-st.top().fid)*st.top().val;
                    ans=max(ans,z);
                    st.pop();
                }
                st.push({i,st.top().rid+1,x});
            }
        }
        while(st.size())
        {
            z=(n+1-st.top().fid)*st.top().val;
            ans=max(ans,z);
            st.pop();
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }

    return 0;
}