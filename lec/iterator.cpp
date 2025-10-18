#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    reverse(v.begin(), v.end());

    vector<int> u(10, 8);
    copy(v.begin(), v.end(), u.begin());
    copy(u.begin(), u.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
