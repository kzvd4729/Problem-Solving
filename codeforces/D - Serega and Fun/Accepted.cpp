/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/03/2018 01:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1185 ms                                         memory_used: 138700 KB                            
*  problem: https://codeforces.com/contest/455/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,sq=350;
int fr[sq+2][N+2],tmp;
deque<int>dq[sq+2];
deque<int>::iterator it;
void balance(void)
{
  for(int i=0;i<=sq;i++)
  {
    while(dq[i].size()>sq)
    {
      int tmp=dq[i].back();dq[i].pop_back();
      fr[i][tmp]--;fr[i+1][tmp]++;
      dq[i+1].push_front(tmp);
    }
    while(dq[i].size()<sq&&dq[i+1].size()>0)
    {
      int tmp=dq[i+1].front();dq[i+1].pop_front();
      fr[i+1][tmp]--;fr[i][tmp]++;
      dq[i].push_back(tmp);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int nw=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(dq[nw].size()>=sq)nw++;
    dq[nw].push_back(x);fr[nw][x]++;
  }
  int q,last=0;cin>>q;
  for(int qq=1;qq<=q;qq++)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int lt,rt;cin>>lt>>rt;
      lt=(lt+last-1)%n+1;rt=(rt+last-1)%n+1;
      if(lt>rt)swap(lt,rt);if(lt==rt)continue;
      for(int i=0; ;i++)
      {
        if(rt<=dq[i].size())
        {
          it=dq[i].begin()+rt-1;tmp=*it;fr[i][tmp]--;
          dq[i].erase(it);break;
        }
        rt-=dq[i].size();
      }
      for(int i=0; ;i++)
      {
        if(lt<=dq[i].size())
        {
          dq[i].insert(dq[i].begin()+lt-1,tmp);
          fr[i][tmp]++;break;
        }
        lt-=dq[i].size();
      }
    }
    else
    {
      int lt,rt,k;cin>>lt>>rt>>k;
      lt=(lt+last-1)%n+1;rt=(rt+last-1)%n+1;
      k=(k+last-1)%n+1;if(lt>rt)swap(lt,rt);
      int ans=0;rt=rt-lt+1;
      for(int i=0; ;i++)
      {
        if(!rt)break;
        else if(dq[i].size()<lt)
          lt-=dq[i].size();
        else if(!lt)
        {
          if(dq[i].size()<=rt)
            ans+=fr[i][k],rt-=dq[i].size();
          else
          {
            for(auto x:dq[i])
            {
              if(!rt)break;
              if(x==k)ans++;rt--;
            }
          }
        }
        else
        {
          int cnt=0;
          for(auto x:dq[i])
          {
            cnt++;
            if(cnt>=lt)
            {
              if(x==k)ans++;rt--;
              if(!rt)break;
            }
          }
          lt=0;
        }
      }
      cout<<ans<<"\n";last=ans;
    }
    if(qq%100==0)balance();
  }
  return 0;
}