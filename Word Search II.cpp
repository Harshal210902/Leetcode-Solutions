class Solution {
public:
    vector<string> result;
    int m,n;
    struct trienode{
        bool wordend;
        string word;
        trienode* children[26];
    };

    trienode* getnode()
    {
        trienode* newnode = new trienode();
        newnode->wordend = false;
        newnode->word="";
        for(int i =0;i<26;i++)
        {
            newnode->children[i] =NULL;
        }
        return newnode;
    }

    void insert(trienode* root, string &word)
    {
        trienode* crawler = root;
        for(int i =0;i<word.length();i++)
        {
            char ch = word[i];
            if(crawler->children[ch-'a']==NULL)
            {
                crawler->children[ch-'a'] = getnode();
            }
            crawler = crawler->children[ch-'a'];
        }
        crawler->wordend = true;
        crawler->word = word;
    }
    vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
    void findwords(vector<vector<char>> &board, int i, int j, trienode* root)
    {
        if(i<0|| i>=n||j<0||j>=m)return;

        if(board[i][j]=='.' || root->children[board[i][j]-'a']==NULL) return;

        root = root->children[board[i][j]-'a'];
        if(root->wordend==true)
        {
            result.push_back(root->word);
            root->wordend=false;
        }
        char temp = board[i][j];
        board[i][j] = '.';
        for(auto &it: directions)
        {
            int newi = i+it[0];
            int newj = j+it[1];
            findwords(board,newi,newj,root);
        }
        board[i][j] = temp;
         


    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        trienode* root = getnode();
        for(auto &it: words)
        {
            insert(root,it);
        }
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                char ch = board[i][j];
                if(root->children[ch-'a']!=NULL)
                {
                    findwords(board,i,j,root);
                }
            }
        }
        return result;
    }
};
