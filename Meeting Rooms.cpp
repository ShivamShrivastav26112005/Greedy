// Description
// Given an array of meeting time intervals consisting of start and end times
// [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

// ex-: 253 leetcode (paid)
// Input: intervals = [(0,30),(5,10),(15,20)]
// Output: 2

// Explanation:
// We need two meeting rooms
// room1: (0,30)
// room2: (5,10),(15,20)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int minMeetingRooms(vector<vector<int>> &intervals) {
        vector<int> start;
        vector<int> ending;
        for(auto ele : intervals){
            start.push_back(ele[0]);
            ending.push_back(ele[1]);
        }

        sort(start.begin(),start.end());
        sort(ending.begin(),ending.end());

        int ans=0;
        int rooms=0;
        int i=0; 
        int j=0;
        while(i<start.size() && j<ending.size()){
            if(start[i]<ending[j]){
                // meeting is starting   
                rooms++;
                i++;
                ans=max(ans,rooms);
            }
            else if(start[i]>ending[j]){
                // meeting is ending 
                rooms--;
                j++;
            }
            else{ // (starts[i]==ending[j]
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>>intervals = {{0,30},{5,10},{15,20}};
    Solution sol;
    cout<<sol.minMeetingRooms(intervals);
} // 2


