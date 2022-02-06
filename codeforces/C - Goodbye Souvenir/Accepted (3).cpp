/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2020 20:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 4336 ms                                         memory_used: 7200 KB                              
*  problem: https://codeforces.com/contest/848/problem/C
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
#define long long long
using namespace std;
const int N=1e5;
int n,aa[N+2],ls[N+2];
set<int>st[N+2];
long bit[N+2];
struct data
{
  int l,r,id;long an;
};
vector<data>ask;
void upd(int id,int ad){for( ;id<=N;id+=id&-id)bit[id]+=ad;}
long get(int id){long ret=0;for( ;id>0;id-=id&-id)ret+=bit[id];return ret;}
void udp(int id,int ad){for( ;id>0;id-=id&-id)bit[id]+=ad;}
long gte(int id){long ret=0;for( ;id<=N;id+=id&-id)ret+=bit[id];return ret;}
void build()
{
  sort(ask.begin(),ask.end(),[&](data a,data b){
    return a.r<b.r;
  });
  memset(ls,0,sizeof(ls));memset(bit,0,sizeof(bit));
  int pt=0;
  for(int i=1;i<=n;i++)
  {
    if(ls[aa[i]])upd(ls[aa[i]],-ls[aa[i]]);
    ls[aa[i]]=i;upd(ls[aa[i]],i);
    while(pt<ask.size()&&ask[pt].r==i)
    {
      ask[pt].an=get(i)-get(ask[pt].l-1);
      pt++;
    }
  }
  sort(ask.begin(),ask.end(),[&](data a,data b){
    return a.l<b.l;
  });
  memset(ls,0,sizeof(ls));memset(bit,0,sizeof(bit));
  pt=ask.size()-1;
  for(int i=n;i>=1;i--)
  {
    if(ls[aa[i]])udp(ls[aa[i]],-ls[aa[i]]);
    ls[aa[i]]=i;udp(ls[aa[i]],i);
    while(pt>=0&&ask[pt].l==i)
    {
      ask[pt].an-=(gte(i)-gte(ask[pt].r+1));
      pt--;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>aa[i],st[aa[i]].insert(i);
  int magic=400;vector<vector<int> >chn;
  for(int i=1;i<=q;i++)
  {
    int a,b,c;cin>>a>>b>>c;
    if(a==2)ask.push_back({b,c,i,0});
    else chn.push_back({i,b,c});

    if(i%magic&&i!=q)continue;
    build();
    sort(ask.begin(),ask.end(),[&](data a,data b){
    return a.id<b.id;
    });
    a=0,b=0;
    while(true)
    {
      if(a==chn.size())
      {
        while(b<ask.size())cout<<ask[b++].an<<"\n";
        break;
      }
      if(b==ask.size())
      {
        while(a<chn.size())
        {
          int id=chn[a][1],nw=chn[a][2];
          st[aa[id]].erase(id);aa[id]=nw;
          st[aa[id]].insert(id);
          a++;
        }
        break;
      }
      if(chn[a][0]<ask[b].id)
      {
        int id=chn[a][1],nw=chn[a][2];//cout<<id<<" -- "<<nw<<endl;
        int ol=aa[id];aa[id]=nw;
        //st[ol].erase(id);st[nw].insert(id);
        for(int j=b;j<ask.size();j++)
        {
          if(id<ask[j].l||id>ask[j].r)continue;
          auto lt=st[ol].lower_bound(ask[j].l);
          auto rt=st[ol].upper_bound(ask[j].r);rt--;
          if(lt!=st[ol].end()&&*lt<=*rt)ask[j].an-=(*rt-*lt);//cout<<*lt<<" "<<*rt<<endl;
          lt=st[nw].lower_bound(ask[j].l);
          rt=st[nw].upper_bound(ask[j].r);rt--;
          if(lt!=st[nw].end()&&*lt<=*rt)ask[j].an-=(*rt-*lt);//cout<<*lt<<" "<<*rt<<endl;
        }
        st[ol].erase(id);st[nw].insert(id);
        for(int j=b;j<ask.size();j++)
        {
          if(id<ask[j].l||id>ask[j].r)continue;
          auto lt=st[ol].lower_bound(ask[j].l);
          auto rt=st[ol].upper_bound(ask[j].r);rt--;
          if(lt!=st[ol].end()&&*lt<=*rt)ask[j].an+=(*rt-*lt);//cout<<*lt<<" "<<*rt<<endl;
          lt=st[nw].lower_bound(ask[j].l);
          rt=st[nw].upper_bound(ask[j].r);rt--;
          if(lt!=st[nw].end()&&*lt<=*rt)ask[j].an+=(*rt-*lt);//cout<<*lt<<" "<<*rt<<endl;
        }
        a++;
      }
      else cout<<ask[b++].an<<"\n";
    }
    chn.clear();ask.clear();
  }
  return 0;
}