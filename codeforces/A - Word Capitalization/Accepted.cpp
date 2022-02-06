/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/28/2017 18:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/281/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        if(s[0]>='a')s[0]=s[0]-32;
        cout<<s<<endl;
     }
      return 0;
}