/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/09/2017 23:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/6/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,c,d;
bool ck(long x,long y,long z)
{
    if(x+y>z&&x+z>y&&y+z>x)return true;
    return false;
}
bool ck1(long x,long y,long z)
{
    if(x+y==z||x+z==y||y+z==x)return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>a>>b>>c>>d;
    if(ck(a,b,c)||ck(a,b,d)||ck(a,c,d)||ck(b,c,d))
    {
        cout<<"TRIANGLE"<<endl;
        return 0;
    }
    if(ck1(a,b,c)||ck1(a,b,d)||ck1(a,c,d)||ck1(b,c,d))
    {
        cout<<"SEGMENT"<<endl;
        return 0;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
 