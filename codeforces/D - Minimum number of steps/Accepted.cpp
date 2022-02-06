/****************************************************************************************
*  @author: kzvd4729                                         created: May/20/2017 11:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/805/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long int
using namespace std;
long b,step,i;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for(i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='b')
        {
            b++;
        }
        if(s[i]=='a')
        {
            step=(step+b)%1000000007;
            b=(b*2)%1000000007;
        }
    }
    cout<<step<<endl;
    return 0;
}