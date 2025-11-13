# 文档说明

## 编译方法

```bash
~\assignment3>g++ main.cpp -o 1
~\assignment3> ./1 map1.txt
# 结束之后，按Ctrl+C退出
~\assignment3> ./1 map2.txt
# 结束之后，按Ctrl+C退出
~\assignment3> ./1 map3.txt
```

## 随机位置的生成以及调试

采用随机时间种子进行位置生成.

调试时请解除第127-128行的DEBUG信号注释，这会输出当前princess和monster的位置：

```cpp
cout << "DEBUG: Monster is in " << monsterRoom << endl;
cout << "DEBUG: Princess is in " << princessRoom << endl;
```

终端中运行两次可以看出monster和princess的位置区别（DEBUG部分显示了位置）：

```bash
~\assignment3> ./1 map1.txt
[Random locations set: Monster and Princess are hiding...]
DEBUG: Monster is in throne_room
DEBUG: Princess is in west_corridor
=== CASTLE ADVENTURE ===
Find the princess and bring her back to escape!
Beware of the monster!
Welcome to the dungeon. There is 1 exit: up.
Enter your command: U
~\assignment3> ./1 map1.txt
[Random locations set: Monster and Princess are hiding...]
DEBUG: Monster is in west_corridor
DEBUG: Princess is in east_corridor
=== CASTLE ADVENTURE ===
Find the princess and bring her back to escape!
Beware of the monster!
Welcome to the dungeon. There is 1 exit: up.
Enter your command: 
```
