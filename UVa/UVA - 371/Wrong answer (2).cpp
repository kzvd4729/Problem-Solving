/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-02-28 12:25:35                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-371
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,i,x,cnt,mcnt,z;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)break;
        cout<<"Between "<<a<<" and "<<b<<", ";
        if(a>b)swap(a,b);
        mcnt=0;
        for(i=a;i<=b;i++)
        {
            x=i;
            cnt=0;
            while(x!=1)
            {
                if(x%2==0)x=x/2;
                else x=3*x+1;
                cnt++;
                //Between 1 and 20, 18 generates the longest sequence of 20 values.


            }
            if(cnt>mcnt)
            {
                mcnt=cnt;
                z=i;
            }

        }
        cout<<z<<" generates the longest sequence of "<<mcnt<<" values."<<endl;
    }

    return 0;
}