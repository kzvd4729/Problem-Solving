/****************************************************************************************
*  @author: kzvd4729#                                        created: May/11/2017 16:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/743/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,x1,x2;
    string s;
    cin>>n>>x1>>x2;
    cin>>s;
    if(s[x1-1]==s[x2-1])cout<<0<<endl;
    else cout<<1<<endl;
    return 0;
}