/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2018 11:19                        
*  solution_verdict: Time limit exceeded on test 3           language: GNU C++14                               
*  run_time: 4000 ms                                         memory_used: 48000 KB                             
*  problem: https://codeforces.com/contest/861/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
map<string,int>mp;
string s[100005],x,mn;
  void make_visit(string s)
{
for(int i=0;i<s.size();i++)
{
for(int j=i;j<s.size();j++)
{
mp[s.substr(i,j-i+1)]++;
}
}
}
 string minimum(string a,string b)
{
return a.size()>b.size()?b:a;
}
 void check(string s)
{
for(int i=0;i<s.size();i++)
{
for(int j=i;j<s.size();j++)
{
x=s.substr(i,j-i+1);
mp[x]--;
}
}
for(int i=0;i<s.size();i++)
{
for(int j=i;j<s.size();j++)
{
x=s.substr(i,j-i+1);
if(mp[x]==0)mn=minimum(mn,x);
mp[x]++;
}
}
///make_visit(s);
}
    int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
 cin>>n;
for(int i=1;i<=n;i++)cin>>s[i];
 for(int i=1;i<=n;i++)
{
make_visit(s[i]);
}
 for(int i=1;i<=n;i++)
{
mn="9999999999";
check(s[i]);
cout<<mn<<endl;
}
return 0;
}