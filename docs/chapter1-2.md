# 数据结构

| Data | 描述客观事物 |
| ------- | ------- |
| Data Item | 独立Data最小单位 |
| Data Object | 相同性质数据元素组合 |
| Data Structure | 数据元素之间的关系 |

## 逻辑结构
### 表示
1. 图表
2. 二元组

> 前驱元素，后继元素，开始元素，终端元素

### 类型
1. 集合
2. 线性结构
3. 树形结构

## 存储结构
### 1. 顺序存储结构
```C
struct {
    int no;
    char name[8];
    char sex[2];
    char class[4];
} Stud[1] = {{1,"Zhang", "m", "9901"}}
```

### 2. 链状存储结构
```C
typedef struct Stunode
{
    int no;
    char name[7];
    char sex[2];
    char class[4];
    struct Studnode* next; //next node
} StudType; //节点类型
```

### 3. 索引存储

### 4. 哈希存储

> 逻辑结构映射存储结构

## 数据类型，

| Data Type | 一组性质相同的值的集合&此集合上的一组操作 |
| ----- | ----- |

### C++语言常用
1. 数据类型
> int (short long unsigned), bool, float, double, char
```C++
int n = 10; //超过作用范围，系统自动释放 -> 自动变量
```

2. 指针类型

```C++
int i, *p;
i = 2;

*p = &i //i's address to pointer, 是一个地址
printf("%d\n", *p);
```

3. 数组类型

需要规定数组大小

4. 结构体类型

```C++
struct Teacher{
    int no;
    char name[8];
    int age;
}

struct Teacher t;
t.no=85;
strcpy(t.name, "zhang");
t.age=42;
```

5. 共用体类型
```C++
union Tag{
    short int n;
    char ch[2];
}

union Tag n;
u.n = 0x4142; //不能被解释
```

6. 自定义类型
```C++
//TYPEDEF 制定新类型
typedef struct Student{
    int no;
    char name[7];
    char sex[2];
    char class[4];
    struct Studnode* next; //next node
} NewType;

NewType s1,s2;
```

### 存储空间分配

1. 静态
```C++
int a[10];
```

2. 动态
```C++
char *p;
p = (char *)malloc(10*sizeof(char)); //dyna allocate 10
strcpy(p, "china");
printf("%c\n",*p); //第一个字符
printf("%s\n",p);//全部字符
free(p);
```

## 抽象数据类型

Abstract Data Type
: 用户进行软件系统设计时从问题的数学模型中抽象出来的逻辑数据结构和其运算，而不考虑计算机本身的存储结构和算法

```C++
ADT Complex{
    //数据对象
    //数据关系
    //基本运算
}
```

# 算法

| 算法 | 对特定问题求解步骤的描述（指令的有限序列）|
| --- | --- |

### 算法的特性
- [x] 有穷性
- [x] 确定性
- [x] 可行性
- [x] 有输入
- [x] 有输出

## 算法设计的目标
- [x] 正确性
- [x] 可使用性
- [x] 可读性
- [x] 健壮性
- [x] 高效率和低存储量

## 算法描述
#### 设计步骤
1. 分析算法功能
2. 确定算法属性（I/O）
3. 设计函数体

#### 输出型参数的设计
> 指针&引用


# 算法分析

1. 事后统计
2. 事前估计

## 时间复杂度分析
### T(n)
T(n) = n+1+n(n+1) = 2n^2 + 2n + 1
### O(n)
| O(1) | 没有循环或与n无关 |
| --- | --- |

> O(1) < O(log2n) < O(n) < O(nlog2n) < O(n^2) < O(n^3) < O(2^n) < O(n!)

### 简化的时间复杂度分析
```C++
int i=0, s=0;
while (s<n){
    i++;
    s=s + i;
}
```

### 时间复杂度求和
