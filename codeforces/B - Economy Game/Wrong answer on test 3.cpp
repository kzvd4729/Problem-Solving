/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/11/2017 19:28                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/681/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,i,j,k,x;
int main()
{
    cin>>n;
    for(i=0; i<=100; i++)
    {
        for(j=0; j<=100; j++)
        {
            for(k=0; k<=100; k++)
            {
                x=(i*1234567)+(j*123456)+(k*1234);
                if(x==n)
                {
                    cout<<"YES"<<endl;
                    return 0;
                }
                if(x>n)break;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}