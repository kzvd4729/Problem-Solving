/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-19 22:50:21                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1083
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,arr[30003],n,x,ans;
stack<pair<long,long> >st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(long i=1;i<=n;i++)cin>>arr[i];

        while(st.size())st.pop();

        st.push({0,0});
        ans=0;
        for(long i=1;i<=n;i++)
        {
            if(arr[i]>=st.top().second)
            {
                st.push({i,arr[i]});
            }
            else
            {
                while(st.top().second>arr[i])
                {
                    x=(i-st.top().first)*st.top().second;
                    ans=max(ans,x);
                    st.pop();
                }
                st.push({st.size(),arr[i]});
            }
        }
        while(st.size())
        {
            x=(n+1-st.top().first)*st.top().second;
            ans=max(ans,x);
            st.pop();
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
    return 0;
}