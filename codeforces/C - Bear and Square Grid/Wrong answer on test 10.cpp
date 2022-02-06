/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/23/2020 13:19                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 530 ms                                          memory_used: 46900 KB                             
*  problem: https://codeforces.com/contest/679/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2,inf=1e9;
int n,k,cnt,com,lft[N*N+2],rgt[N*N+2],upp[N*N+2],dww[N*N+2],szz[N*N+2];
int bg[N+2][N+2],ed[N+2][N+2];
int vis[N+2][N+2],tk[N*N+2];
string s[N+2];
bool isV(int i,int j)
{
  if(i<1||i>n||j<1||j>n||s[i][j]=='X'||vis[i][j])return false;
  return true;
}
void dfs(int i,int j)
{
  cnt++;vis[i][j]=com;
    lft[com]=min(lft[com],j);
  rgt[com]=max(rgt[com],j);
  upp[com]=min(upp[com],i);
  dww[com]=max(dww[com],i);
   if(isV(i+1,j))dfs(i+1,j);
  if(isV(i-1,j))dfs(i-1,j);
  if(isV(i,j+1))dfs(i,j+1);
  if(isV(i,j-1))dfs(i,j-1);
}
map<pair<int,int>,int>bit[N*N+2];
void upd(int id,int x,int y)
{
  for( ;x<=N;x+=x&-x)
  {
    int yy=y;
    for( ;y<=N;y+=y&-y)
      bit[id][{x,y}]++;
    y=yy;
  }
}
int get(int id,int x,int y)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
  {
    int yy=y;
    for( ;y>0;y-=y&-y)
      ret+=bit[id][{x,y}];
    y=yy;
  }
  return ret;
}
int get(int id,int a,int b,int c,int d)
{
  return get(id,c,d)-get(id,a-1,d)-get(id,c,b-1)+get(id,a-1,b-1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>s[i],s[i]="#"+s[i];
   for(int i=1;i<=N*N;i++)upp[i]=inf,lft[i]=inf;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(!isV(i,j))continue;//cout<<i<<" "<<j<<endl;
      ++com,cnt=0;dfs(i,j);szz[com]=cnt;
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(!vis[i][j])continue;
      upd(vis[i][j],i,j);
    }
  }
  //for(int i=1;i<=com;i++)cout<<rgt[i]<<" ";cout<<endl;
  for(int i=1;i<=com;i++)
  {
    bg[upp[i]][lft[i]]=i;
    ed[dww[i]][rgt[i]]=i;
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    if(i+k-1>n)break;
    for(int j=1;j<=n;j++)
    {
      if(j+k-1>n)break;
       tk[0]=1;vector<int>bf;
      for(int a=i;a<i+k;a++)
      {
        if(!tk[vis[a][j-1]])
        {
          tk[vis[a][j-1]]=1;
          bf.push_back(vis[a][j-1]); 
        }
        if(!tk[vis[a][j+k]])
        {
          tk[vis[a][j+k]]=1;
          bf.push_back(vis[a][j+k]); 
        }
      }
      for(int b=j;b<k+k;b++)
      {
        if(!tk[vis[i-1][b]])
        {
          tk[vis[i-1][b]]=1;
          bf.push_back(vis[i-1][b]); 
        }
        if(!tk[vis[i+k][b]])
        {
          tk[vis[i+k][b]]=1;
          bf.push_back(vis[i+k][b]); 
        }
      }
      int now=k*k;
      for(auto x:bf)
        now+=szz[x]-get(x,i,j,i+k-1,j+k-1),tk[x]=0;
      bf.clear();
      ans=max(ans,now);
    }
  }
  cout<<ans<<endl;
  return 0;
}