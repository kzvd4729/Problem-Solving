/****************************************************************************************
*  @author: JU_AAA: prdx9_abir, aniks2645, kzvd4729#         created: Sep/20/2017 17:31                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/100199/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s;
    if((s[s.size()-1]-'0')%2==0)cout<<1<<endl;
    else cout<<3<<endl;
     return 0;
}