/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2018 15:51                        
*  solution_verdict: Wrong answer on test 32                 language: GNU C++14                               
*  run_time: 1060 ms                                         memory_used: 2100 KB                              
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
    k=min(k,100000000LL);
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