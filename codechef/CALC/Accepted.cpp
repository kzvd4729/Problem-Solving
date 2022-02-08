/****************************************************************************************
*  @author: kzvd4729                                         created: 08-07-2017 11:39:09                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.01 sec                                        memory_used: 3.1M                                 
*  problem: https://www.codechef.com/JULY17/problems/CALC
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int t,n,b,in,pu,one,two,three,lo,hi,mid,ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>b;
        pu=n/b;
        lo=0;
        hi=pu;
        while(true)
        {
            mid=(lo+hi)/2;
            one=mid-1;
            one=one*(n-(one*b));
            two=mid;
            two=two*(n-(two*b));
            three=mid+1;
            three=three*(n-(three*b));
            if(one<two&&two<three)lo=mid+1;
            else if(one>two&&two>three)hi=mid-1;
            else
            {
                ans=max(one,max(two,three));
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}