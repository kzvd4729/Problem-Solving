/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/24/2020 12:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1216 ms                                         memory_used: 66900 KB                             
*  problem: https://codeforces.com/contest/650/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=8e5;
int aa[N+2],id[N+2],cn[N+2],n,m;
void compress()
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(aa[i]);
  for(int i=1;i<=m;i++)v.push_back(cn[i]);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   map<int,int>mp;
  for(int i=0;i<v.size();i++)
    mp[v[i]]=i+1;
  for(int i=1;i<=n;i++)aa[i]=mp[aa[i]];
  for(int i=1;i<=m;i++)cn[i]=mp[cn[i]];
}
int bit[N+2],bit2[N+2];
void upd(int x,int vl)
{
  for( ;x<=N;x+=x&-x)
    bit[x]=max(bit[x],vl);
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
    ret=max(ret,bit[x]);
  return ret;
}
void upd2(int x,int vl)
{
  for( ;x>0;x-=x&-x)
    bit2[x]=max(bit2[x],vl);
}
int get2(int x)
{
  int ret=0;
  for( ;x<=N;x+=x&-x)
    ret=max(ret,bit2[x]);
  return ret;
}
int dp[N+2],art[N+2],ans[N+2],lis[N+2];
vector<int>v[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=m;i++)cin>>id[i]>>cn[i];
  compress();
    int mx=0;
  for(int i=1;i<=n;i++)
  {
    dp[i]=get(aa[i]-1)+1;
    upd(aa[i],dp[i]);
     mx=max(mx,dp[i]);
  }
  lis[mx+1]=2e9;
  for(int i=n;i>=1;i--)
  {
    if(lis[dp[i]+1]>aa[i])
    {
      //cout<<"here"<<endl;
      v[dp[i]].push_back(i);//cout<<dp[i]<<endl;
      lis[dp[i]]=max(lis[dp[i]],aa[i]);
    }
  }
  for(int i=1;i<=mx;i++)
  {
    if(v[i].size()==1)
      art[v[i][0]]=1;
  }
  //for(int i=1;i<=n;i++)cout<<art[i];
    //cout<<endl;
  vector<vector<int> >p;
  for(int i=1;i<=m;i++)p.push_back({id[i],cn[i],i});
  sort(p.begin(),p.end());
   memset(bit,0,sizeof(bit));
  int pt=0;
  for(int i=1;i<=n;i++)
  {
    while(pt<p.size()&&p[pt][0]==i)
    {
      ans[p[pt][2]]+=get(p[pt][1]-1)+1;
      pt++;
    }
     upd(aa[i],get(aa[i]-1)+1);
  }
  //cout<<pt<<endl;
  pt=m-1;
  for(int i=n;i>=1;i--)
  {
    while(pt>=0&&p[pt][0]==i)
    {
      ans[p[pt][2]]+=get2(p[pt][1]+1);
      pt--;
    }
    upd2(aa[i],get2(aa[i]+1)+1);
  }
  //cout<<pt<<endl;
  for(int i=1;i<=m;i++)
  {
    if(art[id[i]])ans[i]=max(ans[i],mx-1);
    else ans[i]=max(ans[i],mx);
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}