/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/05/2017 19:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/782/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int mark[300000];
int main()
{
    int n,i,x,cnt,mxcnt;
    while(cin>>n)
    {
        memset(mark,0,sizeof(mark));
        n=2*n;
        cnt=0;
        mxcnt=0;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            if(mark[x]==0)
            {
                mark[x]=1;
                cnt++;
                if(cnt>mxcnt)mxcnt=cnt;
            }
            else
            {
                cnt--;
            }
          }
        cout<<mxcnt<<endl;
      }
      return 0;
}