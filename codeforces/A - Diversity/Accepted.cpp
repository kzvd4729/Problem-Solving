/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/24/2017 22:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/844/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 100005
using namespace std;
string s;
long fre[9999],k,l,cnt,ans;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s;
    cin>>k;
    l=s.size();
    if(k>l||k>26)
    {
        cout<<"impossible"<<endl;
        return 0;
    }
     for(long i=0; i<l; i++)
    {
        fre[(long)s[i]]++;
    }
    for(long i=0; i<9999; i++)
    {
        if(fre[i])cnt++;
    }
     ans=k-cnt;
    if(ans<0)ans=0;
    cout<<ans<<endl;
     return 0;
}