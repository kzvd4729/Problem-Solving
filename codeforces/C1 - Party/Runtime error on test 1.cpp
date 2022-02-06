/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/20/2018 19:04                        
*  solution_verdict: Runtime error on test 1                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 35200 KB                             
*  problem: https://codeforces.com/contest/177/problem/C1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n;
struct data
{
  string s;int pt,sc,ms;
  data()
  {
    pt=0;sc=0;ms=0;
  }
}aa[N+2];
map<string,int>mp;
bool cmp(data A,data B)
{
  if(A.pt!=B.pt)return A.pt>B.pt;
  if(A.sc-A.ms!=B.sc-B.ms)return A.sc-A.ms>B.sc-B.ms;
  if(A.sc!=B.sc)return A.sc>B.sc;
  return A.s<B.s;
}
pair<string,string>parse1(string s)
{
  int i=0;string a,b;
  for( ;s[i]!='-';i++)
    a.push_back(s[i]);
  for(++i;s[i];i++)
    b.push_back(s[i]);
  return {a,b};
}
pair<int,int>parse2(string s)
{
  int i=0;int a=0,b=0;
  for( ;s[i]!=':';i++)
    a=a*10+(s[i]-'0');
  for(++i;s[i];i++)
    b=b*10+(s[i]-'0');
  return {a,b};
}
void _sort(void)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(aa[i].sc>aa[j].sc)swap(aa[i],aa[j]);
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(aa[i].sc-aa[i].ms<aa[j].sc-aa[j].ms)swap(aa[i],aa[j]);
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(aa[i].pt<aa[j].pt)swap(aa[i],aa[j]);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i].s;
    mp[aa[i].s]=i;
  }
  int nn=n*(n-1)/2;
  for(int i=1;i<=nn;i++)
  {
    string s1,s2;cin>>s1>>s2;
    pair<string,string>p1=parse1(s1);
     // if(p1.first.size()==0||p1.second.size()==0)assert(0);
    // if(p1.first.size()+p1.second.size()+1!=s1.size())
    //   assert(0);
     pair<int,int>p2=parse2(s2);
     int id1=mp[p1.first],id2=mp[p1.second];
     aa[id1].sc+=p2.first;aa[id1].ms+=p2.second;
    aa[id2].sc+=p2.second;aa[id2].ms+=p2.first;
     if(p2.first>p2.second)
      aa[id1].pt+=3;
    else if(p2.second>p2.first)
      aa[id2].pt+=3;
    else aa[id1].pt++,aa[id2].pt++;
  }
  sort(aa+1,aa+n+1,cmp);
    vector<string>v;
  for(int i=1;i<=n/2;i++)
    v.push_back(aa[i].s);
  sort(v.begin(),v.end());
  for(auto x:v)
    cout<<x<<endl;
  return 0;
}