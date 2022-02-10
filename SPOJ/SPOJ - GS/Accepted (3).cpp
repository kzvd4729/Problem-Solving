/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-30 19:53:57                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-GS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=20;

const double EPS=1e-13;
const int INF=1e9;
int gauss (vector < vector<double> > a, vector<double> & ans) 
{
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }
    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }
    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}
double pr[N+2][N+2],sum[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,bg,ed;cin>>n>>bg>>ed;bg--;ed--;
    memset(pr,0,sizeof(pr));memset(sum,0,sizeof(sum));
    for(int i=1;i<n;i++)
    {
      int u,v,w;cin>>u>>v>>w;u--;v--;
      sum[u]+=w;sum[v]+=w;pr[u][v]=w;pr[v][u]=w;
    }
    if(bg==ed)
    {
      cout<<"0.00000"<<endl;continue;
    }
    vector<vector<double> >aa;
    for(int i=0;i<n;i++)
    {
      vector<double>a(n+1,0);a[i]=1;
      for(int j=0;j<n;j++)
      {
        a[j]-=pr[i][j]/sum[i];
      }
      a[n]=1.0;
      if(i==ed)
      {
        for(int j=0;j<=n;j++)
          a[j]=0;
        a[i]=1.0;
      }
      aa.push_back(a);
    }
    vector<double>ans;int x=gauss(aa,ans);
    cout<<setprecision(5)<<fixed<<ans[bg]<<endl;
  }
  return 0;
}