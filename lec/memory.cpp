#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int globalx = 100;

int main()
{
    static int staticx = 30;
    int localx = 3;
    int *px = (int *)malloc(sizeof(int));

    cout << "&globalx = " << &globalx << endl;
    cout << "&staticx = " << &staticx << endl;
    cout << "&localx = " << &localx << endl;
    cout << "&px = " << &px << endl;
    cout << "px = " << px << endl;
}

/*
跑出来这些结果：
&globalx = 0x403010
&staticx = 0x403014
&localx = 0x61fe4c
&px = 0x61fe40  指针变量的地址
px = 0x10a6ce0  指针变量的值
*/