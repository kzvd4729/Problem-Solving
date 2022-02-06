/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2018 15:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 4900 KB                              
*  problem: https://codeforces.com/contest/922/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n;
string s[100005];
long compute(string ss)
{
    long cnt=0,ans=0;
    for(int i=ss.size()-1;i>=0;i--)
    {
        if(ss[i]=='h')cnt++;
        else ans+=cnt;
    }
    return ans;
}
bool cmp(string a,string b)
{
    return compute(a+b)>compute(b+a);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    sort(s+1,s+n+1,cmp);
//    for(int i=1;i<=n;i++)cout<<s[i];
//    cout<<endl;
    string k;
    for(int i=1;i<=n;i++)k+=s[i];
    cout<<compute(k)<<endl;
    return 0;
}