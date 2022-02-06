/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/24/2017 00:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/41/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s1,s2,s3;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s1>>s2;
    for(long i=s2.size()-1;i>=0;i--)
    {
        s3.push_back(s2[i]);
    }
    if(s3==s1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
      return 0;
}