/****************************************************************************************
*  @author: kzvd4729                                         created: 20-08-2017 23:02:12                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.14 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/COOK85/problems/GAMSTICK
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,xx1,xx2,yy1,yy2,c1;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>xx1>>yy1>>xx2>>yy2;
        long g=0;
        if(yy1==yy2)
        {
            cout<<"Draw"<<endl;
            g=1;
        }
        if(g==1)continue;
        long f=0;
        if(yy1>yy2)
        {
            swap(xx1,xx2);
            swap(yy1,yy2);
            f=1;
        }
        if(yy1+1==yy2)
        {
            yy2=n-yy2+1;
            if(yy1>yy2)
            {
                if(f==0)
                {
                    cout<<"Miron"<<endl;
                }
                else cout<<"Miron"<<endl;
            }
            else cout<<"Draw"<<endl;
        }
        ///cout<<yy1<<" "<<yy2<<endl;
        c1=(yy2-yy1-1);
        if(c1%2==0)
        {
            yy1=yy1+c1/2;
            yy2=yy2-c1/2;
            yy2=n-yy2+1;
            if(yy1==yy2)
            {
                cout<<"Draw"<<endl;
            }
            else if(yy1>yy2)
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
            if(xx1==xx2)
            {
                yy1=yy1+c1/2+1;
                yy2=yy2-c1/2;
                yy2=n-yy2+1;
                if(yy1==yy2)
                {
                    cout<<"Draw"<<endl;
                }
                else if(yy1>yy2)
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
                yy1=yy1+c1/2;
                yy2=yy2-c1/2;
                yy2=n-yy2+1;
                if(yy1==yy2)
                {
                    cout<<"Draw"<<endl;
                }
                else if(yy1>yy2)
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