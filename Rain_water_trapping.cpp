#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr = {3, 0, 0, 2, 0, 4};    //10
    int n= arr.size();
    vector<int>lmax;
    int rmax[n];
    vector<int>water;

    lmax.push_back(arr[0]);
    for(int i=1; i<n; i++)
    {
        lmax.push_back(max(lmax[i-1], arr[i]));
    }

    rmax[n-1] = arr[n-1];
    for(int i= n-2; i>=0; i--)
    {
        rmax[i] = (max(rmax[i+1], arr[i]));
    }
    //water for each building
    int sum =0;
    for(int i=0; i<n; i++)
    {
        water.push_back(min(lmax[i] , rmax[i]) - arr[i]);
        sum += water[i];
    }

    // int sum =0;
    // for(int i=0; i<n; i++)
    // {
    //     sum += water[i];
    // }
    cout<<"ANS = "<<sum;
    return 0;
}



// leetcode =>   42. Trapping Rain Water
// Link =>     https://leetcode.com/problems/trapping-rain-water/submissions/1659990622/
