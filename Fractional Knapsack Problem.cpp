// Fractional Knapsack Problem.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// find ratio of value by weight
// custom compartor-:
bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    // pair<int,int> -> first = value/profit , second = weight

    // value by weight ratio of p1 and p2
    double r1 = (p1.first*1.0) / (p1.second*1.0);
    double r2 = (p2.first*1.0) / (p2.second*1.0);
    // pick those ratio(r1 or r2) which have max value by weight ratio
    return r1 > r2; 
}

// W is a capacity of knapsack , n is a no. of ele.s (how many times we perform the ops (n items))
double fractionalknapsack(vector<int> &profit, vector<int> &weights, int n, int W){ 
    vector<pair<int,int> > arr; // we push value by weight ratio so that we use pair of vector 
    
    // push all ele in the array arr
    for(int i=0; i<n; i++){
        arr.push_back({profit[i],weights[i]});
    }
    sort(arr.begin(),arr.end(),cmp); 

    double result=0;
    for(int i=0; i<n; i++){
        if(arr[i].second <= W){ 
            result += arr[i].first; 
            W -= arr[i].second;
        }
        else{ // pick partially 
            result += ((arr[i].first*1.0) / (arr[i].second*1.0))*W;
            W = 0; // full capacity of knapsack 
            break;
        }
    }
    return result;
}
int main(){
    vector<int> profit = {60,100,120};
    vector<int> weights = {10,20,30};
    int W=50; // capacity of knapsack 
    int n =3; // no. of ele.s 
    double maxProfit = fractionalknapsack(profit, weights, n, W);
    cout << "Maximum profit: " << maxProfit << endl;
}

// Maximum profit: 240

// T.C.= O(nlogn) S.C.=O(sorting algo)
