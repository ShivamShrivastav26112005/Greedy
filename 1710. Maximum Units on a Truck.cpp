// 1710. Maximum Units on a Truck. 

// You are assigned to put some amount of boxes onto one truck. 
// You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
// numberOfBoxesi is the number of boxes of type i.
// numberOfUnitsPerBoxi is the number of units in each box of the type i.
// You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. 
// You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.
// Return the maximum total number of units that can be put on the truck.



// Leetcode-1-:

bool cmp(vector<int> &a, vector<int> &b){ // sorting on the basis of profit in decreasing order (jiska profit max vo phle)
    return a[1]>b[1]; // if profit of (a) is greater than b than a comes first.

}
class Solution { // T.C.=O(sorting)=O(nlogn)
public:
// we write custom campartor for boxtypes array 
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp); // sorting done
        int profit=0;
        // traverse in the array 
        for(int i=0; i<boxTypes.size(); i++){ // [i][0] it is used becoz our vector is a 2d vector 
            if(boxTypes[i][0]<=truckSize) {// check quantity of current boxTypes if less than or equal to trucksize then picks
            profit+=boxTypes[i][0]*boxTypes[i][1]; // boxTypes[i][0] (quantity) * boxTypes[i][1] (cost of one box)
            //  each box ko multiply kar dete h cost of one box se 
            truckSize-=boxTypes[i][0];
        }
        else{ // pick remaining truckSize (truckSize)
            profit+=truckSize*boxTypes[i][1]; 
            truckSize=0;
        }
        if(truckSize==0) break;
    }
    return profit;
    }
};




// https://leetcode.com/problems/maximum-units-on-a-truck/

// leetcode - 1710 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// custom compartor
bool cmp(vector<int> &a, vector<int> &b){ // sorting on the basis of profit in decreasing order (jiska profit max vo phle)
    return a[1]>b[1]; // if profit of (a) is greater than b than a comes first.

}

class Solution { // T.C.=O(sorting)=O(nlogn) , S.C.=O(sorting)
public:

// we write custom campartor for boxtypes array 
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp); // sorting done
        int profit=0;
        // traverse in the array 
        for(int i=0; i<boxTypes.size(); i++){ // [i][0] it is used becoz our vector is a 2d vector 
            if(boxTypes[i][0]<=truckSize) {// check quantity of current boxTypes if less than or equal to trucksize then picks
            profit+=boxTypes[i][0]*boxTypes[i][1]; // boxTypes[i][0] (quantity) * boxTypes[i][1] (cost of one box)
            //  each box ko multiply kar dete h cost of one box se 
            truckSize-=boxTypes[i][0];
        }
        else{ // pick remaining truckSize (truckSize)
            profit+=truckSize*boxTypes[i][1]; 
            truckSize=0;
        }
        if(truckSize==0) break;
    }
    return profit;
    }
};

int main(){

    vector<vector<int>> boxTypes ={{1,3},{2,2},{3,1}};
    int truckSize = 4;
    Solution sol;
    cout<<sol.maximumUnits(boxTypes ,truckSize);

} // 8




// Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
// Output: 8
// Explanation: There are:
// - 1 box of the first type that contains 3 units.
// - 2 boxes of the second type that contain 2 units each.
// - 3 boxes of the third type that contain 1 unit each.
// You can take all the boxes of the first and second types, and one box of the third type.
// The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.



