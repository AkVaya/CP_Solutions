struct TrieNode{
    struct TrieNode * children[26];
    bool isEnd;
    
};
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for(auto i : word){
            if(curr->children[i-'a']==NULL)
                curr->children[i-'a'] =  new TrieNode(); 
            curr = curr->children[i-'a'];
        }
        curr->isEnd = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        for(auto i : word){
            if(curr->children[i-'a']==NULL)
                return false;
            curr = curr->children[i-'a'];
        }
        return curr->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        TrieNode *curr = root;
        for(auto i : word){
            if(curr->children[i-'a']==NULL)
                return false;
            curr = curr->children[i-'a'];
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