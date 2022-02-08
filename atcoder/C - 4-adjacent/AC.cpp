/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-06 18:12:47                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 40 ms                                           memory_used: 384 KB                               
*  problem: https://atcoder.jp/contests/arc080/tasks/arc080_a
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int i,n,x,f,c;
int main()
{
    cin>>n;
    f=0;
    c=0;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x%4==0)f++;
        else if(x%2==0)c++;
    }
    f=f+(c/2);
    n=n/2;
    if(f>=n)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
      return 0;
}