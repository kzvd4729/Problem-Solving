/****************************************************************************************
*  @author: kzvd4729                                         created: 20-08-2017 23:46:26                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.14 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/COOK85/problems/GAMSTICK
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int t,n,xx1,xx2,yy1,yy2,c1,g,f;
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
        g=0;
        if(yy1==yy2)
        {
            cout<<"Draw"<<endl;
            g=1;
        }
        if(g==1)continue;
        f=0;
        if(yy1>yy2)
        {
            swap(xx1,xx2);
            swap(yy1,yy2);
            f=1;
        }
        if(yy1+1==yy2)
        {
            g=1;
            yy2=n-yy2+1;
            if(yy1>yy2)
            {
                if(f==0)
                {
                    cout<<"Miron"<<endl;
                }
                else cout<<"Slava"<<endl;
            }
            else cout<<"Draw"<<endl;
        }
        if(g==1)continue;
        c1=(yy2-yy1-1);
        if(c1%2==0)
        {
            if(xx1==xx2)
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
                yy1=yy1+c1/2;
                yy2=yy2+(c1/2)-1;
                if(yy1>n/2)
                {
                    if(f==0)
                    {
                        cout<<"Miron"<<endl;
                    }
                    else cout<<"Slava"<<endl;
                }
                else if(yy2>n/2)
                {
                    if(f==0)
                    {
                        cout<<"Slava"<<endl;
                    }
                    else cout<<"Miron"<<endl;
                }
                else cout<<"Draw"<<endl;
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
                int zz=0;
                if(yy1>yy2)
                {
                    if(f==0)
                    {
                        cout<<"Miron"<<endl;
                    }
                    else cout<<"Slava"<<endl;
                }
                else if(yy2>yy1)
                {
                    zz=1;
                    if(f==0)
                    {
                        cout<<"Slava"<<endl;
                    }
                    else cout<<"Miron"<<endl;
                }
                else
                {
                    if(zz==0)cout<<"Draw"<<endl;
                }
            }
        }
    }
    return 0;
}