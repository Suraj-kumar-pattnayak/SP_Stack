#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main(){
    // // int arr[] = {6, 8, 0, 1, 3}; // [8, -1, 1, 3, -1]
    // // int n  = sizeof(arr)/sizeof(arr[0]);
    vector<int>arr =  {1, 3, 2, 4};   //[3 4 4 -1]
    // vector<int> ans;   
    // for(int i=0; i< arr.size(); i++){

    //     bool flag = false;
    //     for(int j= i+1; j< arr.size(); j++)
    //     {
    //         if(arr[j] > arr[i]) { ans.push_back(j-i);    flag = true; break;}

    //     }
    //     if(flag == false) ans.push_back(-1);
    // }

    // for(int i=0; i<ans.size(); i++)
    // {
    //     cout<<ans[i]<<" ";
    // }
    int n = arr.size();
    stack<int>st;
    vector<int>ans;
    for(int i= n-1; i>=0; i--)
    {   
                                                                                                                        // bool flag = false;
                                                                                                                        // while(!st.empty()){
                                                                                                                        //     if(st.top() > arr[i]) {
                                                                                                                        //         arr[i] = st.top();
                                                                                                                        //         flag = true;
                                                                                                                        //         break;
                                                                                                                        //     }
                                                                                                                        //     else st.pop();
                                                                                                                        // }
                                                                                                                        // if(flag == false) arr[i] = -1;

        if(st.empty()) ans.push_back(-1);

        else if(!st.empty() && st.top() > arr[i]) ans.push_back(st.top());

        else if(!st.empty() && st.top() <= arr[i]) {

            while(!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }

            if(st.empty()) ans.push_back(-1);
            else if(!st.empty() && st.top() > arr[i]) ans.push_back(st.top());
        }
        //at last
        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }

    // while(!st.empty()){
    //    cout<< st.top()<<" ";
    //     st.pop();
    // }
    return 0;
}
