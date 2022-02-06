/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/10/2018 20:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/765/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,k,exxa,exxb,wna,wnb;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>k>>a>>b;
    exxa=a%k;
    exxb=b%k;
     wna=a/k;
    wnb=b/k;
     if((k-1)*wnb<exxa||(k-1)*wna<exxb)cout<<-1<<endl;
    else cout<<wna+wnb<<endl;
     return 0;
}
 