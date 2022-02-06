/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/23/2019 22:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 10700 KB                             
*  problem: https://codeforces.com/contest/1108/problem/E1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],n,sp[N+2][22],lt[N+2],rt[N+2];
pair<int,int>sg[N+2];
void build(void)
{
  for(int i=1;i<=n;i++)
    sp[i][0]=aa[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if((i+(1<<(j-1)))>n)continue;
      sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
int qry(int lt,int rt)
{
  if(rt<lt)return 1e9;
  int df=(rt-lt+1),dg=31-__builtin_clz(df);
  return min(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
  return p1.second<p2.second;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  build();int id=0;
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
      int mn=qry(pr,sg[j].second-1);mn-=cnt;
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
    int mn=qry(pr,n);mn-=cnt;
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