/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-12 19:19:24                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc070/tasks/abc070_c
****************************************************************************************/
#include<iostream>
using namespace std;
long long int n,i,arr[103],mx,j;
int main()
{
    cin>>n;
    mx=0;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        mx=max(mx,arr[i]);
    }
    for(i=1; ;i++)
    {
        mx=mx*i;
        int f=0;
        for(j=1;j<=n;j++)
        {
            if(mx%arr[j]!=0)
            {
                f=1;
                break;
            }
        }
        if(f==0)break;
    }
    cout<<mx<<endl;
    return 0;
}
 