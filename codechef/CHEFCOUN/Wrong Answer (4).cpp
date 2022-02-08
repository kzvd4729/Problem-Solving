/****************************************************************************************
*  @author: kzvd4729                                         created: 06-10-2017 16:44:10                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/OCT17/problems/CHEFCOUN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(long i=1;i<n;i++)
        {
            if(i==10)cout<<999<<" ";
            else if(i==45)cout<<991<<" ";
            else if(i==50)cout<<100000<<" ";
            else if(i==57)cout<<991<<" ";
            else if(i==100)cout<<999<<" ";
            else if(i==200)cout<<100000<<" ";
            else if(i==99981)cout<<990<<" ";
            else if(i==99971)cout<<100000<<" ";
            else if(i==99981)cout<<990<<" ";
                        else cout<<9999<<" ";
        }
        cout<<990<<endl;
    }
    return 0;
}