#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> wordmap;
    for (const auto &w : {"we", "are", "the", "world", "we", "love", "the", "world"})
    {
        ++wordmap[w];
    }

    for (const auto &[word, count] : wordmap)
    {
        cout << word << " occurs " << count << ((count > 1) ? " times" : " time") << endl;
    }

    return 0;
}