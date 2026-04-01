#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    char val;
    bool isWord;
    unordered_map<char, TrieNode*> children;

    TrieNode(char c) {
        val = c;
        isWord = false;
    }
};


class Trie {
private:
    TrieNode* root;

    // Helper method to find a node based on a string
    TrieNode* getNode(string s) {
        TrieNode* curr = root;
        for (char c : s) {
            if (curr->children.find(c) == curr->children.end()) {
                return nullptr; // Character not found
            }
            curr = curr->children[c];
        }
        return curr;
    }

public:
    Trie() {
        root = new TrieNode(' '); // Dummy root node
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            // If the character doesn't exist, create a new node
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode(c);
            }
            curr = curr->children[c];
        }
        curr->isWord = true; // Mark the end of the word
    }

    bool search(string word) {
        TrieNode* node = getNode(word);
        return node != nullptr && node->isWord;
    }

    bool startsWith(string prefix) {
        return getNode(prefix) != nullptr;
    }
};


int main() {
    Trie* obj = new Trie();
    
    obj->insert("apple");
    cout << "Search 'apple': " << (obj->search("apple") ? "True" : "False") << endl;   
    cout << "Search 'app': " << (obj->search("app") ? "True" : "False") << endl;       
    cout << "StartsWith 'app': " << (obj->startsWith("app") ? "True" : "False") << endl; 

    obj->insert("app");
    cout << "Search 'app' after inserting: " << (obj->search("app") ? "True" : "False") << endl;
    delete obj;
    return 0;
}