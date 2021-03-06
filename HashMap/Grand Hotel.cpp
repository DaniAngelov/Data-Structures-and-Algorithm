// github.com/DaniAngelov

#include <iostream>
#include <map>
#include <algorithm>

#define MAX 1000000000
using namespace std;

int main()
{
    int N;
    cin >> N;

    long long* bi = new long long[N - 1];
    long long* ai = new long long[N - 1];


    multimap<long long, long long> m_ai;
    multimap<long long, long long> m_bi;

    long long counter = 0;


    for (int i = 0; i < N - 1; i++)
    {
        cin >> bi[i];

    }

    for (int i = 0; i < N - 1; i++)
    {

        cin >> ai[i];


    }


    for (int i = 0; i < N - 1; i++)
    {
        m_ai.insert(pair<int, int>(ai[i], i));
        m_bi.insert(pair<int, int>(bi[i], i));

        //cout << "count:" << m_bi.count(ai[i]) << endl;

        if (m_bi.count(ai[i]))
        {
            m_ai.erase(m_ai.lower_bound(ai[i]));
            m_bi.erase(m_bi.lower_bound(ai[i]));
        }
        else
        {
            counter++;
            m_ai.erase(m_ai.lower_bound(ai[i]));
        }

    }









    /*
    
    multimap<long long, long long>::iterator it;


    cout << "AI: " << endl;

    for (it = m_ai.begin(); it != m_ai.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    cout << "BI: " << endl;

    for (it = m_bi.begin(); it != m_bi.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    
    */
    cout << counter << endl;



    int _;
    cin >> _;
    return 0;
}
