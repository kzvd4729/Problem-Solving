/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-14 19:14:12                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 14 ms                                           memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_e
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
string mrg(string a,string b)
{
  string s=a;//cout<<s<<endl;
  for(int i=0;i<=s.size();i++)
  {
    int f=0;
    for(int j=i; ;j++)
    {
      if(j==s.size()||j-i==b.size()){f=1;break;}
      if(s[j]=='?'||b[j-i]=='?')continue;
       if(s[j]!=b[j-i])break;
    }
    if(!f)continue;//cout<<i<<endl;
    for(int j=i; ;j++)
    {
      if(j==s.size()||j-i==b.size())
      {
        while(j-i<b.size())s.push_back(b[-i+j++]);
        return s;
      }
      if(s[j]=='?')s[j]=b[j-i];
    }
  }
  assert(0);
  return s;
}
string ss[4];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>ss[1]>>ss[2]>>ss[3];int ans=1e9;
  vector<int>v;v.push_back(1);v.push_back(2);v.push_back(3);
  do
  {
    string s=mrg(ss[v[0]],ss[v[1]]);
    s=mrg(s,ss[v[2]]);ans=min(ans,(int)s.size());
  }while(next_permutation(v.begin(),v.end()));
  cout<<ans<<endl;
  return 0;
}