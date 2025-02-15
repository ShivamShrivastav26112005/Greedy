// Minimum product subset, Find the subset whose products is minimum and you have to return the product.

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int minproduct(vector<int> &arr){
    int cz=0; // count of zero 
    int cn=0; // count of negative
    int cp=0; // count of positive
    // to find the product of +ve no. and -ve no./ele.s.
    int prod_pos=1;
    int prod_neg=1;
    int lar_neg=INT_MIN;
    // checking the no.(either it is +ve,-ve or 0)
    for(int i=0; i<arr.size(); i++){
        if(arr[i]<0){
            cn++;
            prod_neg*=arr[i];
            lar_neg=max(lar_neg,arr[i]);
        } 
        if(arr[i]>0){
            prod_pos*=arr[i];
            cp++;
        }
        if(arr[i]==0) cz++;
    }
    if(cn==0){ 
        if(cz>0) return 0; 
        else{
            auto minimum=min_element(arr.begin(),arr.end());
            return *minimum;
        }
    }
    else{ 
        if(cn%2==0){ 
            return (prod_neg/lar_neg)*prod_pos;
        } 
        else{ 
            return prod_neg*prod_pos;
        }
    }
}
int main(){
    // vector<int>arr={-2,-3,1,4,-2}; // -48 (odd) no. of -ve
    // vector<int>arr={-2,-3,1,4,-2,-5}; // -120 (even) no. of -ve
    // vector<int>arr={0,1,2,3}; // 0 exists than ans = 0
    vector<int>arr={11,2,3}; // ans = 2 if 0 is not exists 
    cout<<minproduct(arr); 
}

