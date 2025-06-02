#include<bits/stdc++.h>
using namespace std;
int main(){

    //suppose to find NSL and NSR   
    vector<int>arr = {2, 1, 5, 6, 2, 3}; // 10
    int n = arr.size();
    stack<pair<int , int>>st;
    vector<int>NSL_ans;
    //NSL
    for(int i=0; i<n; i++)    // -1, -1, 1, 2, 1, 4
    {   
        if(st.empty())  NSL_ans.push_back(-1);

        else if(st.top().first < arr[i]) NSL_ans.push_back(st.top().second);

        else if(st.top().first >= arr[i]){
            while(!st.empty() && st.top().first >= arr[i]){
                st.pop();
            }
            if(st.empty()) NSL_ans.push_back(-1);
            else if(st.top().first < arr[i]) NSL_ans.push_back(st.top().second);
        }
        
        st.push({arr[i], i});
    }


    // for(int i=0; i<arr.size(); i++){
    //     cout<<NSL_ans[i]<<" ";
    // }
    cout<<"\n";
    // clear the stack before reusing
    while(!st.empty()) st.pop();
    vector<int>NSR_ans;
    //NSL
    for(int i=n-1; i>=0; i--)    //1, -1, 4, 4, -1, -1 
    {   
        if(st.empty())  NSR_ans.push_back(arr.size());

        else if(st.top().first < arr[i]) NSR_ans.push_back(st.top().second);

        else if(st.top().first >= arr[i]){
            while(!st.empty() && st.top().first >= arr[i]){
                st.pop();
            }
            if(st.empty()) NSR_ans.push_back(arr.size());
            else if(st.top().first < arr[i]) NSR_ans.push_back(st.top().second);
        }
        
        st.push({arr[i], i});
    }

reverse(NSR_ans.begin(), NSR_ans.end());
    // for(int i=0; i<arr.size(); i++){
    //     cout<<NSR_ans[i]<<" ";
    // }

    int maxHistogram = 0;
    for(int i=0; i<n; i++){
        maxHistogram = max(maxHistogram,(NSR_ans[i] - NSL_ans[i] - 1) * arr[i]);
    }
    cout<<maxHistogram;
    return 0;
}


//leetcode =>  84. Largest Rectangle in Histogram
//link  =>  https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/1651963967/