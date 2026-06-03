#include <iostream>
#include <vector>
#include <string>

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

    void findWords(TrieNode* node, std::string prefix, std::vector<std::string>& results) {
        if (node->isEndOfWord) {
            results.push_back(prefix);
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                findWords(node->children[i], prefix + char('a' + i), results);
            }
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    std::vector<std::string> search(const std::string& prefix) {
        TrieNode* node = root;
        std::vector<std::string> results;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) {
                return results;
            }
            node = node->children[index];
        }
        findWords(node, prefix, results);
        return results;
    }
};

int main() {
    Trie trie;
    trie.insert("alice");
    trie.insert("alicia");
    trie.insert("bob");
    trie.insert("albert");

    std::vector<std::string> results = trie.search("ali");
    for (const std::string& word : results) {
        std::cout << word << std::endl;
    }

    return 0;
}
