/****************************************************************************************
*  @author: kzvd4729                                         created: May/01/2019 21:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1156/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int fr[30],f;
void dfs(vector<int>ord,int msk,int ls)
{
  if(!msk)
  {
    for(auto x:ord)
    {
      while(fr[x]--)
        cout<<(char)(x+'a');
    }
    cout<<"\n";f=1;return ;
  }
  if(f)return ;
  for(int i=0;i<26;i++)
  {
    if(f)return ;
    if(!(msk&(1<<i)))continue;
    if(abs(ls-i)==1)continue;
    vector<int>tmp=ord;tmp.push_back(i);
    dfs(tmp,msk^(1<<i),i);
    if(f)return ;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;
    memset(fr,0,sizeof(fr));int msk=0;
    for(auto x:s)
    {
      fr[x-'a']++;msk|=(1<<((int)(x-'a')));
    }
    vector<int>v;f=0;dfs(v,msk,30);
    if(!f)cout<<"No answer"<<"\n";
  }
  return 0;
}