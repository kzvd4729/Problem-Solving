/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2018 00:11                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/922/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n;
string s[100005];
string k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]=='s')s[i][j]='0';
            else s[i][j]='1';
        }
    }
    sort(s+1,s+n+1);
    for(int i=1;i<=n;i++)k+=s[i];
    long cnt=0,ans=0;
    for(int i=k.size()-1;i>=0;i--)
    {
        if(k[i]=='1')cnt++;
        else ans+=cnt;
    }
    cout<<ans<<endl;
    return 0;
}