#include<bits/stdc++.h>
using namespace std;
int get_binary(int hour)// Function helps to convert a number to its binary code 
{
    int binary_hour[32];
    int i=0;
    while (hour > 0) {
        binary_hour[i] = hour % 2;
        hour = hour / 2;
        i++;
    }
    int count=0;
    for (int j = i - 1; j >= 0; j--)
    {
        if(binary_hour[j]==1)// counting for one bit
        {
            count+=1;
        }
    }
    return count; // returning the total count
}
void solve()
{
    int n;
    cin>>n;
    std::vector<string> arr;
    for(int hour=0;hour<12;hour++)
    {
        for(int minutes=0;minutes<60;minutes+=1)
        {
            if((get_binary(hour)+get_binary(minutes))==n)//calling Function and checking base case
            {
                cout<<hour<<":"<<minutes<<"  ";
                
            }
            
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        solve();
    }
    return 0;
}

//python code for leetcode
// class Solution:
//     def readBinaryWatch(self, turnedOn: int) -> List[str]:
//         result=[]
//         for hour in range(12):
//             for minutes in range(60):
//                 if((bin(hour)+bin(minutes)).count('1')==turnedOn):
//                     time='%d:%02d'%(hour,minutes)
//                     result.append(time)
//         return result