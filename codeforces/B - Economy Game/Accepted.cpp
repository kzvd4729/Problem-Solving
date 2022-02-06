/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/11/2017 19:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/681/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,i,j,k,x;
int main()
{
    ///810
    ///8100
    cin>>n;
    for(i=0; i<=810; i++)
    {
        for(j=0; j<=8100; j++)
        {
            x=n-((i*1234567)+(j*123456));
            if(x>-1&&x%1234==0)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}