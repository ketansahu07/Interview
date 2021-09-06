/*

Time Complexity: O(nk^2)

*/

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
 
// Trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    vector<int> pos; // To store palindromic
                     // positions in str
    int id;
 
    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
 
// Returns new Trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;
    pNode->isLeaf = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
 
    return pNode;
}

bool isPalindrome(string str, int i, int len)
{
    // compare each character from starting
    // with its corresponding character from last
    while (i < len)
    {
        if (str[i] != str[len])
            return false;
        i++, len--;
    }
 
    return true;
}

void insert(struct TrieNode* root, string key, int id)
{
    struct TrieNode *pCrawl = root;
 
    // Start traversing word from the last
    for (int level = key.length()-1; level >=0; level--)
    {
        // If it is not available in Trie, then
        // store it
        int index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        // If current word is palindrome till this
        // level, store index of current word.
        if (isPalindrome(key, 0, level))
            (pCrawl->pos).push_back(id);
 
        pCrawl = pCrawl->children[index];
    }
    pCrawl->id = id;
    pCrawl->pos.push_back(id);
 
    // mark last node as leaf
    pCrawl->isLeaf = true;
}

void search(struct TrieNode *root, string key, int id, vector<vector<int> > &result)
{
    struct TrieNode *pCrawl = root;
    for (int level = 0; level < key.length(); level++)
    {
        int index = CHAR_TO_INDEX(key[level]);
 
        // If it is present also check upto which index
        // it is palindrome. (condition when word in trie is smaller
        // than word being searched with)
        if (pCrawl->id >= 0 && pCrawl->id != id &&
            isPalindrome(key, level, key.size()-1))
            result.push_back({id, pCrawl->id});
 
        // If not present then return
        if (!pCrawl->children[index])
            return;
 
        pCrawl = pCrawl->children[index];
    }
 
    // condition when word in the trie is larger than word
    // being searched with
    for (int i: pCrawl->pos)
    {
        if (i == id)
            continue;
        result.push_back({id, i});
    }
}

bool checkPalindromePair(vector <string> vect)
{
    // Construct trie
    struct TrieNode *root = getNode();
    for (int i = 0; i < vect.size(); i++)
        insert(root, vect[i], i);
 
    // Search for different keys
    vector<vector<int> > result;
    for (int i=0; i<vect.size(); i++)
    {
        search(root, vect[i], i, result);
        if (result.size() > 0)
           return true;
    }
 
    return false;
}