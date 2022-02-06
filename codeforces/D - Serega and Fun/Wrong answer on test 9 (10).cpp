/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/03/2018 01:03                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 686 ms                                          memory_used: 236500 KB                            
*  problem: https://codeforces.com/contest/455/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,sq=6e2;
int fr[sq+2][N+2],tmp;
deque<int>dq[sq+2];
deque<int>::iterator it;
void balance(void)
{
  for(int i=0;i<=sq;i++)
  {
    if(dq[i].size()>sq)
    {
      int tmp=dq[i].back();dq[i].pop_back();
      dq[i+1].push_front(tmp);
    }
    if(dq[i].size()<sq&&dq[i+1].size())
    {
      int tmp=dq[i+1].front();dq[i+1].pop_front();
      dq[i].push_back(tmp);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int nw=0;int f=0,cc=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;if(i==1&&x==65899)f=1;
    if(dq[nw].size()>=sq)nw++;
    dq[nw].push_back(x);fr[nw][x]++;
  }
  int q,last=0;cin>>q;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int lt,rt;cin>>lt>>rt;
      lt=(lt+last-1)%n+1;rt=(rt+last-1)%n+1;
      if(lt>rt)swap(lt,rt);
      if(lt==rt)continue;
      for(int i=0;i<=sq;i++)
      {
        if(rt<=dq[i].size())
        {
          it=dq[i].begin()+rt-1;tmp=*it;fr[i][tmp]--;
          dq[i].erase(it);break;
        }
        rt-=dq[i].size();
      }
      for(int i=0;i<=sq;i++)
      {
        if(lt<=dq[i].size())
        {
          dq[i].insert(dq[i].begin()+lt-1,tmp);
          fr[i][tmp]++;break;
        }
      }
    }
    else
    {
      int lt,rt,k;cin>>lt>>rt>>k;cc++;
      lt=(lt+last-1)%n+1;rt=(rt+last-1)%n+1;
      k=(k+last-1)%n+1;if(lt>rt)swap(lt,rt);
      int ans=0;rt=rt-lt+1;
      for(int i=0;i<=sq;i++)
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
      if(f&&cc==142)
      {
        int sum=0;
        for(int j=0;j<=sq+1;j++)sum+=dq[j].size();
        cout<<lt<<","<<rt<<","<<sum<<endl;
      }
      cout<<ans<<"\n";last=ans;
    }
    //balance();
  }
  return 0;
}