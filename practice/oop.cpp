#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(vector<int>& tmp, int ind){
        int ans = -1;
        int min = INT_MAX;
        for(unsigned int i = ind + 1; i < tmp.size(); i++){
            if(tmp[i] > tmp[ind] && (tmp[i] - tmp[ind] < min)){
                min = tmp[i] - tmp[ind];
                ans = i;
            }
        }
        return ans;
    }
    long long nextGreaterElement(int n) {
        // string s = to_string(n);
        // stack<int> st;
        stack<int> sttmp;
        // vector<int> right(s.length(), -1);
        vector<int> tmp;
        while(n!=0){
            sttmp.push(n%10);
            n/=10;
        }
        while(!sttmp.empty()){
            tmp.push_back(sttmp.top());
            sttmp.pop();
        }
        // for(int i = tmp.size() - 1; i >= 0; i--){
        //     while(!st.empty() && tmp[st.top()] < tmp[i]) st.pop();
        //     if(!st.empty()) right[i] = st.top();
        //     st.push(i);
        // }

        int ind = tmp.size() - 2;
        while(ind >= 0 && tmp[ind] >= tmp[ind+1]) ind--;
        if(ind == -1) return -1;
        // if(right[ind] == -1) return -1;

        int k = find(tmp, ind);
        if(k == -1) return -1;

        int tmp1;
        tmp1 = tmp[ind];
        tmp[ind] = tmp[k];
        tmp[k] = tmp1;
        
        sort(tmp.begin() + ind + 1, tmp.end());

        long long ans = 0;
        for(unsigned int i = 0; i < tmp.size(); i++){
            ans*=10;
            ans+=tmp[i];
        }

        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    Solution* oop = new Solution;
    long long ans = oop->nextGreaterElement(n);
    cout << ans << endl;
    delete oop;
    return 0;
}