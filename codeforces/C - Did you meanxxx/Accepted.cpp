/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2018 10:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/861/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int l;
string s;
map<char,int>mp,mp2;
bool check(int id)
{
mp2.clear();
if(id+3>l)return false;
int cnt=0;
for(int i=id;i<id+3;i++)
{
if(mp[s[i]])return false;
if(!mp2[s[i]])cnt++;
mp2[s[i]]=1;
}
if(cnt>=2)return true;
else return false;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
 mp['a']=1;
mp['e']=1;
mp['i']=1;
mp['o']=1;
mp['u']=1;
 cin>>s;
l=s.size();
 for(int i=0;i<s.size();i++)
{
if(check(i))
{
cout<<s[i]<<s[i+1]<<" ";
i++;
}
else cout<<s[i];
}
cout<<endl;
return 0;
}