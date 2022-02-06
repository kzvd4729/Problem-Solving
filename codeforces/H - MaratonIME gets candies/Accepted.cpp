/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2017 19:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/gym/101375/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
char c;
int lo,hi,mid;
int main()
{
    lo=1;
    hi=1000000000;
    while(true)
    {
        mid=(lo+hi)/2;
        cout<<"Q"<<" "<<mid<<endl;
        cout.flush();
        cin>>c;
        if(c=='>')
        {
            lo=mid+1;
        }
        else if(c=='<')
        {
            hi=mid-1;
        }
        else return 0;
    }
    return 0;
}