/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2017 07:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/143/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r1,r2,c1,c2,d1,d2,x1,x2,x3,x4,f;
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    x1=r1;
    f=0;
    while(x1--)
    {
        x2=r1-x1;
        x3=c1-x1;
        x4=d1-x1;
        if(x1>=1&&x1<=9&&x2>=1&&x2<=9&&x3>=1&&x3<=9&&x4>=1&&x4<=9&&x1!=x2&&x1!=x3&&x1!=x4&&x2!=x3&&x2!=x4&&x3!=x4)
        {
            if(x1+x2==r1&&x3+x4==r2&&x1+x3==c1&&x2+x4==c2&&x1+x4==d1&&x2+x3==d2)
            {
                f=1;
                break;
            }
        }
            }
    if(f==0)cout<<-1<<endl;
    else cout<<x1<<" "<<x2<<endl<<x3<<" "<<x4<<endl;
    return 0;
}