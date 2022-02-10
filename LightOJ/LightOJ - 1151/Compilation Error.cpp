/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-31 10:57:12                      
*  solution_verdict: Compilation Error                       language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1151
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=100;

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
    }
    return 1;
}
double pr[N+2][N+2],sum[N+2];
int main()
{
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int n;scanf("%d",&n);int ld[N+1];
    for(int i=0;i<=N;i++)ld[i]=i;
    while(n--)
    {
      int u,v;scanf("%d%d",&u,&v);u--;v--;ld[u]=v;
    }
    vector<vector<double> >aa;double p=1.0/6.0;
    for(int i=0;i<N;i++)
    {
      vector<double>a(N+1,0);a[i]=1.0;
      for(int j=1;j<=6;j++)
      {
        int x=i+j;
        if(x<100)a[ld[x]]-=p;
        else a[i]-=p;
      }
      a[N]=1.0;
      if(i==N-1)
      {
        for(int j=0;j<N;j++)
          a[j]=0;
        a[i]=0.0;a[N]=0.0;
      }
      aa.push_back(a);
    }
    vector<double>ans;
    gauss(aa,ans);printf("Case %d: %0.6lf\n",++tc,ans[0]);
  }
  return 0;
}