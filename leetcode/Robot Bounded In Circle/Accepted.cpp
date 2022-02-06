/****************************************************************************************
*  @author: kzvd4729                                         created: 06/10/2021 19:37                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 0 ms                                            memory_used: 6.1 MB                               
*  problem: https://leetcode.com/problems/robot-bounded-in-circle
****************************************************************************************/
class Solution {
public:
    bool isRobotBounded(string s) 
    {
        int x=0,y=0,dx=0,dy=1;
        for(int i=1; ;i++)
        {
            for(auto c:s)
            {
                if(c=='L')
                {
                    if(dx==0)
                    {
                        dx=-dy;
                        dy=0;
                    }
                    else 
                    {
                        dy=dx;
                        dx=0;
                    }
                }
                else if(c=='R')
                {
                    if(dx==0)
                    {
                        dx=dy;
                        dy=0;
                    }
                    else 
                    {
                        dy=-dx;
                        dx=0;
                    }
                }
                else x+=dx,y+=dy;
            }
            if((dx==0) && (dy==1))break;
        }
        return (x==0) && (y==0);
    }
};