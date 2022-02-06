/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2019 13:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 14117 ms                                        memory_used: 44300 KB                             
*  problem: https://codeforces.com/gym/101991/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,sq=320;
int aa[N+2];long ans[10*N+2],pr[N+2];
vector<pair<int,int> >fr[N+2],rv[N+2];
 int sp[N+2][21];
void build(int n)
{
  for(int i=1;i<=n;i++)
    sp[i][0]=aa[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if((i+(1<<(j-1)))>n)continue;
      sp[i][j]=__gcd(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  int dg=31-__builtin_clz(rt-lt+1);
  return __gcd(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
 struct query
{
  int l,r,id,d;
}qr[N+2];
bool cmp(query a,query b)
{
  if(a.l/sq!=b.l/sq)return a.l<b.l;
  return a.r<b.r;
}
int main()
{
  //freopen("test.txt","r",stdin);
  //freopen("one.txt","w",stdout);
  freopen("gcdrng.in","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    memset(ans,0,sizeof(ans));
    memset(sp,0,sizeof(sp));
    memset(pr,0,sizeof(pr));
    for(int i=0;i<=N;i++)
      fr[i].clear(),rv[i].clear();
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
      fr[i].clear();rv[i].clear();
      cin>>aa[i];
    }
    build(n);//sparse build
    for(int i=1;i<=n;i++)
    {
      int gc=aa[i],id=i;
      while(true)
      {
        int lo=id,hi=n,md;
        while(hi-lo>2)
        {
          md=(lo+hi)/2;
          if(get(i,md)==gc)lo=md;
          else hi=md;
        }
        for(md=hi;md>=lo;md--)
          if(get(i,md)==gc)break;
        fr[i].push_back({gc,id});
        if(md==n)break;
        id=md+1;
        gc=__gcd(get(i,md),aa[md+1]);
      }
      fr[i].push_back({1,n+1});
      gc=aa[i],id=i;
      while(true)
      {
        int lo=1,hi=id,md;
        while(hi-lo>2)
        {
          md=(lo+hi)/2;
          if(get(md,i)==gc)hi=md;
          else lo=md;
        }
        for(md=lo;md<=hi;md++)
          if(get(md,i)==gc)break;
        rv[i].push_back({gc,id});
        if(md==1)break;
        id=md-1;
        gc=__gcd(get(md,i),aa[md-1]);
      }
      rv[i].push_back({1,0});
      /*for(auto x:rv[i])
        cout<<x.first<<" --> "<<x.second<<" ";
      cout<<endl;*/
    }
    for(int i=1;i<=q;i++)
    {
      cin>>qr[i].l>>qr[i].r>>qr[i].d;
      qr[i].id=i;
    }
    sort(qr+1,qr+q+1,cmp);
    /*for(int i=1;i<=q;i++)
      cout<<"** "<<qr[i].l<<" "<<qr[i].r<<" "<<qr[i].id<<endl;*/
     int pra=0,prb=-1;
    for(int c=1;c<=q;c++)
    {
      int nwa=qr[c].l,nwb=qr[c].r;
      //non intersecting segment
      if(prb<nwa)
      {
        for(int i=nwa;i<=nwb;i++)
        {
          for(int j=0;j<fr[i].size();j++)
          {
            if(fr[i][j].second>nwb)break;
            ans[fr[i][j].first]+=min(fr[i][j+1].second-1,nwb)-fr[i][j].second+1;
          }
        }
        for(int i=pra;i<=prb;i++)
        {
          for(int j=0;j<fr[i].size();j++)
          {
            if(fr[i][j].second>prb)break;
            ans[fr[i][j].first]-=min(fr[i][j+1].second-1,prb)-fr[i][j].second+1;
          }
        }
      }
       //new segment is inside previous segment
      else if(nwa>=pra&&nwb<=prb)
      {
        for(int i=pra;i<nwa;i++)
        {
          for(int j=0;j<fr[i].size();j++)
          {
            if(fr[i][j].second>prb)break;
            ans[fr[i][j].first]-=min(fr[i][j+1].second-1,prb)-fr[i][j].second+1;
          }
        }
        for(int i=prb;i>nwb;i--)
        {
          for(int j=0;j<rv[i].size();j++)
          {
            if(rv[i][j].second<nwa)break;
            ans[rv[i][j].first]-=rv[i][j].second-max(nwa,rv[i][j+1].second+1)+1;
          }
        }
      }
       //new segment is intersecting right
      else if(nwa>=pra&&nwa<=prb&&nwb>prb)
      {
        for(int i=pra;i<nwa;i++)
        {
          for(int j=0;j<fr[i].size();j++)
          {
            if(fr[i][j].second>prb)break;
            ans[fr[i][j].first]-=min(fr[i][j+1].second-1,prb)-fr[i][j].second+1;
          }
        }
        for(int i=nwb;i>prb;i--)
        {
          for(int j=0;j<rv[i].size();j++)
          {
            if(rv[i][j].second<nwa)break;
            ans[rv[i][j].first]+=rv[i][j].second-max(nwa,rv[i][j+1].second+1)+1;
          }
        }
      }
      //new segment covers previous segment
      else if(pra>=nwa&&prb<=nwb)
      {
        for(int i=nwa;i<pra;i++)
        {
          for(int j=0;j<fr[i].size();j++)
          {
            if(fr[i][j].second>nwb)break;
            ans[fr[i][j].first]+=min(fr[i][j+1].second-1,nwb)-fr[i][j].second+1;
          }
        }
        for(int i=nwb;i>prb;i--)
        {
          for(int j=0;j<rv[i].size();j++)
          {
            if(rv[i][j].second<pra)break;
            ans[rv[i][j].first]+=rv[i][j].second-max(pra,rv[i][j+1].second+1)+1;
          }
        }
      }
      else assert(0);
       /*cout<<"/**************\\"<<endl;
      for(int i=0;i<=N;i++)
        if(ans[i])cout<<i<<" "<<ans[i]<<endl;
       cout<<"/**************\\"<<endl;*/
       pr[qr[c].id]=ans[qr[c].d];
      pra=nwa,prb=nwb;
    }
    for(int i=1;i<=q;i++)
      cout<<pr[i]<<"\n";
  }
  return 0;
}