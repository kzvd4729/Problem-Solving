/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/08/2017 22:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 122 ms                                          memory_used: 600 KB                               
*  problem: https://codeforces.com/contest/182/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long l1,l2,ans;
string s1,s2;
bool ck1(long l)
{
    string x=s1.substr(0,l);
    for(long i=l;i<l1;i+=l)
    {
        if(s1.substr(i,l)!=x)return false;
    }
    return true;
}
bool ck2(long l)
{
    string x=s2.substr(0,l);
    for(long i=l;i<l2;i+=l)
    {
        if(s2.substr(i,l)!=x)return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
     cin>>s1>>s2;
    l1=s1.size();
    l2=s2.size();
     for(long i=1;i<=min(l1,l2);i++)
    {
        if(l1%i==0&&l2%i==0&&s1.substr(0,i)==s2.substr(0,i))
        {
            if(ck1(i)&&ck2(i))ans++;
        }
    }
    cout<<ans<<endl;
     return 0;
}