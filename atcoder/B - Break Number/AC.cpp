/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-07-29 18:06:47                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc068/tasks/abc068_b
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,cnt,mx,ans,x,xx;
int main()
{
    cin>>n;
    for(x=1; x<=n; x++)
    {
        xx=x;
        cnt=0;
        while(xx)
        {
            if(xx%2==0)
            {
                cnt++;
                xx=xx/2;
            }
            else break;
        }
        if(cnt>=mx)
        {
            mx=cnt;
            ans=x;
        }
    }
    cout<<ans<<endl;
    return 0;
}