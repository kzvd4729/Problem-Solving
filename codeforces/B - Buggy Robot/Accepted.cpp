/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/10/2017 22:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/888/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
long n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    cin>>s;
    long u=0,d=0,l=0,r=0;
    for(long i=0;i<s.size();i++)
    {
        if(s[i]=='U')u++;
        else if(s[i]=='D')d++;
        else if(s[i]=='L')l++;
        else r++;
    }
    ///cout<<l<<" "<<r<<endl;
    cout<<min(u,d)*2+min(l,r)*2<<endl;
     return 0;
}