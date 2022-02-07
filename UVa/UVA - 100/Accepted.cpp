/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-02-28 12:17:40                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 290                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-100
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,i,x,cnt,mcnt;
    while(cin>>a>>b)
    {
        cout<<a<<" "<<b<<" ";
        if(a>b)swap(a,b);
        mcnt=0;
        for(i=a;i<=b;i++)
        {
            x=i;
            cnt=1;
            while(x!=1)
            {
                if(x%2==0)x=x/2;
                else x=3*x+1;
                cnt++;


            }
            if(cnt>mcnt)mcnt=cnt;

        }
        cout<<mcnt<<endl;

    }

    return 0;
}