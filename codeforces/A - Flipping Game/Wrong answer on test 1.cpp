/****************************************************************************************
*  @author: kzvd4729                                         created: May/03/2017 14:17                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/327/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,arr[103],c,mx,lo,hi,llo;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    c=0;
    mx=0;
    lo=0;
    for(i=1;i<=n;i++)
    {
        if(arr[i]==1)
        {
            c--;
            if(c<0)
            {
                c=0;
                lo=i;
            }
        }
        else 
        {
            c++;
        }
        if(c>mx)
        {
            mx=c;
            hi=i;
            llo=lo;
        }
    }
    /*cout<<mx<<endl;
    cout<<llo<<" "<<hi<<endl;*/
    int one=0;
    for(i=1;i<=lo;i++)
    {
        if(arr[i]==1)one++;
    }
    for(i=hi+1;i<=n;i++)
    {
        if(arr[i]==1)one++;
    }
    for(i=lo+1;i<=hi;i++)
    {
        if(arr[i]==1)one++;
    }
    if(mx==0)one--;
    cout<<one+mx<<endl;
    cout<<one<<mx<<endl;
    return 0;
}