/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-12 19:11:50                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc070/tasks/abc070_b
****************************************************************************************/
#include<iostream>
using namespace std;
int a,b,c,d,ans;
int main()
{
    cin>>a>>b>>c>>d;
    if(a<c)
    {
        ans=min((b-c),(d-c));
        if(ans<0)ans=0;
        cout<<ans<<endl;
    }
    else
    {
        ans=min(d-a,b-a);
        if(ans<0)ans=0;
        cout<<ans<<endl;
    }
    return 0;
}
 