/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-10-07 17:20:55                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 380                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10641
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6,inf=2e9;
#define setp(a) cout<<setprecision(a)<<fixed

struct point
{
  int x,y;
  point(){};point(int _x,int _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(int d){return point(x*d,y*d);}
  point operator/(int d){return point(x/d,y/d);}
  bool operator==(point p){return x==p.x&&y==p.y;}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  int operator^(point p)
  {
    return x*p.y-y*p.x;//0 if two vectors are same
    //signed area of the parallelogram by two vector
    //positive if p is ccw to the vector
  }
}a[N+2],b[N+2];
int n,m,c[N+2];vector<int>v[N+2],tmp[N+2];
int dp[1000+2][30+2];
int dfs(int id,int dn)
{
  if(dn==n)return 0;if(id>m)return inf;
  if(dp[id][dn]!=-1)return dp[id][dn];
  int ret=dfs(id+1,dn);

  if(tmp[id][0]<=dn&&tmp[id][1]>=dn)
    ret=min(ret,tmp[id][2]+dfs(id+1,tmp[id][1]+1));
  return dp[id][dn]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(cin>>n)
  {
    if(n==0)break;
    for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y;

    cin>>m;
    for(int i=1;i<=m;i++)cin>>b[i].x>>b[i].y>>c[i];

    for(int i=1;i<=m;i++)
    {
      //cout<<i<<" ";
      v[i].clear();
      for(int j=0;j<n;j++)
      {
        point p1=a[j]-b[i];
        point p2=a[(j+1)%n]-b[i];

        if((p1^p2)<0)v[i].push_back(j);
      }
    }
    int ans=inf;
    for(int i=0;i<n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        vector<int>l;
        for(auto x:v[j])
          l.push_back((x-i+n)%n);
        sort(l.begin(),l.end());

        int lo=inf,hi=-1;
        if(l.size())
        {
          lo=l[0],hi=l[0];
          for(int k=1;k<l.size();k++)
            if(l[k]==hi+1)hi++;
        }
        tmp[j]={lo,hi,c[j]};
      }
      sort(tmp+1,tmp+m+1,[&](vector<int>a,vector<int>b){
        return a[1]<b[1];
      });
      //for(int j=1;j<=m;j++)cout<<tmp[j][0]<<" "<<tmp[j][1]<<" "<<tmp[j][2]<<endl;
      //cout<<endl;
      memset(dp,-1,sizeof dp);
      ans=min(ans,dfs(1,0));
    }
    if(ans==inf)cout<<"Impossible.\n";
    else cout<<ans<<'\n';
  }
  return 0;
}