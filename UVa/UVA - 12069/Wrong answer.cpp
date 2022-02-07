/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-26 19:00:02                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12069
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2+4;
const int inf=1e8;
int lt[N+2],rt[N+2],up[N+2],dw[N+2],dis[N+2][N+2];
char mt[N+2][N+2];
void _fill(int a,int b,int c,int d)
{
  for(int i=a;i<=c;i++)
    for(int j=b;j<=d;j++)
      mt[i][j]='*';
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
      cin>>lt[i]>>up[i]>>rt[i]>>dw[i];
    int k;cin>>k;
    cout<<"Labyrinth #"<<++tc<<"\n";
    while(k--)
    {
      for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
          mt[i][j]='.';
      int a,b,c,d;cin>>a>>b>>c>>d;
      vector<int>v;map<int,int>mp1,mp2;
      v.push_back(a);v.push_back(c);
      for(int i=1;i<=n;i++)
        v.push_back(lt[i]),v.push_back(rt[i]);
      sort(v.begin(),v.end());int cnt=0;
      for(int i=0;i<v.size();i++)
      {
        cnt+=2;
        if(!mp1[v[i]])mp1[v[i]]=cnt;
      }

      v.clear();cnt=0;
      v.push_back(b);v.push_back(d);
      for(int i=1;i<=n;i++)
        v.push_back(up[i]),v.push_back(dw[i]);
      sort(v.begin(),v.end());
      for(int i=0;i<v.size();i++)
      {
        cnt+=2;
        if(!mp2[v[i]])mp2[v[i]]=cnt;
      }
      for(int i=1;i<=n;i++)
        _fill(mp1[lt[i]],mp2[up[i]],mp1[rt[i]],mp2[dw[i]]);
      a=mp1[a],b=mp2[b],c=mp1[c],d=mp2[d];
      for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
          dis[i][j]=inf;
      if(mt[mp1[a]][mp2[b]]=='*')
      {
        cout<<"Impossible"<<"\n";continue;
      }
      if(mt[mp1[c]][mp2[d]]=='*')
      {
        cout<<"Impossible"<<"\n";continue;
      }
      queue<pair<int,int> >q;q.push({a,b});
      dis[a][b]=0;
      while(q.size())
      {
        pair<int,int>p=q.front();q.pop();
        for(int i=1; ;i++)
        {
          if(p.second+i>N)break;
          if(mt[p.first][p.second+i]=='*')break;
          if(dis[p.first][p.second]+1<dis[p.first][p.second+i])
          {
            dis[p.first][p.second+i]=dis[p.first][p.second]+1;
            q.push({p.first,p.second+i});
          }
          else if(dis[p.first][p.second]+1>dis[p.first][p.second+i])break;
        }
        for(int i=1; ;i++)
        {
          if(p.second-i<1)break;
          if(mt[p.first][p.second-i]=='*')break;
          if(dis[p.first][p.second]+1<dis[p.first][p.second-i])
          {
            dis[p.first][p.second-i]=dis[p.first][p.second]+1;
            q.push({p.first,p.second-i});
          }
          else if(dis[p.first][p.second]+1>dis[p.first][p.second-i])break;
        }
        for(int i=1; ;i++)
        {
          if(p.first-i<1)break;
          if(mt[p.first-i][p.second]=='*')break;
          if(dis[p.first][p.second]+1<dis[p.first-i][p.second])
          {
            dis[p.first-i][p.second]=dis[p.first][p.second]+1;
            q.push({p.first-i,p.second});
          }
          else if(dis[p.first][p.second]+1>dis[p.first-i][p.second])break;
        }
        for(int i=1; ;i++)
        {
          if(p.first+i>N)break;
          if(mt[p.first+i][p.second]=='*')break;
          if(dis[p.first][p.second]+1<dis[p.first+i][p.second])
          {
            dis[p.first+i][p.second]=dis[p.first][p.second]+1;
            q.push({p.first+i,p.second});
          }
          else if(dis[p.first][p.second]+1>dis[p.first+i][p.second])break;
        }
      }
      if(dis[c][d]>=inf)cout<<"Impossible"<<"\n";
      else cout<<dis[c][d]-1<<"\n";
    }
  }
  return 0;
}