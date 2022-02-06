/****************************************************************************************
*  @author: kzvd4729                                         created: 06/02/2021 00:09                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 12 ms                                           memory_used: 23.5 MB                              
*  problem: https://leetcode.com/problems/max-area-of-island
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
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1000000007;
vector<vector<int> >a,vs;
int n,m,cnt;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void dfs(int i,int j)
{
  cnt++;vs[i][j]=1;
  for(int k=0;k<4;k++)
  {
    int ii=i+dx[k],jj=j+dy[k];
    if(ii>=0 && ii<n && jj>=0 && jj<m && vs[ii][jj]==0 && a[ii][jj]==1)dfs(ii,jj);
  }
}
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        a=grid;n=a.size();
        m=a[0].size();
                vs.resize(n);
        for(int i=0;i<n;i++)vs[i].assign(m,0);
        int ret=0;
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
            if(vs[i][j] || a[i][j]==0)continue;
            cnt=0;dfs(i,j);ret=max(ret,cnt);
          }
        }
        return ret;
    }
};