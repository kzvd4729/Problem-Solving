/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/24/2019 01:00                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 10600 KB                             
*  problem: https://codeforces.com/contest/1108/problem/E2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,lt[N+2],rt[N+2],aa[N+2];
pair<int,int>sg[N+2];
/**************** Sparse for Range Min ***************/
int sp_min[N+2][21],SP[N+2];
void Sparse_Min_Build(int n)
{
  for(int i=1;i<=n;i++)
    sp_min[i][0]=SP[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if((i+(1<<(j-1)))>n)continue;
      sp_min[i][j]=min(sp_min[i][j-1],sp_min[i+(1<<(j-1))][j-1]);
    }
  }
}
int Query_Min(int lt,int rt)
{
  int dg=31-__builtin_clz(rt-lt+1);
  return min(sp_min[lt][dg],sp_min[rt-(1<<dg)+1][dg]);
}
/////////////////////////////////////////////////////////
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
  return p1.second<p2.second;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>aa[i],SP[i]=aa[i];
  Sparse_Min_Build(n);int id=0;
  int a,b;
  for(int i=1;i<=m;i++)
  {
    int x,y;cin>>x>>y;y++;lt[i]=x;rt[i]=y;
    sg[++id]={-i,x};sg[++id]={i,y};
  }
  sort(sg+1,sg+id+1,cmp);int prn=-1e9;
  vector<int>ok;
  for(int i=1;i<=n;i++)
  {
    int pr=1,cnt=0;vector<int>tmp;
    int ans=-1e9;
    for(int j=1;j<=id;j++)
    {
      int mn=Query_Min(pr,sg[j].second-1);mn-=cnt;
      ans=max(ans,aa[i]-mn);
      if(sg[j].first<0)
      {
        int ii=abs(sg[j].first);
        if(lt[ii]<=i&&rt[ii]-1>=i);
        else
        {
          cnt++;tmp.push_back(-sg[j].first);
        }
      }
      else
      {
        int ii=abs(sg[j].first);
        if(lt[ii]<=i&&rt[ii]-1>=i);
        else cnt--;
      }
      pr=sg[j].second;
    }
    int mn=Query_Min(pr,n);mn-=cnt;
    ans=max(ans,aa[i]-mn);
    if(ans>prn)
    {
      prn=ans;ok=tmp;
    }
  }
  cout<<prn<<endl;
  cout<<ok.size()<<endl;
  for(auto x:ok)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}