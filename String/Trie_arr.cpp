#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;

struct Trie{
    struct node{
        int child[26];
        int cnt, exist;
    } nodes[maxn];

    int cur;
    Trie(): cur(0){
        memset(nodes[0].child, -1, sizeof(nodes[0].child));
        nodes[0].cnt = nodes[0].exist = 0;
    }

    int new_node(){
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].cnt = nodes[cur].exist = 0;
        return cur;
    }

    void add_string(string s){
        int pos = 0;
        for(int i = 0; i < s.length(); i++){
            int k = s[i] - 'a';
            if(nodes[pos].child[k] == -1) nodes[pos].child[k] = new_node();
            pos = nodes[pos].child[k];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }

    bool find_string(string s){
        int pos = 0;
        for(int i = 0; i < s.length(); i++){
            int k = s[i] - 'a';
            if(nodes[pos].child[k] == -1) return false;
            pos = nodes[pos].child[k];
        }
        return nodes[pos].exist > 0;
    }

    bool can_i_find(int pos, string& s, int i){
        if(i != s.length()){
            int k = s[i] - 'a';
            bool can_i = can_i_find(nodes[pos].child[k], s, i+1);
            if(can_i) nodes[pos].child[k] = -1;
        }
        else{
            nodes[pos].exist--;
        }

        if(pos != 0){
            nodes[pos].cnt--;
            if(nodes[pos].cnt == 0) return true;
        }
        return false;
    }

    void delete_string(string s){
        if(find_string(s) == false) return;
        else can_i_find(0, s, 0);
    }
};

int main() {
    // Trie trie;

    // trie.add_string("apple");
    // trie.add_string("banana");
    // trie.add_string("orange");

    // std::cout << "Search 'apple': " << (trie.find_string("apple") ? "Found" : "Not found") << std::endl;
    // std::cout << "Search 'banana': " << (trie.find_string("banana") ? "Found" : "Not found") << std::endl;
    // std::cout << "Search 'cherry': " << (trie.find_string("cherry") ? "Found" : "Not found") << std::endl;
    

    // trie.delete_string("banana");

    // std::cout << "Search 'banana': " << (trie.find_string("banana") ? "Found" : "Not found") << std::endl;

    // return 0;
}