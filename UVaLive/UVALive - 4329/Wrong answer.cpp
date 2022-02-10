/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-18 22:35:52                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-4329
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],bit[N+2],lsml[N+2],rsml[N+2],lbig[N+2],rbig[N+2];

void upd(int x){for( ;x<=N;x+=x&-x)bit[x]++;}
int get(int x){int ret=0;for( ;x>0;x-=x&-x)ret+=bit[x];return ret;}
void upd1(int x){for( ;x>0;x-=x&-x)bit[x]++;}
int get1(int x){int ret=0;for( ;x<=N;x+=x&-x)ret+=bit[x];return ret;}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
//to rejudge

    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n;i++)
    {
      lsml[i]=get(aa[i]);
      upd(aa[i]);
    }

    memset(bit,0,sizeof(bit));
    for(int i=n;i>=1;i--)
    {
      rsml[i]=get(aa[i]);
      upd(aa[i]);
    }

    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n;i++)
    {
      lbig[i]=get1(aa[i]);
      upd1(aa[i]);
    }

    memset(bit,0,sizeof(bit));
    for(int i=n;i>=1;i--)
    {
      rbig[i]=get1(aa[i]);
      upd1(aa[i]);
    }

    long ans=0;
    for(int i=1;i<=n;i++)
      ans+=(1LL*lsml[i]*rbig[i])+(1LL*lbig[i]*rsml[i]);
    cout<<ans<<endl;
  }
  return 0;
}