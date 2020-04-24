// github.com/DaniAngelov

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

struct Node
{
    int prefix_count;
    bool isEnd;
    Node* child[26];
}*head;

void init()
{
    head = new Node();
    head->isEnd = false;
    head->prefix_count = 0;
}

void insert(string word)
{
    Node *current = head;
    current->prefix_count++;

    for (int i = 0; i < word.length(); ++i)
    {
        int letter = (int)word[i] - (int)'a';    
        if (current->child[letter] == NULL)
            current->child[letter] = new Node();

        current->child[letter]->prefix_count++;
        current = current->child[letter];
    }
    current->isEnd = true;
}

int words_with_prefix(string prefix)
{
    Node *current = head;
    for (int i = 0; i < prefix.length(); ++i)
    {
        int letter = (int)prefix[i] - (int)'a';
        if (current->child[letter] == NULL)
            return 0;
        else
            current = current->child[letter];
    }
    return current->prefix_count;
}


int main()
{
    init();

    int N;
    cin >> N;
    int Q;
    cin >> Q;
    string s;
    string* words = new string[N];
    string* pref = new string[Q];

    for (int i = 0; i < N;i++)
    {
        cin >> words[i];
        insert(words[i]);
    }


    for (int i = 0; i < Q; i++)
    {
        cin >> pref[i];
    }

    for (int i = 0; i < Q; i++)
    {
        cout << words_with_prefix(pref[i]) << endl;
        
    }

    int _;
    cin >> _;
    return 0;
}
