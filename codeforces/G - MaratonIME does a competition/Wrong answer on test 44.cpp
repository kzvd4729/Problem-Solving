/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2017 19:48                        
*  solution_verdict: Wrong answer on test 44                 language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 2300 KB                              
*  problem: https://codeforces.com/gym/101375/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,arr[100000],a,b,c,d,x,i;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(i=1;i<=n;i=i+4)
    {
        a+=arr[i];
        b+=arr[i+1];
        c+=arr[i+2];
        d+=arr[i+3];
        x=max(d,max(c,max(a,b)));
    }
    if(a==x)cout<<"A"<<endl;
    else if(b==x)cout<<"B"<<endl;
    else if(c==x)cout<<"C"<<endl;
    else cout<<"D"<<endl;
     return 0;
}