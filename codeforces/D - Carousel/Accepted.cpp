/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/05/2020 17:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 7200 KB                              
*  problem: https://codeforces.com/contest/1328/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;set<int>st;
    for(int i=1;i<=n;i++)
    {
      cin>>aa[i];st.insert(aa[i]);
    }
    if(st.size()==1)
    {
      cout<<1<<"\n";
      for(int i=1;i<=n;i++)cout<<1<<" ";
        cout<<"\n";
      continue;
    }
    if(n%2==0)
    {
      cout<<2<<"\n";
      for(int i=1;i<=n/2;i++)
        cout<<1<<" "<<2<<" ";
      cout<<"\n";
      continue;
    }
    aa[n+1]=aa[1];int f=0;
    for(int i=1;i<=n;i++)
      if(aa[i]==aa[i+1])f=i;
    if(f)
    {
      cout<<2<<"\n";
      int a=f,b=f+1;if(b>n)b=1;
      aa[a]=2;aa[b]=2;
      int in=1;if(a<b)a+=n;
      for(int i=b+1;i<a;i++)
      {
        int j=i;if(j>n)j-=n;
        aa[j]=in;if(in==1)in=2;else in=1;
      }
      for(int i=1;i<=n;i++)cout<<aa[i]<<" ";
        cout<<"\n";
      continue;
    }
    cout<<3<<"\n";int in=1;
    for(int i=1;i<=n;i++)
    {
      aa[i]=in;in++;if(in==4)in=1;
    }
    if(aa[n]==1)aa[n]=2;
    for(int i=1;i<=n;i++)cout<<aa[i]<<" ";
      cout<<"\n";
  }
  return 0;
}