/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/01/2017 14:55                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/798/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s1,s2;
long cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s1;
    s2=s1;
    reverse(s2.begin(),s2.end());
    for(long i=0;i<s1.size();i++)
    {
        if(s1[i]!=s2[i])cnt++;
    }
    if(cnt==2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
     return 0;
}
 