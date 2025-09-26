#include<iostream>

using namespace std;

int main(){
    string s;
    string *ps = &s; // ps is a pointer to a string
    s = "Hello, World!";
    cout << s << endl;
    cout << *ps << endl; // dereference the pointer to get the string value
    
    int *p = new int; //new 分配内存
    int *a = new int[10]; //new 分配数组内存
    delete p; //释放内存
    delete[] a; //释放数组内存
    
    
    
    return 0;
}