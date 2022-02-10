/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-31 14:47:23                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1346
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,n;
double x,y,xx,xx2,yy,yy2,xx3,yy3,ax,a1,a2,b1,b2,c1,c2,ans;
//A = y2-y1
//B = x1-x2
//C = A*x1+B*y1
//double det = A1*B2 - A2*B1
//    if(det == 0){
//        //Lines are parallel
//    }else{
//        double x = (B2*C1 - B1*C2)/det
//        double y = (A1*C2 - A2*C1)/det
//    }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin>>t;
    while(t--)
    {
        cin>>n>>ax;
        xx=ax;
        yy=0;
        cin>>xx2>>yy2;
        ans=0;
        double mn=-9999999999;
        for(int i=2;i<=n;i++)
        {
            cin>>xx3>>yy3;
            if(yy2>mn)
            {
                a1=yy2-yy;
                b1=xx-xx2;
                c1=a1*xx+b1*yy;
                mn=yy2;
                ///cout<<i<<" "<<xx2<<" "<<yy2<<endl;
            }
            ///cout<<mn<<endl;
            a2=yy3-yy2;
            b2=xx2-xx3;
            c2=a2*xx2+b2*yy2;
            ///if(i==6)cout<<a2<<" "<<b2<<" 666666"<<endl;


            double det=a1*b2-a2*b1;
            ///if(i==6)cout<<det<<" det"<<endl;
            if(det!=0)
            {
                x=(b2*c1-b1*c2)/det;
                y=(a1*c2-a2*c1)/det;
                ///if(i==6)cout<<x<<" x y "<<y<<endl;
                if(yy3>yy2&&x>=xx2&&x<=xx3&&y>=yy2&&y<=yy3)
                {
                    ///cout<<"yea "<<i<<" "<<x<<" "<<y<<" "<<endl;
                    ///cout<<"yea"<<" "<<sqrt((xx3-x)*(xx3-x)+(yy3-y)*(yy3-y))<<endl;
                    ans+=sqrt((xx3-x)*(xx3-x)+(yy3-y)*(yy3-y));
                }
            }
            xx2=xx3;
            yy2=yy3;
        }
        cout<<"Case "<<++tc<<": "<<setprecision(12)<<fixed<<ans<<endl;
    }
    return 0;
}