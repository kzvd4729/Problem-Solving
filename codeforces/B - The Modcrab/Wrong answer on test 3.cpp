/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/14/2017 11:44                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/903/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
vector<string>ans;
long h1,a1,c1,h2,a2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>h1>>a1>>c1;
    cin>>h2>>a2;
    while(true)
    {
        if(h2<=0)break;
        if(h1<=a2)
        {
            h1+=c1;
            h1-=a2;
            ans.push_back("HEAL");
        }
        else
        {
            h2-=a1;
            h1-=a2;
            ans.push_back("STRIKE");
        }
     }
    cout<<ans.size()<<endl;
    for(auto x:ans)
    {
        cout<<x<<endl;
    }
     return 0;
}