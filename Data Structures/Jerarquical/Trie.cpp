#include <iostream>
#include <vector>

using namespace std;

class TrieNode{
    
    public:
        // pointer array for child nodes of each node
        TrieNode* child[26];

        // Used for indicating ending of string
        bool wordEnd;

        TrieNode(){
            // Constructor
            // Initialize the wordEnd variable with false
            // Initialize every index of childNode array with
            // NULL
            wordEnd = false;
            for( int i = 0; i < 26; i++ ){
                child[i] = NULL;
            }
        }
};

void insertKey(TrieNode* root, string& key ){
    // Initialize the curr pointer with the root node
    TrieNode* curr = root;

    // Iterate across the length of the string
    for( char c : key ){

        // Check if the node exists for the current character in the Trie
        if( curr->child[c - 'a'] == nullptr ){
            // If node for current character does
            // not exist then make a new node
            TrieNode* newNode = new TrieNode();
            curr->child[c - 'a'] = newNode;
        }

        curr = curr->child[c-'a'];
    }

    curr->wordEnd = true;
}

bool searchKey(TrieNode* root, string& key ){
    TrieNode* curr = root;

    for( char c : key ){
        if( curr->child[c - 'a'] == nullptr ) 
            return false;

        curr = curr->child[c - 'a'];
    }
    
    return curr->wordEnd;

}

int main() {
  
    // Create am example Trie
    TrieNode* root = new TrieNode();
    vector<string> arr = 
      {"and", "ant", "do", "geek", "dad", "ball"};
    for (string& s : arr) {
        insertKey(root, s);
    }

    // One by one search strings
    vector<string> searchKeys = {"do", "gee", "bat"};
    for (string& s : searchKeys) {
        cout << "Key : " << s << "\n";
        if (searchKey(root, s)) 
            cout << "Present\n";
        else 
            cout << "Not Present\n";        
    }
  
    return 0;
}