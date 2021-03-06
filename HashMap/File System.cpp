// github.com/DaniAngelov

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Directory
{
    Directory* previous;
    map<string, Directory*> dirs;
    string directory;

    Directory()
    {
        this->directory = "";
        this->previous = NULL;
    }
    Directory(string directory)
    {
        this->directory = directory;
        this->previous = NULL;
    }
    Directory(string directory,Directory* prev)
    {
        this->directory = directory;
        this->previous = prev;
    }
};

class Tree
{
    vector<string> subDirectories;
    Directory* root = new Directory();
    Directory* curr = root;

public:

    void mkdir(string dir)
    {
        auto it = curr->dirs.find(dir);
        if (it == curr->dirs.end())
        {
            Directory* temp = new Directory(dir, curr);
            curr->dirs.insert(pair<string, Directory*>(dir, temp));
        }
        else
        {
            
            cout << "Directory already exists" << endl;
        }
    }
    void cd(string dir)
    {
        if (dir == "..")
        {
            if (curr != root)
            {
                curr = curr->previous;
                subDirectories.pop_back();
            }
            else
            {
                cout << "No such directory" << endl;
            }
            return;
        }

        auto it = curr->dirs.find(dir);

        if (it == curr->dirs.end())
        {
            cout << "No such directory" << endl;
        }
        else
        {
            curr = it->second;
            subDirectories.push_back(dir);
        }
    }
    void ls()
    {
        for (auto it = curr->dirs.begin(); it != curr->dirs.end(); it++)
        {
            cout << it->first << " ";
        }
        cout << endl;

    }
    void pwd()
    {
        if (curr == root)
        {
            cout << "/" << endl;
            return;
        }

        cout << "/";

        
        
            for (int i = 0; i < subDirectories.size(); i++)
            {
                cout << subDirectories[i] << "/";
            }
            cout << endl;
        
    }


};

int main()
{
    int N;
    cin >> N;

    string directory;
    string command;

    Tree directories;

    for (int i = 0; i < N; i++)
    {
        cin >> command;

        if (command == "ls")
        {
            directories.ls();
        }
        if (command == "pwd")
        {
            directories.pwd();
        }
        if (command == "mkdir")
        {
            cin >> directory;
            directories.mkdir(directory);
        }
        if (command == "cd")
        {
            cin >> directory;
            directories.cd(directory);
        }
    }


    

    /*
    7
    mkdir a
    mkdir b
    cd b
    mkdir c
    cd c
    cd ..
    ls
    */


    int _;
    cin >> _;
    return 0;
}
