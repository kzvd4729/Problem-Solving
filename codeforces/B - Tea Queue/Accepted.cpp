/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/02/2018 20:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/920/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,u,v,last,n;
vector<int>ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>t;
    while(t--)
    {
        ans.clear();
        cin>>n;
        cin>>u>>v;
        ans.push_back(u);
        last=u;
        for(int i=2;i<=n;i++)
        {
            cin>>u>>v;
            if(v<=last)ans.push_back(0);
            else
            {
                last=max(u,last+1);
                ans.push_back(last);
            }
        }
        for(auto x:ans)cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}