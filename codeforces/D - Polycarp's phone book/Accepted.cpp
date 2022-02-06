/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2018 13:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 343 ms                                          memory_used: 98900 KB                             
*  problem: https://codeforces.com/contest/861/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,trie[1000006][12][2],sz;
string s[70004],print;
void insrt(string x,int vl)
{
int now=0;
for(int i=0;i<x.size();i++)
{
char xx=x[i];
int z=xx-'0';
if(trie[now][z][0]==0)trie[now][z][0]=++sz;
trie[now][z][1]+=vl;
now=trie[now][z][0];
}
}
string query(string x)
{
string ret;
int now=0;
for(int i=0;i<x.size();i++)
{
char xx=x[i];
int z=xx-'0';
ret.push_back(xx);
if(trie[now][z][1]==0)return ret;
now=trie[now][z][0];
}
return "99999999999";
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
 cin>>n;
for(int i=1;i<=n;i++)
{
cin>>s[i];
for(int j=0;j<9;j++)insrt(s[i].substr(j,9-j),1);
}
for(int i=1;i<=n;i++)
{
for(int j=0;j<9;j++)insrt(s[i].substr(j,9-j),-1);
print="99999999999";
for(int j=0;j<9;j++)
{
string tmp=query(s[i].substr(j,9-j));
if(tmp.size()<print.size())print=tmp;
}
cout<<print<<endl;
for(int j=0;j<9;j++)insrt(s[i].substr(j,9-j),1);
}
return 0;
}