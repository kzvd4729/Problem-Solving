/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-15 16:28:20                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 20                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10954
****************************************************************************************/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
long long int arr[100009];
int main()
{
    long long int n,i,sum,x,y,z,l,temp;
    while(cin>>n)
    {
        if(n==0)break;
        for(i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);


        if(n==1)
        {
            cout<<arr[0]<<endl;
        }
        else if(n==2)
        {
            cout<<arr[0]+arr[1]<<endl;
        }
        else
        {
            priority_queue<int>pq;

            l=pq.size();
            for(i=0;i<l;i++)
            {
                pq.pop();
            }

            for(i=0;i<n;i++)
            {
                temp=arr[i]*(-1);
                pq.push(temp);
            }

            l=pq.size();

            /*for(i=0;i<l;i++)
            {
                cout<<pq.top()<<endl;
                pq.pop();
            }*/

            sum=0;

            while(pq.size()>=2)
            {
                x=pq.top()*(-1);
                pq.pop();
                y=pq.top()*(-1);
                pq.pop();

                //cout<<x<<" "<<y<<endl;

                z=x+y;

                temp=z*(-1);

                pq.push(temp);

                sum=sum+z;

            }



            cout<<sum<<endl;

        }




    }


    return 0;
}