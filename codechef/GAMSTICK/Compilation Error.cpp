/****************************************************************************************
*  @author: kzvd4729                                         created: 20-08-2017 22:37:41                      
*  solution_verdict: Compilation Error                       language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/COOK85/problems/GAMSTICK
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,x1,x2,y1,y2,c1;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>x1>>y1>>x2>>y2;
        long f=0;
        if(y1>y2)
        {
            swap(x1,x2);
            swap(y1,y2);
            f=1;
        }
        ///cout<<y1<<" "<<y2<<endl;
        c1=(y2-y1-1);
        if(c1%2==0)
        {
            y1=y1+c1/2;
            y2=y2-c1/2;
            y2=n-y2+1;
            if(y1==y2)
            {
                cout<<"Draw"<<endl;
            }
            else if(y1>y2)
            {
                if(f==0)
                {
                    cout<<"Miron"<<endl;
                }
                else cout<<"Slava"<<endl;
            }
            else
            {
                if(f==0)
                {
                    cout<<"Slava"<<endl;
                }
                else cout<<"Miron"<<endl;
            }
        }
        else
        {
            if(x1==x2)
            {
                y1=y1+c1/2+1;
                y2=y2-c1/2;
                y2=n-y2+1;
                if(y1==y2)
                {
                    cout<<"Draw"<<endl;
                }
                else if(y1>y2)
                {
                    if(f==0)
                    {
                        cout<<"Miron"<<endl;
                    }
                    else cout<<"Slava"<<endl;
                }
                else
                {
                    if(f==0)
                    {
                        cout<<"Slava"<<endl;
                    }
                    else cout<<"Miron"<<endl;
                }
            }
            else
            {
                y1=y1+c1/2;
                y2=y2-c1/2;
                y2=n-y2+1;
                if(y1==y2)
                {
                    cout<<"Draw"<<endl;
                }
                else if(y1>y2)
                {
                    if(f==0)
                    {
                        cout<<"Miron"<<endl;
                    }
                    else cout<<"Slava"<<endl;
                }
                else
                {
                    if(f==0)
                    {
                        cout<<"Slava"<<endl;
                    }
                    else cout<<"Miron"<<endl;
                }
            }
        }
    }
    return 0;
}