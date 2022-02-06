/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/24/2017 20:55                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/777/problem/A
****************************************************************************************/
#include<iostream>
using namespace std;
int main()
{
    long long int n,x,arr[]={0,1,2};
    cin>>n>>x;
    int z=n%6;
    for(int i=1;i<=z;i++)
    {
        if(i%2==1)
        {
            swap(arr[0],arr[1]);
        }
        else swap(arr[1],arr[2]);
    }
     cout<<arr[x]<<endl;
      return 0;
}