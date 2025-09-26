#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    ofstream File1("1.txt"); //ofstream 创建一个输出文件流对象 File1
    // 打开名为 "1.txt" 的文件用于写入
    // 如果文件不存在，会自动创建；如果存在，会清空原内容
    File1 << "Hello World" << endl;

    ifstream File2("2.txt"); // ifstream
    string str1, str2, str3;
    // 创建一个输入文件流对象 File2
    // 打开文件 "2.txt" 用于读取
    File2 >> str1 >> str2 >> str3; // Reading words from the file

    return 0;
}
