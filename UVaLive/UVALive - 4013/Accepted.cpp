/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-18 00:50:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 266                                        memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-4013
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,md=(1<<16);
int fr[(1<<16)+2],cnt[16][(1<<16)+2],qm[(1<<16)+2];
int sum(int lt,int rt)
{
  int ret=0;
  if(rt<md)
  {
    ret=qm[rt];
    if(lt)ret-=qm[lt-1];
    return ret;
  }
  ret=qm[md-1];
  if(lt)ret-=qm[lt-1];

  return ret+qm[rt%md];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,tc=0;while(cin>>n)
  {
    if(n==-1)break;
    memset(fr,0,sizeof(fr));
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;fr[x]++;
    }
    memset(qm,0,sizeof(qm));
    qm[0]=fr[0];
    for(int i=1;i<md;i++)
      qm[i]=qm[i-1]+fr[i];
    memset(cnt,0,sizeof(cnt));

    for(int j=0;j<16;j++)
    {
      int p=(1<<j);
      for(int k=0;k<p+p;k++)
      {
        int id=p-k;if(id<0)id+=md;
        int f=0;
        for(int i=id; ;i=(i+p+p)%md)
        {
          if(i==id&&f)break;f=1;
          cnt[j][k]+=sum(i,i+p-1);
        }
      }
    }
    char c;int ad=0;long ans=0;
    while(cin>>c)
    {
      if(c=='E')break;
      if(c=='C')
      {
        int x;cin>>x;ad=(ad+x)%md;
      }
      else
      {
        int x;cin>>x;
        ans+=1LL*cnt[x][ad%(1<<(x+1))];
        //cout<<"***"<<x<<" "<<ad%(1<<(x+1))<<" "<<cnt[x][ad%(1<<(x+1))]<<endl;
      }
    }
    cout<<"Case "<<++tc<<": "<<ans<<"\n";
  }
  return 0;
}