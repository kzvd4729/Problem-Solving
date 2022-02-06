/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/09/2017 13:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/867/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,c1,c2;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    cin>>s;
    long l=s.size();
     for(long i=0;i<l-1;i++)
    {
        if(s[i]=='S'&&s[i+1]=='F')c1++;
        if(s[i]=='F'&&s[i+1]=='S')c2++;
    }
    if(c1>c2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
      return 0;
}