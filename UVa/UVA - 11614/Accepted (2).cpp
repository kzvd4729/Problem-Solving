/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-12 11:16:56                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11614
****************************************************************************************/
#include<iostream>
using namespace std;
int main()
{
    long long int t,n,lo,md,hi,x,xx;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n;

            if(n==0)
            {
                cout<<0<<endl;
            }
            else
            {


                lo=1;
                hi=10e9;

                while(lo<=hi)
                {
                    md=(lo+hi)/2;

                    x=(md*(md+1))/2;

                    xx=((md+1)*(md+2))/2;

                    //cout<<md<<endl;

                    if(x<=n&&xx>n)break;
                    else if(x<n)
                    {
                        lo=md+1;
                    }

                    else
                    {
                        hi=md-1;
                    }


                }
                cout<<md<<endl;
            }
        }

    }

    return 0;
}