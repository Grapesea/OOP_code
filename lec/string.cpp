#include<iostream>
#include<string>
using namespace std;
int main() {
    cout << "Hello, World!" << endl;

    string str1 = "Hello";
    string str2 = "World";
    string str3 = str1 + str2;
    printf("%s\n", str3.c_str()); 


    class A {
        int i;
        virtual void f() {}
    };

    printf("%d\n",sizeof(int *)); //8
    printf("%d\n",sizeof(int));   //4
    printf("Size of class A: %zu\n", sizeof(A));  //16
    //vptr: 8字节
    //int i: 4字节
    //padding: 4字节(用于对齐)


    string init_str1("hello");
    string init_str2(init_str1);
    string init_str3 = "Hello,World!";
    string init_str4(init_str3, 7, 5); // 从第7个位置开始截取，取5个字符

    cout << "init_str1:" << init_str1 << endl;
    cout << "init_str2:" << init_str2 << endl;
    cout << "init_str3:" << init_str3 << endl;
    cout << "init_str4:" << init_str4 << endl;

    //其余初始化方法
    
    char charArray[] = "C++ str example";
    string str2_ = charArray;    // 可以用字符数组来赋值
    cout << "str2:" << str2_ << endl;

    string str3_(10,'A');        // 可以直接写(10,char)来初始一个长度为10全为char的字符数组
    cout << "str3:" << str3_ << "\n" << endl;

    // 一些其他的内容

    // substr 获取子串
    string sub = init_str3.substr(7,5);
    cout << "Substring:" << sub << "\n" << endl;

    // assign 可以对字符串重新赋值
    cout << "Before assign: " << init_str3 << endl;
    init_str3.assign("New String");
    cout << "After assign: " << init_str3 << endl;

    // insert 可以在指定位置插入字符串
    cout << "Before insert: " << init_str1 << endl;
    init_str1.insert(5, ", C++");
    cout << "After insert: " << init_str1 << endl;

    // erase 可以删除指定位置的字符
    cout << "Before erase: " << init_str1 << endl;
    init_str1.erase(5, 5); // 从位置5开始删除5个字符
    cout << "After erase: " << init_str1 << endl;

    // append 可以追加
    cout << "Before append: " << init_str1 << endl;
    init_str1.append(" C++");
    cout << "After append: " << init_str1 << endl;

    // replace 可以替换

    cout << "Before replace: " << init_str1 << endl;
    init_str1.replace(6, 3, "World"); // 从位置6开始替换3个字符为"World"
    cout << "After replace: " << init_str1 << endl;

    // find 查找子串
    size_t pos = init_str1.find("World");
    if (pos != string::npos) {
        cout << "'World' found at position: " << pos << endl;
    } else {
        cout << "'World' not found" << endl;
    }
}