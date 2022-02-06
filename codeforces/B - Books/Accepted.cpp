/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/28/2017 19:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/279/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,t,arr[100005],x,cnt,mx,i,b;
    while(cin>>n>>t)
    {
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        x=0;
        cnt=0;
        b=-1;
        mx=0;
        for(i=0;i<n;i++)
        {
            x=x+arr[i];
            cnt++;
            if(x<=t)
            {
             }
            if(x>t)
            {
                while(x>t)
                {
                    x=x-arr[++b];
                    cnt--;
                }
             }
            if(cnt>mx)mx=cnt;
             //cout<<x<<" "<<cnt<<endl;
          }
        cout<<mx<<endl;
      }
     return 0;
}