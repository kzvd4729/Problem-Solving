/****************************************************************************************
*  @author: kzvd4729                                         created: 21-01-2018 23:00:08                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15.7M                                
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
        if((d1+d2)%10==0||(d1+d2)%10==5)
        {
            cout<<"NO"<<endl;
        }
        else if((d1+d2)%10==1)
        {
            if(k==2)x=1;
            else if(k==3)x=2;
            else
            {
                x=2;
                k-=3;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)x+=2;
                if(k==2)x+=6;
                if(k==3)x+=14;
                if(x%3==0)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
        else if((d1+d2)%10==2)
        {
            if(k==2)x=2;
            else
            {
                x=2;
                k-=2;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)x+=2;
                if(k==2)x+=6;
                if(k==3)x+=14;
                if(x%3==0)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
        else if((d1+d2)%10==3)
        {
            if(k==2)x=3;
            else if(k==3)x=6;
            else
            {
                x=6;
                k-=3;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)x+=6;
                if(k==2)x+=8;
                if(k==3)x+=12;
                if(x%3==0)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
        else if((d1+d2)%10==4)
        {
            if(k==2)x=4;
            else
            {
                x=4;
                k-=2;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)x+=4;
                if(k==2)x+=12;
                if(k==3)x+=18;
                if(x%3==0)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
        else if((d1+d2)%10==6)
        {
            if(k==2)x=6;
            else
            {
                x=6;
                k-=2;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)x+=6;
                if(k==2)x+=8;
                if(k==3)x+=12;
                if(x%3==0)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
        else if((d1+d2)%10==7)
        {
            if(k==2)x=7;
            else if(k==3)x=14;
            else
            {
                x=14;
                k-=3;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)x+=4;
                if(k==2)x+=12;
                if(k==3)x+=18;
                if(x%3==0)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
        else if((d1+d2)%10==8)
        {
            if(k==2)x=8;
            else
            {
                x=8;
                k-=2;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)x+=6;
                if(k==2)x+=8;
                if(k==3)x+=12;
                if(x%3==0)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
        else if((d1+d2)%10==9)
        {
            if(k==2)x=9;
            else if(k==3)x=18;
            else
            {
                x=18;
                k-=3;
                x=(x+((k/4)*2))%3;
                k=k%4;
                if(k==1)x+=8;
                if(k==2)x+=14;
                if(k==3)x+=16;
                if(x%3==0)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}