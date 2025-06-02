#include<bits/stdc++.h>
using namespace std;

int MAH(vector<int>& arr){
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

    return maxHistogram;
}


int main(){

    // can find by help of max_Histogram and by 1D not 2d mean each row one by one as array
    vector<vector<int>>matrix = {{1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0} };  //6

    // first row push manually and find its MAH
    int n = matrix.size(), m = matrix[0].size();
    vector<int>v;
    for(int j=0; j<m; j++)
    {
        v.push_back(matrix[0][j]);
    }
    int maxi =  MAH(v);    //1
    // cout<<maxi;

    // all row's one by one, start from second
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(matrix[i][j] == 0) v[j] = 0;   //overwrite

            else v[j] = v[j] + matrix[i][j];
        }
        maxi = max(maxi, MAH(v));
    }

    cout<< maxi;
    return 0;
}


//leetcode =>  85. Maximal Rectangle
//link  =>  https://leetcode.com/problems/maximal-rectangle/submissions/1652037057/