// Ques-> Maximize sum of the array after 'k' negation. Leetcode -> 1005.


#include<iostream>
#include<queue> 
#include<vector>
using namespace std;

class Solution { // Total T.C. = O(klogn+n)
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n=nums.size();        
        // Minheap -:
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=0; i<n; i++){ 
            pq.push(nums[i]); 
        }

        int sum=0;
        for(int i=0; i<n; i++) sum+=nums[i];
        
        while(k--){
            int ele=pq.top();

            if(ele==0){ 
                break;
            }
            pq.pop(); 
            sum-=ele;
            pq.push(-1*ele); 
            sum+=(-ele);
            // k push and k pop ho rha hai to T.C.=O(klogn)+O(klogn)
            // Overall O(klogn)+O(klogn)=O(klogn) then, our while loop is run in O(klogn) T.C. me 
        }
        cout<<sum;
    }
};

int main(){
    int num[] = {4,2,3};
    int n=sizeof(num)/sizeof(num[0]);
    vector<int>nums(num,num+n);
    int k = 1;
    Solution sol;
    sol.largestSumAfterKNegations(nums,k);
}

// O/P -: 5 






