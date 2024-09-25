#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int count = 0;
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            node->count++;
        }
    }

    int calculateScore(const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char ch : word) {
            node = node->children[ch];
            score += node->count;
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        
        // Step 1: Insert all words into the Trie
        for (const string& word : words) {
            trie.insert(word);
        }
        
        // Step 2: Calculate the score for each word
        vector<int> result;
        for (const string& word : words) {
            result.push_back(trie.calculateScore(word));
        }
        
        return result;
    }
};
