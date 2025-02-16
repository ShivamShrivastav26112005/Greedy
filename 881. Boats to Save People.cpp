
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // sort the array people in increasing order 
        sort(people.begin(),people.end()); // O(nlogn)

        // two pointer algo. used here 
        int i=0;
        int j=people.size()-1;

        // boats
        int boats=0;
        while(i<=j){ // O(n)
            if(people[i]+people[j]<=limit){ // pair 
                boats++; // allocate a boat to the pair(boat is allocated with the pair)
                i++;
                j--;
            }
            else{
                boats++; // allocate a boat to the heaviest(last boat is added and j--) 
                j--;
            }
        }
        return boats;
    }
};

int main(){
    vector<int> people = {1,2};
    int limit = 3;
    Solution sol;
    cout<<sol.numRescueBoats(people,limit);

} // 1






// Leetcode Solution -: 

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int count=0;
        sort(people.begin(), people.end());
        int i=0;
        int j=n-1;
        while(i<=j){
            int sum=people[i]+people[j];
            if(sum<=limit){
                count++;
                i++;
                j--; 
            }else{
                count++;
                j--; 
            }
        }
        return count; 
    }
};




// Leetcode -> 881
// T.C.=O(sorting used)=O(nlogn), while loop runs n times O(n)
// Overall T.C.=O(nlogn)+O(n) = O(nlogn)

// S.C.=O(sorting)
// https://leetcode.com/problems/boats-to-save-people/

// Leetcode -> 881
// T.C.=O(sorting used)=O(nlogn), while loop runs n times O(n)
// Overall T.C.=O(nlogn)+O(n) = O(nlogn)

// S.C.=O(sorting)
// https://leetcode.com/problems/boats-to-save-people/


