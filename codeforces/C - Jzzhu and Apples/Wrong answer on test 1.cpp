/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/14/2020 11:37                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/449/problem/C
****************************************************************************************/
  #include<bits/stdc++.h>
  #define long long long
  using namespace std;
  const int N=1e5;
  int vis[N+2];
  vector<int>p[N+2];
  void solve()
  {
    for(int i=2;i<=N;i++)
    {
      if(vis[i])continue;
      for(int j=i;j<=N;j+=i)
      {
        vis[j]=1;p[j].push_back(i);
      }
    }
  }
  int main()
  {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();int n;cin>>n;vector<pair<int,int> >v;
    memset(vis,0,sizeof(vis));
     for(int i=n;i>=2;i--)
    {
      int f=0;
      for(auto x:p[i])
      {
        for(int j=i+x;j<=n;j+=x)
        {
          if(vis[j])continue;
          f=1;v.push_back({i,j});
          vis[i]=1,vis[j]=1;break;
        }
        if(f)break;
      }
    }
    cout<<v.size()<<"\n";
    for(auto x:v)cout<<x.first<<" "<<x.second<<"\n";
    return 0;
  }