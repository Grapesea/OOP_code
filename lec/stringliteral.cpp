#include <iostream>
using namespace std;

struct Student
{
    int id;
};

void foo(const Student *ps)
{
    cout << ps->id << endl;
    cout << (*ps).id << endl;
}

void bar(const Student &s) // 传引用避免拷贝
{
    cout << s.id << endl;
}

int main()
{
    const Student s = {1001};
    foo(&s);
    bar(s);
}
