# 编译说明

## 如何在命令行内使用g++对cpp代码进行编译

使用g++编译C++代码的基本指令格式如下：

```bash
g++ 源文件名.cpp -o 可执行文件名
```

### 具体示例

假设你有一个名为 `hello.cpp` 的源文件：

```bash
# 编译生成可执行文件
g++ hello.cpp -o hello

# 运行可执行文件
./hello
```

### 常用编译选项

```bash
# 基本编译
g++ main.cpp -o main

# 指定C++标准版本
g++ -std=c++11 main.cpp -o main
g++ -std=c++17 main.cpp -o main

# 开启调试信息
g++ -g main.cpp -o main

# 开启编译优化
g++ -O2 main.cpp -o main

# 显示所有警告
g++ -Wall main.cpp -o main

# 组合多个选项
g++ -std=c++17 -Wall -g -O2 main.cpp -o main
```

### 编译多个文件

```bash
# 编译多个源文件
g++ main.cpp utils.cpp helper.cpp -o program

# 分别编译再链接
g++ -c main.cpp        # 生成main.o
g++ -c utils.cpp       # 生成utils.o
g++ main.o utils.o -o program  # 链接生成可执行文件
```

* 常见编译流程

    1. **编写代码**：创建 `.cpp` 文件
    2. **编译**：`g++ 源文件.cpp -o 程序名`
    3. **运行**：`./程序名`（Linux/Mac）或直接输入程序名（Windows）

## CMakeLists相关

添加完 CMakeLists.txt 文件后，编译 C++ 项目的标准流程如下：

1. **创建构建目录**（推荐做法）

```bash
mkdir build
cd build
```

2. **生成构建文件**

```bash
cmake ..
```

或者指定构建类型：

```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
```

3. **编译项目**

```bash
make
```

或者使用多线程编译加速：

```bash
make -j4  # 使用4个线程
```

### 完整示例

假设你的项目结构如下：

```
my_project/
├── CMakeLists.txt
├── main.cpp
└── src/
    ├── file1.cpp
    └── file1.h
```

编译命令：

```bash
cd my_project
mkdir build
cd build
cmake ..
make
```

### 其他编译选项

**指定编译器：**

```bash
cmake -DCMAKE_CXX_COMPILER=g++ ..
cmake -DCMAKE_CXX_COMPILER=clang++ ..
```

**Debug 模式编译：**

```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```

**清理重新编译：**

```bash
make clean
make
```

**使用 cmake 直接编译：**

```bash
cmake --build . --config Release
```

编译完成后，可执行文件通常会在 `build` 目录中生成。运行程序：

```bash
./your_program_name
```

这样就完成了从 CMakeLists.txt 到可执行程序的整个编译过程。

!!! tips

    在本项目中，我采用的编译流程是：
    
    ```bash
    PS E:..\> cd assignment1
    PS E:..\assignment1> mkdir build
    PS E:..\assignment1> cd build
    PS E:..\assignment1\build> cmake -G "MinGW Makefiles" ..
    PS E:..\assignment1\build> cmake --build .
    PS E:..\assignment1\build> ./student_scores
    K.Weng  5       5       5       
    T.Dixon 4       3       2       
    V.Chu   3       4       5
    L.Tson  4       3       4
    L.Lee   3       4       3
    I.Young 4       2       5
    K.Hiro  4       2       1
    G.Ping  4       4       4
    H.Gu    2       3       4
    J.Jon   5       4       3
    ```
    
    输入完之后等待输出就好了

## 通过命令行下载和安装 CMake

## Linux 系统

**Ubuntu/Debian：**

```bash
sudo apt update
sudo apt install cmake
```

**CentOS/RHEL/Fedora：**

```bash
# CentOS/RHEL
sudo yum install cmake
# 或者新版本使用
sudo dnf install cmake

# Fedora
sudo dnf install cmake
```

**Arch Linux：**

```bash
sudo pacman -S cmake
```

## macOS 系统

**使用 Homebrew：**

```bash
brew install cmake
```

**使用 MacPorts：**

```bash
sudo port install cmake
```

## Windows 系统

**使用 Chocolatey：**

```bash
choco install cmake
```

**使用 Scoop：**

```bash
scoop install cmake
```

**使用 winget：**

```bash
winget install Kitware.CMake
```

## 通用方法 - 官方二进制包

**Linux/macOS 下载最新版本：**

```bash
# 下载最新版本（以 3.27.0 为例）
wget https://github.com/Kitware/CMake/releases/download/v3.27.0/cmake-3.27.0-linux-x86_64.tar.gz

# 解压
tar -xzf cmake-3.27.0-linux-x86_64.tar.gz

# 移动到系统目录
sudo mv cmake-3.27.0-linux-x86_64 /opt/cmake

# 添加到 PATH
echo 'export PATH="/opt/cmake/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
```

## 从源码编译（适用于所有系统）

```bash
# 下载源码
wget https://github.com/Kitware/CMake/releases/download/v3.27.0/cmake-3.27.0.tar.gz
tar -xzf cmake-3.27.0.tar.gz
cd cmake-3.27.0

# 编译安装
./bootstrap
make
sudo make install
```

## 验证安装

安装完成后，验证 CMake 是否正确安装：

```bash
cmake --version
```

## 常用 CMake 组件

如果需要特定的 CMake 模块或工具，可以额外安装：

**Ubuntu/Debian 额外工具：**

```bash
sudo apt install cmake-curses-gui  # ccmake 图形界面
sudo apt install cmake-qt-gui      # cmake-gui 图形界面
```

选择适合你操作系统的方法即可快速安装 CMake。
