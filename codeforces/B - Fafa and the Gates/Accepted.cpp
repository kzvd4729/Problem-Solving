/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/19/2018 22:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/935/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,f=-1,x,y,ans;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    cin>>s;
    x=0,y=0;
    for(auto z:s)
    {
        if(z=='U')y++;
        if(z=='R')x++;
        if(y>x)
        {
            if(f==0)ans++;
            f=1;
        }
        if(x>y)
        {
            if(f==1)ans++;
            f=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}