/****************************************************************************************
*  @author: kzvd4729                                         created: May/25/2020 11:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/1144/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=1e6;
string numToString(long x)
{
  string ret;
  while(x)
  {
    ret.push_back((char)(x%26+'a'));
    x/=26;
  }
  reverse(ret.begin(),ret.end());
  if(ret.size()==0)ret.push_back('a');
  return ret;
}
long stringToNum(string s)
{
  long ret=0;
  for(auto x:s)
    ret=ret*26+(x-'a');
  return ret;
}
int compare(string a,string b)//not lexicographic
{
  int x=a.size(),y=b.size();
  if(x<y)return -1;if(x>y)return 1;
  for(int i=0;i<x;i++)
  {
    if(a[i]<b[i])return -1;//b is bigger
    if(a[i]>b[i])return 1;//a is bigger
  }
  return 0;//same
}
string add(string a,string b)
{
  reverse(a.begin(),a.end());reverse(b.begin(),b.end());
  int x=a.size(),y=b.size();
  while(x<y)a.push_back('a'),x++;
  while(y<x)b.push_back('a'),y++;
  int c=0;string r;
  for(int i=0;i<x;i++)
  {
    int x=c+a[i]-'a'+b[i]-'a';
    c=x/26;x%=26;
    r.push_back((char)(x+'a'));
  }
  if(c)r.push_back((char)(c+'a'));
  reverse(r.begin(),r.end());return r;
}
string sub(string a,string b)
{
  //assuming a>=b;
  reverse(a.begin(),a.end());reverse(b.begin(),b.end());
  int x=a.size(),y=b.size();
  while(y<x)b.push_back('a'),y++;
  int c=0;string r;
  for(int i=0;i<x;i++)
  {
    int x=(a[i]-'a')-(b[i]-'a'+c);
    if(x<0)x+=26,c=1;
    else c=0;
    r.push_back((char)(x+'a'));
  }
  while(r.size()>1)
  {
    if(r.back()=='a')r.pop_back();
    else break;
  }
  reverse(r.begin(),r.end());return r;
}
string mul(string a,long b)
{
  //b should be <= 1e17
  int x=a.size();string ret;long c=0;
  for(int i=x-1;i>=0;i--)
  {
    int z=a[i]-'a';c+=z*b;
    ret.push_back((char)(c%26)+'a');
    c/=26;
  }
  while(c)
  {
    ret.push_back((char)(c%26)+'a');
    c/=26;
  }
  reverse(ret.begin(),ret.end());
  return ret;
}
pair<string,string>divide(string a,string b)
{
  //if(b=="0")assert(0);
  if(compare(a,b)<0)return {"a",a};
  int x=a.size(),y=b.size();
  string rm="a",rt;int i=0;
  while(i<x)
  {
    if(rm=="a")rm.clear();int cnt=0;
    while(true)
    {
      if(i>=x)break;
      if(a[i]!='a')rm.push_back(a[i]);
      else if(rm.size())rm.push_back(a[i]);
      cnt++;i++;
      if(rm.size()>=b.size())
        if(compare(rm,b)>=0)break;
      if(rt.size())rt.push_back('a');
    }
    if(compare(rm,b)>=0)
    {
      for(int k=25;k>=1;k--)
      {
        string tmp=mul(b,k);
        if(compare(rm,tmp)>=0)
        {
          rt.push_back((char)(k+'a'));
          rm=sub(rm,tmp);break;
        }
      }
    }
  }
  if(rm.size()==0)rm.push_back('a');
  return {rt,rm};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  string a,b;cin>>a>>b;string df=sub(b,a);
  df=add(df,"b");df=divide(df,"c").first;
  cout<<add(a,df)<<endl;
  return 0;
}