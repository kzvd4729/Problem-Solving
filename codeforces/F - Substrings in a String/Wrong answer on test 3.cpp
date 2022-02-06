/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2018 04:02                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/914/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
bitset<N+2>bt[22],one,ans;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>s;
  for(int i=1;i<=s.size();i++)
    bt[s[i-1]-'a'][i]=1,one[i]=1;
  int q;cin>>q;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int id;char c;cin>>id>>c;
      bt[s[id-1]-'a'][id]=0;
      bt[c-'a'][id]=1;
      s[id-1]=c;
    }
    else
    {
      ans=one;ans[0]=1;
      int l,r;cin>>l>>r;
      string x;cin>>x;
      for(int i=0;i<x.size();i++)
        ans&=(bt[x[i]-'a']>>i);
      int tot=(ans>>(l-1)).count()-(ans>>r).count();
      cout<<tot<<endl;
    }
  }
  return 0;
}