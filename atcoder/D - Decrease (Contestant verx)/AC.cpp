/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-07-29 18:55:48                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc068/tasks/arc079_b
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int k,i,d,m,arr[100];
int main()
{
    cin>>k;
    d=k/50;
    m=k%50;
    for(i=0;i<=49;i++)
    {
        arr[i]=i+d;
    }
    for(i=49;i>=0;i--)
    {
        if(m==0)break;
        arr[i]++;
        m--;
    }
    cout<<50<<endl;
    for(i=0;i<50;i++)
    {
        cout<<arr[i];
        if(i!=49)cout<<" ";
    }
    cout<<endl;
    return 0;
}