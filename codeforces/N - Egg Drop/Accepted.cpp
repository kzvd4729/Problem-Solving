/****************************************************************************************
*  @author: JU_AAA: prdx9_abir, aniks2645, kzvd4729          created: Sep/15/2017 22:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/100819/problem/N
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,x;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k;
    long sf=1,br=k;
    for(long i=1; i<=n; i++)
    {
        cin>>x>>s;
        if(s=="SAFE")
        {
            sf=max(sf,x);
        }
        if(s=="BROKEN")
        {
            br=min(br,x);
        }
    }
    cout<<sf+1<<" ";
    cout<<br-1<<endl;
    return 0;
}