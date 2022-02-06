/****************************************************************************************
*  @author: JU_Troubleshooer: tariqiitju, the0dd1out, kzvd4729 created: Oct/20/2018 15:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 623 ms                                          memory_used: 25200 KB                             
*  problem: https://codeforces.com/contest/1070/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
map<string,int>fr;
map<string,string>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  while(n--)
  {
    string s;cin>>s;set<string>st;
    for(int i=0;s[i];i++)
    {
      string tmp;
      for(int j=i;s[j];j++)
      {
        tmp.push_back(s[j]);
        st.insert(tmp);
      }
    }
    for(auto x:st)
    {
      fr[x]++;mp[x]=s;
    }
  }
  int q;cin>>q;
  while(q--)
  {
    string s;cin>>s;
    cout<<fr[s]<<" ";
    if(mp.find(s)==mp.end())cout<<"-"<<endl;
    else cout<<mp[s]<<endl;
  }
  return 0;
}