//208. Implement Trie (Prefix Tree)
class Trie {
public:
    class Node {
    public:
        bool flag = false;
        Node* children[26];
        Node() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    Node* root = new Node();

    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                curr->children[word[i] - 'a'] = new Node();
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->flag = true;
    }

    bool search(string word) {
        Node* curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[word[i] - 'a'];
        }
        return curr->flag;
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (curr->children[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */