/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-11 20:13:19                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11332
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int digit_sum(long long int m)
{
    long long int x=0,r;
    while(m)
    {
        r=m%10;
        m=m/10;
        x=x+r;
    }
    return x;
}
int main()
{
    long long int n;
    while(cin>>n)
    {
        if(n==0)break;
        while(n>=10)
        {
            n=digit_sum(n);
        }
        cout<<n<<endl;
    }
    return 0;
}