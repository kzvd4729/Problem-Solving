/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-30 22:09:00                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1272
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=64;
long gauss (vector < bitset<N> > a, int n, int m) 
{
    vector<int> where (m, -1);long ans=0;
    for (int col=0, row=0; col<m && row<n; ++col) 
    {
        for (int i=row; i<n; ++i)
            if (a[i][col]) 
            {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;ans|=(1LL<<(63-col)*1LL);
        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;
    }
    return ans;
}
int main()
{
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int n;scanf("%d",&n);vector<bitset<N> >a;
    for(int ii=1;ii<=n;ii++)
    {
      long x;scanf("%lld",&x);bitset<N>bt;
      for(long i=63;i>=0;i--)
        if(x&(1LL<<i))bt[63-i]=1;
      a.push_back(bt);
    }
    printf("Case %d: %lld\n",++tc,gauss(a,n,64));
  }
  return 0;
}