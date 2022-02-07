/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-06 17:54:22                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 10                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-694
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,r,tc=0;
    while(cin>>n>>r)
    {
        if(n==-1&&r==-1)break;
        int cnt=0;
        int x=n;
        while(1)
        {
           if(n==1)
           {
               cnt++;
               break;
           }
           if(n>r)break;

            if(n%2==0)n=n/2;
            else n=3*n+1;

            cnt++;

        }
        cout<<"Case "<<++tc<<": A = "<<x<<", limit = "<<r<<", number of terms = "<<cnt<<endl;


    }

    return 0;
}