/****************************************************************************************
*  @author: kzvd4729                                         created: 07/18/2021 00:24                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 84 ms                                           memory_used: 22.7 MB                              
*  problem: https://leetcode.com/problems/rotated-digits
****************************************************************************************/
class Solution {
public:
    int rotatedDigits(int n) 
    {
        vector<int>v(10);
                v[0]=0;
        v[1]=1;
        v[2]=5;
        v[3]=-1;
        v[4]=-1;
        v[5]=2;
        v[6]=9;
        v[7]=-1;
        v[8]=8;
        v[9]=6;
                int x=n,cnt=0;
        for(int i=1;i<=x;i++)
        {
            n=i;
            vector<int>d;
            while(n)
            {
                d.push_back(n%10);
                n/=10;
            }
            reverse(d.begin(),d.end());
            int f=1,j=0;
            for(auto x:d)
            {
                if(v[x]==-1)f=0;
                                j=j*10+v[x];
            }
            if(i==j)f=0;
                        cnt+=f;
        }
        return cnt;
            }
};