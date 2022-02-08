/****************************************************************************************
*  @author: kzvd4729                                         created: 21-01-2018 23:25:26                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/COOK90/problems/MULTHREE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,k,d1,d2,x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>k>>d1>>d2;
        if((d1+d2)%10==0)
        {
            cout<<"NO"<<endl;
        }
        else if((d1+d2)%10==5)
        {
            if(k==2)
                x=d1+d2;
            else
                x=d1+d2+5;
            if(x%3==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if((d1+d2)%10==1)
        {
            if(k==2)
                x=d1+d2;
            else if(k==3)
                x=d1+d2+1;
            else
            {
                x=d1+d2+1;
                k-=3;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)
                    x+=2;
                if(k==2)
                    x+=6;
                if(k==3)
                    x+=14;
            }
            if(x%3==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if((d1+d2)%10==2)
        {
            if(k==2)
                x=d1+d2;
            else
            {
                x=d1+d2;
                k-=2;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)
                    x+=2;
                if(k==2)
                    x+=6;
                if(k==3)
                    x+=14;
            }
            if(x%3==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if((d1+d2)%10==3)
        {
            if(k==2)
                x=d1+d2;
            else if(k==3)
                x=d1+d2+3;
            else
            {
                x=d1+d2+3;
                k-=3;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)
                    x+=6;
                if(k==2)
                    x+=8;
                if(k==3)
                    x+=12;
            }
            if(x%3==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if((d1+d2)%10==4)
        {
            if(k==2)
                x=d1+d2;
            else
            {
                x=d1+d2;
                k-=2;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)
                    x+=4;
                if(k==2)
                    x+=12;
                if(k==3)
                    x+=18;
            }
            if(x%3==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if((d1+d2)%10==6)
        {
            if(k==2)
                x=d1+d2;
            else
            {
                x=d1+d2;
                k-=2;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)
                    x+=6;
                if(k==2)
                    x+=8;
                if(k==3)
                    x+=12;
            }
            if(x%3==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if((d1+d2)%10==7)
        {
            if(k==2)
                x=d1+d2;
            else if(k==3)
                x=d1+d2+7;
            else
            {
                x=d1+d2+7;
                k-=3;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)
                    x+=4;
                if(k==2)
                    x+=12;
                if(k==3)
                    x+=18;
            }
            if(x%3==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if((d1+d2)%10==8)
        {
            if(k==2)
                x=d1+d2;
            else
            {
                x=d1+d2;
                k-=2;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)
                    x+=8;
                if(k==2)
                    x+=14;
                if(k==3)
                    x+=16;
            }
            if(x%3==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if((d1+d2)%10==9)
        {
            if(k==2)
                x=d1+d2;
            else if(k==3)
                x=d1+d2+9;
            else
            {
                x=d1+d2+9;
                k-=3;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)
                    x+=8;
                if(k==2)
                    x+=14;
                if(k==3)
                    x+=16;
            }
            if(x%3==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}