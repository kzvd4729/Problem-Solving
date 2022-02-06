/****************************************************************************************
*  @author: kzvd4729#                                        created: May/11/2017 17:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/743/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,k,i;
    cin>>n>>k;
    int f=0;
    while(true)
    {
        for(i=0;i<=50;i++)
        {
            if(pow(2,i)==k)
            {
                f=1;
                break;
            }
            if(pow(2,(i+1))>k)
            {
                k=k-pow(2,i);
                break;
            }
        }
        if(f==1)break;
    }
    cout<<i+1<<endl;
    return 0;
}