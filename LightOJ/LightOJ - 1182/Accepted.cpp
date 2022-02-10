/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-02 22:02:57                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 44                                         memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1182
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,t,cnt,tc=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt=0;
        while(n)
        {
            if(n%2==1)
            {
                n--;
                cnt++;
            }
            n=n/2;
        }
        if(cnt%2==0)cout<<"Case "<<++tc<<": "<<"even"<<endl;
        else cout<<"Case "<<++tc<<": "<<"odd"<<endl;
    }
    return 0;
}