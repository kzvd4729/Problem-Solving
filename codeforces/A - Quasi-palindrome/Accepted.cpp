/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2017 21:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/863/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
bool ck(long lo,long hi)
{
    long var=hi;
    for(long i=lo; i<=hi; i++)
    {
        if(s[i]!=s[var])return false;
        var--;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    long l=s.size();
    l--;
    while(true)
    {
        if(ck(0,l))
        {
            cout<<"YES"<<endl;
            return 0;
        }
        if(s[l]=='0')l--;
        else break;
    }
    cout<<"NO"<<endl;
    return 0;
}