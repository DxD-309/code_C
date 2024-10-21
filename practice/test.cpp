#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        nums.push_back(val);
    }
    vector<int> pre(nums.size(), 1);
    vector<int> suf(nums.size(), 1);
    for(int i = 1; i < nums.size(); i++){
        pre[i] *= nums[i-1]*pre[i-1];
    }
    for(int i = nums.size() - 2; i >= 0; i--){
        suf[i] *= nums[i+1]*suf[i+1];
    }
    for(int i = 0; i < nums.size(); i++){
        cout << pre[i] << " ";
    }
    cout << endl;
    cout << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << suf[i] << " ";
    }
    cout << endl;
    return 0;
}