/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-14 01:44:58                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-424
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
int arr[1005];
int main()
{
    int l,i,c,k,f,n,x;
    memset(arr,0,sizeof(arr));
    while(cin>>s)
    {
        if(s!="0")
        {
            l=s.size();
            c=0;
            k=-1;
            for(i=l-1; i>=0; i--)
            {
                k=k+1;
                n=s[i]-'0';
                x=arr[k]+n+c;
                arr[k]=x%10;
                c=x/10;
            }
            while(c)
            {
                k=k+1;
                x=arr[k]+c;
                arr[k]=x%10;
                c=x/10;
            }
        }
        else
        {
            f=0;
            for(i=1000;i>=0;i--)
            {
                if(arr[i]>0||f==1)
                {
                    cout<<arr[i];
                    f=1;
                }
            }
            cout<<endl;
        }

    }
    return 0;
}