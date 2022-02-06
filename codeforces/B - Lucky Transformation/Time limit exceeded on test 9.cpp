/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2018 14:08                        
*  solution_verdict: Time limit exceeded on test 9           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/121/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n>>k;
    cin>>s;
    for(long i=0;i<s.size()-1;i++)
    {
        if(k==0)break;
        if(s[i]=='4'&&s[i+1]=='7')
        {
            if(i&1)s[i]='7',s[i+1]='7';
            else s[i]='4',s[i+1]='4';
            i-=2;
            i=max(i,-1LL);
            k--;
        }
    }
    cout<<s<<endl;
    return 0;
}