/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-24 23:26:01                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 378                                        memory_used (MB): 28.5                            
*  problem: https://vjudge.net/problem/LightOJ-1364
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int a,b,c,d;
bool vs[15+2][15+2][15+2][15+2][4+2][4+2];
double dp[15+2][15+2][15+2][15+2][4+2][4+2];
int cal(int ty,int i,int f1,int f2)
{
  if(f1==ty)i--;if(f2==ty)i--;
  return i;
}
double dfs(int i,int j,int k,int l,int f1,int f2)
{
  if(i>=a&&j>=b&&k>=c&&l>=d)return 0;
  if(vs[i][j][k][l][f1][f2])return dp[i][j][k][l][f1][f2];

  int ii=cal(1,i,f1,f2);int jj=cal(2,j,f1,f2);
  int kk=cal(3,k,f1,f2);int ll=cal(4,l,f1,f2);
  int rm=52-(ii+jj+kk+ll)+(f1==0)+(f2==0);

  int ex=(f1==0)+(f2==0),ad=0;
  ad+=max(0,a-i-(13-ii));ad+=max(0,b-j-(13-jj));
  ad+=max(0,c-k-(13-kk));ad+=max(0,d-l-(13-ll));
  if(ad>ex)return 1e9;

  double ret=0;
  if(ii<13)ret+=((13-ii)*1.0)/(rm*1.0)*(1.0+dfs(i+1,j,k,l,f1,f2));
  if(jj<13)ret+=((13-jj)*1.0)/(rm*1.0)*(1.0+dfs(i,j+1,k,l,f1,f2));
  if(kk<13)ret+=((13-kk)*1.0)/(rm*1.0)*(1.0+dfs(i,j,k+1,l,f1,f2));
  if(ll<13)ret+=((13-ll)*1.0)/(rm*1.0)*(1.0+dfs(i,j,k,l+1,f1,f2));

  if(!f1)
  {
    int c=1+(f2==0);double mn=1e9;
    mn=min(mn,c*1.0/(rm*1.0)*(1+dfs(i+1,j,k,l,1,f2)));
    mn=min(mn,c*1.0/(rm*1.0)*(1+dfs(i,j+1,k,l,2,f2)));
    mn=min(mn,c*1.0/(rm*1.0)*(1+dfs(i,j,k+1,l,3,f2)));
    mn=min(mn,c*1.0/(rm*1.0)*(1+dfs(i,j,k,l+1,4,f2)));
    ret+=mn;
  }
  else if(!f2)
  {
    double mn=1e9;
    mn=min(mn,1.0/(rm*1.0)*(1+dfs(i+1,j,k,l,f1,1)));
    mn=min(mn,1.0/(rm*1.0)*(1+dfs(i,j+1,k,l,f1,2)));
    mn=min(mn,1.0/(rm*1.0)*(1+dfs(i,j,k+1,l,f1,3)));
    mn=min(mn,1.0/(rm*1.0)*(1+dfs(i,j,k,l+1,f1,4)));
    ret+=mn; 
  }
  vs[i][j][k][l][f1][f2]=1;
  return dp[i][j][k][l][f1][f2]=ret;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);

  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>a>>b>>c>>d;
    if(a+b+c+d>54||max(0,a-13)+max(0,b-13)+max(0,c-13)+max(0,d-13)>2)
    {
      cout<<"Case "<<++tc<<": "<<-1<<endl;
    }
    else
    {
      memset(vs,0,sizeof(vs));
      cout<<"Case "<<++tc<<": "<<setprecision(10)<<fixed<<dfs(0,0,0,0,0,0)<<"\n";
    }
  }
  return 0;
}