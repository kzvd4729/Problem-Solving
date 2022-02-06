/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2017 21:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/808/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
string s;
long l,i,n,nn;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    l=s.size();
    nn=0;
    for(i=0;i<l;i++)
    {
        nn=(nn*10)+(s[i]-'0');
    }
    s[0]=s[0]+1;
    for(i=1;i<l;i++)
    {
        s[i]='0';
    }
    n=0;
    for(i=0;i<l;i++)
    {
        n=(n*10)+(s[i]-'0');
    }
    cout<<n-nn<<endl;
    return 0;
}