/****************************************************************************************
*  @author: kzvd4729#                                        created: May/12/2017 01:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/799/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,k,d,x,cnt;
    cin>>n>>t>>k>>d;
    x=n;
    cnt=0;
    while(x)
    {
        x=x-k;
        cnt++;
        if(x<=0)break;
    }
    cnt--;
    if(d<cnt*t)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}