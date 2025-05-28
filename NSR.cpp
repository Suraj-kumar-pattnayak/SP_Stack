#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main(){

    vector<int>arr =  {4, 5, 2, 10, 8};   // [2, 2, -1, 8, -1]
    int n = arr.size();
    stack<int> st;
    vector<int> ans;

    for(int i= n-1; i>=0; i--){

        if(st.empty())  ans.push_back(-1);

        else if( !st.empty() && st.top() < arr[i]) ans.push_back(st.top());

        else if( !st.empty() && st.top() >= arr[i]){
             while( !st.empty() && st.top() >= arr[i]){
                st.pop();
             }
            if(st.empty())  ans.push_back(-1);
            else if(st.top() < arr[i]) ans.push_back(st.top());
            
        }
        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}