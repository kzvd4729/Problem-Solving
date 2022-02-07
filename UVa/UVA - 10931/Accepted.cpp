/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-07 21:24:53                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10931
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int I,x,cnt,id,i,arr[1000];
    while(cin>>I)
    {
        if(I==0)break;
        x=I;
        cnt=0;
        id=-1;
        while(x)
        {
            if(x%2==1)
            {
                x--;
                x=x/2;
                arr[++id]=1;
                cnt++;
            }
            else 
            {
                x=x/2;
                arr[++id]=0;
            }
        }
        cout<<"The parity of ";
        for(i=id;i>=0;i--)
        {
            cout<<arr[i];
        }
        cout<<" is "<<cnt<<" (mod 2)."<<endl;
        
    }
    return 0;
}