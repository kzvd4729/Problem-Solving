/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/02/2017 20:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/897/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
char c1,c2;
long n,m,l,r;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    cin>>s;
    while(m--)
    {
        cin>>l>>r>>c1>>c2;
        for(long i=l;i<=r;i++)
        {
            if(s[i-1]==c1)s[i-1]=c2;
        }
    }
    cout<<s<<endl;
     return 0;
}
 