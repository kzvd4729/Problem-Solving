/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-31 13:00:10                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 190                                        memory_used (MB): 17.4                            
*  problem: https://vjudge.net/problem/SPOJ-LIM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=300;

const double EPS=1e-9;
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
    return 1;
}
double pr[N+2][N+2],sum[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  while(cin>>n)
  {
    if(!n)break;
    memset(sum,0,sizeof(sum));memset(pr,0,sizeof(pr));
    for(int i=1;i<=n;i++)
    {
      int u,v;cin>>u>>v;pr[v][u]=1.0;
      sum[u]++;sum[v]++;pr[u][v]=1.0;
    }
    n=300;vector<vector<double> >aa;
    for(int i=0;i<=n;i++)
    {
      vector<double>a(n+2,0.0);
      for(int j=0;j<=n;j++)
        if(sum[i]>0.0)a[j]-=pr[i][j]/sum[i];
      if(i>290)for(int j=0;j<n+2;j++)a[j]=0.0;
      a[i]+=1.0;if(i==n)a[n+1]=1.0;
      aa.push_back(a);
    }
    cout<<setprecision(3)<<fixed;
    vector<double>ans;gauss(aa,ans);
    cout<<ans[0]<<endl;
  }
  return 0;
}