/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-13 19:57:14                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 8                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1008
****************************************************************************************/
#include<iostream>
#include<cmath>
using namespace std;
#define ll long long int
int main()
{
    ll t,n,m,x,tc=0,mid,a,b,c;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n;

            x=ceil(sqrt((double)n));

            mid=(((x*x)+((x-1)*(x-1))+1)/2);

            if(n==mid)cout<<"Case "<<++tc<<": "<<x<<" "<<x<<endl;



            else
            {
                if(x%2==1)
                {
                    if(n<mid)
                    {
                        a=x;
                        c=mid-n;
                        b=x-c;
                    }
                    else
                    {
                        b=x;
                        c=n-mid;
                        a=x-c;
                    }
                }

                else
                {
                    if(n>mid)
                    {
                        a=x;
                        c=n-mid;
                        b=x-c;
                    }
                    else
                    {
                        b=x;
                        c=mid-n;
                        a=x-c;
                    }

                }
                cout<<"Case "<<++tc<<": "<<a<<" "<<b<<endl;

            }


        }

    }

    return 0;
}