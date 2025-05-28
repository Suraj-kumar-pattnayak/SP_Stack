// we have to find consecutive smaller or equal before it.  // if nothing 1, bcs including that element
//so we are stopping when finding greater nearer to nearer. 
// NGL
#include<bits/stdc++.h>
using namespace std;
int main(){

    // NGL concept is helpful
    vector<int>arr = {100, 80 ,60, 70, 60, 75, 85}; // [1, 1, 1, 2, 1, 4, 6]
    stack<pair<int , int>>st;
    int n = arr.size();
    vector<int>ans;
    for(int i=0; i<n; i++){
    
        if(st.empty()  || st.top().first > arr[i]) ans.push_back(1);

        else if(!st.empty() && st.top().first <= arr[i]){

            while(!st.empty() && st.top().first <= arr[i]){
                st.pop();
            }
            if(st.empty()) ans.push_back(i + 1);

            else if(st.top().first > arr[i]) ans.push_back(i - st.top().second);
        }
        
        st.push({arr[i] , i});
    }
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}



// leetcode  link =>    https://leetcode.com/problems/online-stock-span/submissions/1646891361/
 