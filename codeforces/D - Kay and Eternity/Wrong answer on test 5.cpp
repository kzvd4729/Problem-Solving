/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/23/2020 17:08                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 236500 KB                            
*  problem: https://codeforces.com/contest/685/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
pair<int,int>pp[N+2];
void compress(int n,int k)
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(pp[i].second);
  sort(v.begin(),v.end());map<int,int>mp;
  v.erase(unique(v.begin(),v.end()),v.end());
   int cnt=0;mp[v[0]]=cnt;
  for(int i=1;i<n;i++)
  {
    if(v[i]>=v[i-1]+k)cnt+=k;
    else cnt+=v[i]-v[i-1];
    mp[v[i]]=cnt; 
  }
  for(int i=1;i<=n;i++)pp[i].second=mp[pp[i].second];
}
int n,fr[300*(N+1)+2],ls[300*(N+1)+2];long ans[N+2];
const int inf=2e9,inv=-2e9-1;
void add(int c,int k,int f,int tm)
{
  //cout<<c<<" ** "<<f<<" "<<tm<<endl;
  //cout<<"**"<<k<<endl;
  for(int i=c;i<=c+k-1;i++)
  {
    //if(fr[i]==3)cout<<"here"<<endl;
    if(ls[i]==inv)ls[i]=tm;
    else if(fr[i]>0)
    {
      //if(fr[i]==3)cout<<"here"<<endl;
      ans[fr[i]]+=min(k,tm-ls[i]);
    }
    fr[i]+=f;ls[i]=tm;
  }
  //for(int i=0;i<15;i++)
    //cout<<fr[i];
  //cout<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>pp[i].first>>pp[i].second;
  sort(pp+1,pp+n+1);compress(n,k);
  for(int i=0;i<300*(N+1)+2;i++)ls[i]=inv;
  int pt=1;
  //for(int i=1;i<=n;i++)cout<<pp[i].first<<" "<<pp[i].second<<endl;
  for(int i=1;i<=n;i++)
  {
    while(true)
    {
      if(pp[pt].first+k<=pp[i].first)
      {
        //cout<<i<<" ** "<<pt<<endl;
        add(pp[pt].second,k,-1,pp[pt].first+k);
        pt++;
      }
      else break;
    }
    add(pp[i].second,k,1,pp[i].first);
  }
  for(int i=pt;i<=n;i++)add(pp[i].second,k,-1,pp[i].first+k);
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
  return 0;
}