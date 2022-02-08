/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-14 18:51:14                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 84 ms                                           memory_used: 7796 KB                              
*  problem: https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n;
vector<string>v;
void dfs(int i,char c,int msk,string s)
{
  //cout<<s<<endl;
  if(i==n)
  {
    v.push_back(s);return ;
  }
  if(msk&(1<<i))
  {
    dfs(i+1,c,msk,s);return ;
  }
   int nxt=0;
  for(int j=0;j<n;j++)
    if(!(msk&(1<<j)))nxt|=(1<<j);
  nxt^=(1<<i);
   for(int sub=nxt; ;sub=(sub-1)&nxt)
  {
    string tmp=s;tmp[i]=c;
    for(int j=0;j<n;j++)if(sub&(1<<j))tmp[j]=c;
    dfs(i+1,c+1,(msk|(1<<i))|sub,tmp);
    if(sub==0)break;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;string s;s.resize(n);
  dfs(0,'a',0,s);
  sort(v.begin(),v.end());//cout<<v.size()<<endl;
  for(auto x:v)cout<<x<<"\n";
   return 0;
}