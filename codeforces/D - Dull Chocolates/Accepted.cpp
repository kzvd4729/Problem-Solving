/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2019 00:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 4555 ms                                         memory_used: 14900 KB                             
*  problem: https://codeforces.com/gym/101991/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,R=1e9;
pair<int,int>pp[N+2];
map<int,int>rcom,ccom;
int bit[1003][1003];
void upd(int x,int y)
{
  for( ;x<=1000;x+=x&-x)
  {
    int yy=y;
    for( ;y<=1000;y+=y&-y)
      bit[x][y]++;
    y=yy;
  }
}
int get(int x,int y)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
  {
    int yy=y;
    for( ;y>0;y-=y&-y)
      ret+=bit[x][y];
    y=yy;
  }
  return ret;
}
 int main()
{
  freopen("dull.in","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    memset(bit,0,sizeof(bit));
    int n,m,k;cin>>n>>m>>k;
    vector<int>row,col;
    for(int i=1;i<=k;i++)
    {
      cin>>pp[i].first>>pp[i].second;
      row.push_back(pp[i].first);
      col.push_back(pp[i].second);
    }
    sort(row.begin(),row.end());
    sort(col.begin(),col.end());
    row.erase(unique(row.begin(),row.end()),row.end());
    col.erase(unique(col.begin(),col.end()),col.end());
     for(int i=0;i<row.size();i++)
      rcom[row[i]]=i+1;
    for(int i=0;i<col.size();i++)
      ccom[col[i]]=i+1;
    for(int i=1;i<=k;i++)
      upd(rcom[pp[i].first],ccom[pp[i].second]);
     long ans=0;
    for(auto x:row)
    {
      int pr=0;
      for(auto y:col)
      {
        int sm=get(rcom[x],ccom[y]);
        int id=upper_bound(row.begin(),row.end(),x)-row.begin(),nx;
        if(id>=row.size())nx=n+1;
        else nx=row[id];
        if(sm%2)
        {
          if(pr)continue;
          ans+=1LL*(nx-x)*(m-y+1);pr=1;
        }
        else
        {
          if(!pr)continue;
          ans-=1LL*(nx-x)*(m-y+1);pr=0;
        }
      }
    }
    cout<<ans<<" "<<1LL*n*m-ans<<"\n";
  }
  return 0;
}