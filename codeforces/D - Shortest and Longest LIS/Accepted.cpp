/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/15/2020 20:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 16200 KB                             
*  problem: https://codeforces.com/contest/1304/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],ad[N+2],bb[N+2],bit[N+2],n;
void upd(int x,int vl)
{
  for( ;x<=n;x+=x&-x)
    bit[x]+=vl;
}
int get(int x)
{
  int sm=0;
  for( ;x>0;x-=x&-x)
    sm+=bit[x];
  //cout<<"*"<<sm<<endl;
  return sm;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>n>>s;
    for(int i=1;i<=n;i++)ad[i]=0,bit[i]=0;
    aa[1]=1;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='>')
      {
        ad[i+1]++;aa[i+2]=1;
      }
      else aa[i+2]=i+2;
    }
    int sm=0;
    for(int i=n;i>=1;i--)
    {
      sm+=ad[i];aa[i]+=sm;
    }
     bb[1]=n;int cnt=0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='<')
      {
        cnt++;int rt=i+1,lt=i+1-cnt+1;
        upd(lt,-1);upd(rt+1,1);
        //cout<<lt<<" "<<rt<<endl;
        bb[i+2]=n-1-i+cnt;
      }
      else bb[i+2]=(n-1-i),cnt=0;
       //cout<<bb[i+2]<<" ";
    }
    //cout<<endl;
    sm=0;
    for(int i=n;i>=1;i--)
    {
      bb[i]+=get(i);
    }
    for(int i=1;i<=n;i++)
      cout<<bb[i]<<" ";
    cout<<"\n";
     for(int i=1;i<=n;i++)
      cout<<aa[i]<<" ";
    cout<<"\n";
   }
  return 0;
}