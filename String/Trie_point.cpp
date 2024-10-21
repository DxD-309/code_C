#include <bits/stdc++.h>
using namespace std;

struct Trie{
    struct node{
        node* child[26];
        int cnt, exist;

        node(){
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
                cnt = exist = 0;
            }
        }
    };

    int cur;
    node* root;
    Trie(): cur(0){
        root = new node();
    }

    void add_string(string s){
        node* p = root;
        for(int i = 0; i < s.length(); i++){
            int k = s[i] - 'a';
            if(p->child[k] == NULL) p->child[k] = new node();
            p = p->child[k];
            p->cnt++;
        }
        p->exist++;
    }

    bool find_string(string s){
        node* p = root;
        for(int i = 0; i < s.length(); i++){
            int k = s[i] - 'a';
            if(p->child[k] == NULL) return false;
            p = p->child[k];
        }
        return p->exist > 0;
    }

    bool can_i_find(node* p, string& s, int i){
        if(i != s.length()){
            int k = s[i] - 'a';
            bool can_i = can_i_find(p->child[k], s, i+1);
            if(can_i) p->child[k] = NULL;
        }
        else{
            p->exist--;
        }

        if(p != root){
            p->cnt--;
            if(p->cnt == 0){
                delete(p);
                return true;
            }
        }
        return false;
    }
    void delete_string(string s){
        if(find_string(s) == false) return;
        else can_i_find(root, s, 0);
    }

};

int main() {
    // Trie trie;

    // trie.add_string("apple");
    // trie.add_string("banana");
    // trie.add_string("orange");

    // cout << "Search 'apple': " << (trie.find_string("apple") ? "Found" : "Not found") << endl;
    // cout << "Search 'banana': " << (trie.find_string("banana") ? "Found" : "Not found") << endl;
    // cout << "Search 'cherry': " << (trie.find_string("cherry") ? "Found" : "Not found") << endl;

    // trie.delete_string("banana");

    // cout << "Search 'banana': " << (trie.find_string("banana") ? "Found" : "Not found") << endl;

    // return 0;
}