# PAT-Advanced-Level-Practice
PAT(Advancedc Level)Practice(英文)代码，
开发环境vscode，
为了方便所有源文件名取为main.cpp。:
## 编译方式
linux和windows在命令行模式下输入命令: 
- 编译 ： 
```
* g++ main.cpp -o main
* 或
* cmake .
* make
```
- 执行：
```
* ./main
```
# PAT-Advanced-Level-Practice-
## 学习总结：
1002. 多项式相加可以直接使用散列，定义结构体使用二路归并相加过于复杂。
1003. Dijkstra算法求最短路径。
1004. DFS或BFS遍历树。
1013. DFS遍历每一个顶点(邻接表和邻接矩阵两种形式)。
1016. 求时间差值可以求出两个时间相对同一时间的差值后在求差值。
1030. Dijkstra 或 Dijkstra + DFS。
1038. 比较拼接字符串大小，cmp(string a, string b){ return a + b >(<) b + a}; erase()函数，删除迭代器指定位置元素。
1070. 贪心求最优解。
1071. char字母大小写转换：tolower()，toupper()，判断字符是否为字母或数字：isalnum()
1074. 静态链表反转。
1081. 多个有理分数每次相加的过程中要进行约分，否则long long类型可能溢出导致浮点错误。
1085. 滑动窗口。
1088. 两个long long整型判断符号不同不能使用if(a * b < 0)，会溢出，使用if((a < 0 && b > 0) || (a > 0 && b < 0))
1094. dfs遍历找树每一层节点数。
1101. 快速排序，乱序数组内和排序数组内相同位置值相等，遍历时保存左边最大值和当前位置值比较，当前值大这位主元，不需要和右边比较。
1140. 计算字符串内连续相同字符个数可以直接使用while循环比较相邻字符:while(s[i] == s[i + 1]){ count++; }