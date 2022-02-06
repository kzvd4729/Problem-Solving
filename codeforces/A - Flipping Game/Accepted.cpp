/****************************************************************************************
*  @author: kzvd4729                                         created: May/04/2017 14:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/327/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,arr[103],r,lo,hi,one=0,qm,mx=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]==1)one++;
    }
    r=0;
    while(++r)
    {
        if(r>n)break;
        lo=0;
        hi=r-1;
        while(1)
        {
            lo++;
            hi++;
            if(hi>n)break;
            qm=0;
            for(i=lo;i<=hi;i++)
            {
                if(arr[i]==1)qm--;
                else qm++;
            }
            if(qm+one>mx)mx=qm+one;
        }
     }
    cout<<mx<<endl;
    return 0;
}