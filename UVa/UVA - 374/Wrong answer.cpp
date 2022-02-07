/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-10-20 19:35:22                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-374
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long b,p,m,pw,ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>b>>p>>m)
    {

        stack<pair<long,long> >st;
        st.push(make_pair(1LL,b%m));

        while(true)
        {
            if(st.top().first*2>p)break;
            st.push(make_pair(st.top().first*2,(st.top().second*st.top().second)%m));
        }
        pw=st.top().first;
        ans=st.top().second;
        while(st.size())
        {
            if(pw+st.top().first>p)st.pop();
            else
            {
                pw+=st.top().first;
                ans=(ans*st.top().second)%m;
                st.pop();
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}