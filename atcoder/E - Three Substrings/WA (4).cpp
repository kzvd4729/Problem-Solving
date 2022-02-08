/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-14 19:36:42                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2103 ms                                         memory_used: 256 KB                               
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
bool isOk(string &a,string &b,int i,int j)
{
  for(int k=0; ;k++)
  {
    if(k+i==a.size()||k+j==b.size())return true;
    if(a[i+k]=='?'||b[j+k]=='?')continue;
    if(a[i+k]!=b[j+k])return false;
  }
}
string ss[3+2];int ans=1e9;
void ret(string a,string b,string c)
{
  string s;
  for(int i=0;i<a.size();i++)
  {
    if(isOk(a,b,i,0))
    {
      s=a;
      for(int j=a.size()-i;j<b.size();j++)
        s.push_back(b[j]);
       s=mrg(s,c);ans=min(ans,(int)s.size());
    }
  }
  for(int i=0;i<=c.size();i++)
  {
    s=a+b;
    s=mrg(s,c);ans=min(ans,(int)s.size());
    a.push_back('?');
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>ss[1]>>ss[2]>>ss[3];
  vector<int>v;v.push_back(1);v.push_back(2);v.push_back(3);
  do
  {
    //cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
    ret(ss[v[0]],ss[v[1]],ss[v[2]]);
  }while(next_permutation(v.begin(),v.end()));
  cout<<ans<<endl;
  return 0;
}