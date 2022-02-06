/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2018 11:35                        
*  solution_verdict: Time limit exceeded on test 3           language: GNU C++17                               
*  run_time: 4000 ms                                         memory_used: 211100 KB                            
*  problem: https://codeforces.com/contest/861/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
map<string,int>mp,vs[100005];
string s[100005],x,print;
  void make_visit(string s,int id)
{
for(int i=0;i<s.size();i++)
{
for(int j=i;j<s.size();j++)
{
x=s.substr(i,j-i+1);
mp[x]++;
vs[id][x]++;
}
}
}
 string check(string s,int id)
{
for(int j=1;j<=s.size();j++)
{
for(int i=0;i<s.size();i++)
{
if(i+j>s.size())continue;
x=s.substr(i,j);
if(mp[x]==vs[id][x])return x;           
}     
}
}
    int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
 cin>>n;
for(int i=1;i<=n;i++)
{
cin>>s[i];
make_visit(s[i],i);
}
 for(int i=1;i<=n;i++)
{
cout<<check(s[i],i)<<endl;
}
return 0;
}