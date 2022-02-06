/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/14/2018 10:49                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/915/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,pos,l,r;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>pos>>l>>r;
    if(l==1&&r==n)cout<<0<<endl;
    else if(l==1)cout<<abs(r-pos)+1<<endl;
    else if(r==n)cout<<abs(pos-l)+1<<endl;
    else cout<<min(abs(pos-l)+r-l+2,abs(pos-r)+r+l+2)<<endl;
     return 0;
}