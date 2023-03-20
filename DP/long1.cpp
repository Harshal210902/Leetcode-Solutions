#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(false);
#define print(array)      \
    for (auto it : array) \
    cout << it << " "
#define sortit(array) sort(array.begin(), array.end())
const int M = 1e9 + 7;

class Trie
{
public:
    struct trie
    {
        trie *arr[26];
        bool isend;
    };

    trie *node;

    Trie()
    {
        node = new trie();
    }

    void insert(string word)
    {
        ios_base::sync_with_stdio(false);
        trie *temp = node;

        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->arr[word[i] - 'a'])
            {
                temp->arr[word[i] - 'a'] = new trie();
            }
            temp = temp->arr[word[i] - 'a'];
        }

        temp->isend = true;
    }

    bool search(string word)
    {

        trie *temp = node;

        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->arr[word[i] - 'a'])
            {
                return 0;
            }
            temp = temp->arr[word[i] - 'a'];
        }

        if (temp->isend)
            return 1;

        return 0;
    }

    bool startsWith(string word)
    {
        trie *temp = node;

        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->arr[word[i] - 'a'])
            {
                return 0;
            }
            temp = temp->arr[word[i] - 'a'];
        }
        return 1;
    }
};