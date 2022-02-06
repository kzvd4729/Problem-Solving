/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/13/2020 22:31                        
*  solution_verdict: Wrong answer on pretest 15              language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1301/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
   int mx=4*n*m-2*n-2*m;int kk=k;
  //cout<<mx<<endl;
   if(k>mx)cout<<"NO\n",exit(0);
   cout<<"YES\n";vector<pair<int,string> >ans;
  if(n==1)
  {
    int mn=min(m-1,k);
    ans.push_back({mn,"R"});
    k-=mn;
     if(k)
    {
      mn=min(m-1,k);
      ans.push_back({mn,"L"});
    }
    cout<<ans.size()<<"\n";
    //for(auto x:ans)
      //cout<<x.first<<" "<<x.second<<"\n";
    exit(0);
  }
  if(m==1)
  {
    int mn=min(n-1,k);
    ans.push_back({mn,"D"});
    k-=mn;
     if(k)
    {
      mn=min(n-1,k);
      ans.push_back({mn,"U"});
    }
    cout<<ans.size()<<"\n";
    //for(auto x:ans)
      //cout<<x.first<<" "<<x.second<<"\n";
    exit(0);
  }
   for(int i=1;i<=m;i++)
  {
    int rm=min(n-1,k);
    string c="D";if(i%2==0)c="U";
    if(rm)ans.push_back({rm,c});
     k-=rm;
     if(i<m&&k)
    {
      k--;
      ans.push_back({1,"R"});
    }
  }
  for(int i=m;i>=1;i--)
  {
    if(i>1)
    {    
      string c="U";if(i%2==0)c="D";
      if(i%2==0)
      {
        int mx=3*(n-1);
        if(mx&&mx<=k)
        {
          ans.push_back({n-1,"LRD"});
          k-=mx;
        }
        else
        {
          if(k/3)
          {
            ans.push_back({k/3,"LRD"});
            k%=3;
          }
          if(k)ans.push_back({1,"L"}),k--;
          if(k)ans.push_back({1,"R"}),k--;
        }
      }
      else
      {
        int mx=3*(n-1);
        if(mx&&mx<=k)
        {
          ans.push_back({n-1,"LRU"});
          k-=mx;
        }
        else
        {
          if(k/3)
          {
            ans.push_back({k/3,"LRU"});
            k%=3;
          }
          if(k)ans.push_back({1,"L"}),k--;
          if(k)ans.push_back({1,"R"}),k--;
        }
      }
       if(k)
      {
        k--;
        ans.push_back({1,"L"});
      }
    }
    else
    {
      if(k)
      {
        ans.push_back({k,"U"});
      }
    }
  }
  int sm=0;
  cout<<ans.size()<<"\n";
  for(auto x:ans)
  {
    cout<<x.first<<" "<<x.second<<"\n";
    sm+=x.first;
  }
  //if(sm!=kk)assert(0);
  return 0;
}