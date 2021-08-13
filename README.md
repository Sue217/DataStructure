# 数据结构

## 1.单链表

```cpp
struct Node{
    int val;
    Node *next;
};
```

**效率低，new慢，一般超时不用，使用数组模拟链表**

### 用数组模拟单链表

* **邻接表 --- 存储图和树**

`e[N]` , `ne[N]` **INT型 用数组下标联系**. *(e[] 表示 val[])*

**eg.**

`head -> 3[0] -> 5[1] -> 7[2] -> 9[3] -> nullptr`

`e[0] = 3,e[1] = 5,e[2] = 7,e[3] = 9`

`ne[0] = 1,ne[1] = 2,ne[2] = 3,ne[3] = -1`

##### 例题 --- 单链表

实现一个单链表，链表初始为空，支持三种操作：

1. 向链表头插入一个数；
2. 删除第 `k` 个插入的数后面的数；
3. 在第 `k` 个插入的数后插入一个数。

现在要对该链表进行 `M` 次操作，进行完所有操作后，从头到尾输出整个链表。

**注意**:题目中第 `k` 个插入的数并不是指当前链表的第 kk 个数。例如操作过程中一共插入了 `n` 个数，则按照插入的时间顺序，这 `n` 个数依次为：第 1 个插入的数，第 2 个插入的数，…，第 n 个插入的数。

**输入格式**

第一行包含整数 `M`，表示操作次数。

接下来 `M` 行，每行包含一个操作命令，操作命令可能为以下几种：

1. `H x`，表示向链表头插入一个数 `x`。
2. `D k`，表示删除第 `k` 个插入的数后面的数（当 k 为 0 时，表示删除头结点）。
3. `I k x`，表示在第 `k` 个插入的数后面插入一个数 `x`（此操作中 k 均大于 0）。

**输出格式**

共一行，将整个链表从头到尾输出。

**数据范围**

1≤M≤100000
所有操作保证合法。

**输入样例：**

```
10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 4 5
I 3 4
D 6
```

**输出样例：**

```
6 4 6 5
```

**Code**

```cpp
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int e[N],ne[N],idx,head;
/*head:表示头结点下标
* e[i]:表示结点i的值
* ne[i]:表示结点i的next指针值
* idx:存储当前用到了哪个点*/

void init(){
    head = -1;
    idx = 0;
}
void add_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx ++;
}
void add(int k,int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx ++;
}
void remove(int k){
    ne[k] = ne[ne[k]];    
}

int main(){
    init();
    int M;
    cin >> M;
    while (M --){
        char op;
        int x,k;
        cin >> op;
        /*switch (op){
        *   case 'H': cin >> x;add_head(x);break;
        *   case 'I': cin >> k >> x;add(k - 1,x);break;
        *   case 'D': cin >> k;if(!k)head = ne[head];else remove(k - 1);break;
        *   default : ;
        }*/
        if (op == 'H') {
            cin >> x;
            add_head(x);
        }
        else if (op == 'I') {
            cin >> k >> x;
            add(k - 1,x);//注意位置k - 1
        }
        else if (op == 'D') {
            cin >> k;
            if(!k) head = ne[head];//注意特判
            else remove(k - 1);//注意位置k - 1
        }
    }
    for(int i = head; i != -1;i = ne[i]) cout << e[i] << ' ';
    cout << '\n';
    return 0;
}
```



## 2.双链表

### 用数组模拟双链表

* **优化某些问题**

##### 例题 --- 双链表

实现一个双链表，双链表初始为空，支持 5 种操作：

1. 在最左侧插入一个数；
2. 在最右侧插入一个数；
3. 将第 k 个插入的数删除；
4. 在第 k 个插入的数左侧插入一个数；
5. 在第 k 个插入的数右侧插入一个数

现在要对该链表进行 M 次操作，进行完所有操作后，从左到右输出整个链表。

**注意** : 题目中第 k 个插入的数并不是指当前链表的第 k 个数。例如操作过程中一共插入了 n 个数，则按照插入的时间顺序，这 n 个数依次为：第 1 个插入的数，第 2 个插入的数，…，第 n 个插入的数。

**输入格式**

第一行包含整数 M，表示操作次数。

接下来 M 行，每行包含一个操作命令，操作命令可能为以下几种：

1. `L x`，表示在链表的最左端插入数 x。
2. `R x`，表示在链表的最右端插入数 x。
3. `D k`，表示将第 k 个插入的数删除。
4. `IL k x`，表示在第 k 个插入的数左侧插入一个数。
5. `IR k x`，表示在第 k 个插入的数右侧插入一个数。

**输出格式**

共一行，将整个链表从左到右输出。

**数据范围**

1≤M≤100000
所有操作保证合法。

**输入样例：**

```
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2
```

**输出样例：**

```
8 7 7 3 2 9
```

**Code**

```cpp
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int e[N],l[N],r[N],idx;

void init(){
    r[0] = 1;//1表示右端点
    l[1] = 0;//0表示左端点 
    //注意顺序!!!
    idx = 2;
}
void insert(int k,int x){
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx ++;
}
void remove(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main(){
    int M,x,k;
    cin >> M;
    init();
    
    while (M --){
        string op;
        cin >> op;
        
        if(op == "L"){
            cin >> x;
            insert(0,x);
        }
        else if(op == "R"){
            cin >> x;
            insert(l[1],x);
        }
        else if(op == "D"){
            cin >> k;
            remove(k + 1);//!
        }
        else if(op == "IL"){
            cin >> k >> x;
            insert(l[k + 1],x);//!
        }
        else if(op == "IR"){
            cin >> k >> x;
            insert(k + 1,x);//!
        }
    }
    
    for(int i = r[0];i != 1;i = r[i])cout << e[i] << ' ';
    cout << '\n';
    return 0;
}
```



## 3.栈

**设 `stack[N]` 表示栈、tt表示栈顶位置**

**`stack[tt ++]`** 表示入栈 `push`

**`tt --`** 表示弹出 `pop`

**`stack[tt]`** 表示栈顶元素

**`if(tt > 0)`** 表示栈非空，否则 ***isEmpty***

##### 例题 --- 模拟栈

实现一个栈，栈初始为空，支持四种操作：

1. `push x` – 向栈顶插入一个数 x；
2. `pop` – 从栈顶弹出一个数；
3. `empty` – 判断栈是否为空；
4. `query` – 查询栈顶元素。

现在要对栈进行 M 个操作，其中的每个操作 3 和操作 4 都要输出相应的结果。

**输入格式**

第一行包含整数 M，表示操作次数。

接下来 M 行，每行包含一个操作命令，操作命令为 `push x`，`pop`，`empty`，`query` 中的一种。

**输出格式**

对于每个 `empty` 和 `query` 操作都要输出一个查询结果，每个结果占一行。

其中，`empty` 操作的查询结果为 `YES` 或 `NO`，`query` 操作的查询结果为一个整数，表示栈顶元素的值。

**数据范围**

1≤M≤100000,
1≤x≤10^9^
所有操作保证合法。

**输入样例：**

```
10
push 5
query
push 6
pop
query
pop
empty
push 4
query
empty
```

**输出样例：**

```
55YES4NO
```

**Code**

```cpp
void push(int x){    stk[tt ++] = x;}void pop(){    tt --;}void empty(){    if(tt == 0)cout << "YES";    else cout << "NO";}int query(){    return stk[tt];}
```



```cpp
#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int stk[N],tt;//设tt全局变量可自动初始化为0

int main(){
    int M,x;
    string op;
    cin >> M;
    while (M --){
        cin >> op;
        if(op == "push"){
            cin >> x;
            stk[tt ++] = x;
        }
        else if(op == "pop"){
            tt --;
        }
        else if(op == "empty"){
            if(tt == 0)cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else if(op == "query"){
            cout << stk[tt - 1] << '\n';
        }
    }
    return 0;
}
```

##### 例题 --- 表达式求值

给定一个表达式，其中运算符仅包含 `+,-,*,/`（加 减 乘 整除），可能包含括号，请你求出表达式的最终值。

**注意：**

- 数据保证给定的表达式合法。
- **题目保证符号 `-` 只作为减号出现**，不会作为负号出现，例如，`-1+2`,`(2+2)*(-(1+1)+2)` 之类表达式均不会出现。
- **题目保证表达式中所有数字均为正整数**。
- 题目保证表达式在中间计算过程以及结果中，均不超过 2^31^−1。
- 题目中的整除是指向 0 取整，也就是说对于大于 0 的结果向下取整，例如 `5/3=1`，对于小于 0 的结果向上取整，例如 `5/(1−4)=−1`。
- C++和Java中的整除默认是向零取整；Python中的整除`//`默认向下取整，因此Python的`eval()`函数中的整除也是向下取整，在本题中不能直接使用。

**输入格式**

共一行，为给定表达式。

**输出格式**

共一行，为表达式的结果。

**数据范围**

表达式的长度不超过 10^5^。

**输入样例：**

```
(2+2)*(1+1)
```

**输出样例：**

```
8
```

**Code**

```cpp
//如何判断某棵子树被遍历完：当前运算符优先级 >= 上一个运算符优先级
//左括号无影响，右括号（当前运算符 < 上一个从右往左全操作）
#include<iostream>
#include<algorithm>
#include<stack>
#include <unordered_map>
using namespace std;
stack<int> num;
stack<char> ops;
void eval() {    
    auto b = num.top();num.pop();
    auto a = num.top();num.pop();//注意顺序！ - /    
    auto c = ops.top();ops.pop();    
    int x;    
    switch(c){        
        case ('+') : x = a + b;break;        
        case ('-') : x = a - b;break;        
        case ('*') : x = a * b;break;        
        case ('/') : x = a / b;break;        
        default : ;    
    }    
    num.push(x);
}
int main() {    
    unordered_map<char,int> pr{{'+', 1},{'-', 1},{'*', 2},{'/', 2}};    
    string op;    
    cin >> op;    
    for(int i = 0;i < op.size();i ++){
        auto c = op[i];        
        if(isdigit(c)) {
            int x = 0,j = i;
            while (j < op.size() && isdigit(op[j])){
                x = x * 10 + op[j ++] - '0';            
            }
            i = j - 1;
            num.push(x);
        }
        else if(c == '(') ops.push(c);
        else if(c == ')') {
            while (!ops.empty() && ops.top() != '(') eval();//用末尾的运算符操作末位的两个数   
            ops.pop();
        }
        else {
            while (!ops.empty() && ops.top() != '(' && pr[ops.top()] >= pr[c]) eval();
            ops.push(c);
        }
    }
    while (!ops.empty()) eval();
    cout << num.top() << '\n';
    return 0;
}
```

##### 例题 --- 简单计算器

给你一个字符串表达式 `s` ，请你实现一个基本计算器来计算并返回它的值。 

* 示例 1：

```
输入：s = "1 + 1"输出：2
```

* 示例 2：

```
输入：s = " 2-1 + 2 "输出：3
```

* 示例 3：

```
输入：s = "(1+(4+5+2)-3)+(6+8)"输出：23
```

* 示例 4：

```
输入：s = "-2 +1 "输出：-1
```

* 提示：

1 <= s.length <= 3 * 10^5^
s 由 数字、'+' 、'-' 、'(' 、')' 、和 ' ' 组成
s 表示一个有效的表达式

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**Code**

```cpp
class Solution {
public:
    int calculate(string s) {
        stack<int> ops; //ops栈顶元素记录了当前位置所处的每个括号所「共同形成」的符号
        ops.push(1);	//如 1+(1-2)-(1+3-2) => 1+1-2-1-3+2
        int sign = 1; 	//表示当前符号

        int ret = 0;
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i ++;
            } else if (s[i] == '+') {
                sign = ops.top();
                i ++;
            } else if (s[i] == '-') {
                sign = -ops.top();
                i ++;
            } else if (s[i] == '(') {
                ops.push(sign);
                i ++;
            } else if (s[i] == ')') {
                ops.pop();
                i ++;
            } else {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i ++;
                }
                ret += sign * num;
            }
        }
        return ret;
    }
};
```



### 单调栈 Monotonic Stack

##### 例题 --- 单调栈 (Lv.1)

给定一个长度为 N 的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 −1。

**输入格式**

第一行包含整数 N，表示数列长度。

第二行包含 N 个整数，表示整数数列。

**输出格式**

共一行，包含 `N` 个整数，其中第 `i` 个数表示第 `i` 个数的左边第一个比它小的数，如果不存在则输出 `−1`。

**数据范围**

1≤N≤10^5^
1≤数列中元素≤10^9^

**输入样例：**

```
5
3 4 2 7 5
```

**输出样例：**

```
-1 3 -1 2 2
```

**思路**

常规暴力做法：i：1～N，j：i - 1～0 遍历

利用栈的思想：如果a[3] >= a[5]，那么对于a[5]之后的元素在满足a[i] > a[3]同时a[i] > a[5]情况下，一定会优先选择a[5]作为最近小的元素输出，所以可以在 `push` a[5]时 `pop` a[3]，进而保证了栈单调。

**Code**

```cpp
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int stk[N],tt;

int main(){
    int n;
    cin >> n;
    while (n --){
        int x;
        cin >> x;
        while (tt && stk[tt] >= x) tt --;
        if(tt) cout << stk[tt] << ' ';
        else cout << "-1" << ' ';
        
        stk[++ tt] = x;
    }
    cout << '\n';
    return 0;
}
```

##### 例题 ---  Next Greater Number (Lv.2)

给你⼀个数组，返回⼀个等⻓的数组，对应索引存储着下⼀个更⼤元素，如果没有更⼤的元素，就存 `-1`

**输入样例：**

```
5
2 1 2 4 3
```

**输出样例：**

```
4 2 4 -1 -1
```

**Code**

**模版**

```cpp
vector<int> nextGreaterNumber(vector<int> & nums){
    vector<int> ans(nums.size());//存放答案的数组
    stack<int> stk;
    for(int i = nums.size() - 1; i >= 0; i --){
        while (!stk.empty() && stk.top() <= nums[i]) s.pop();
        ans[i] = s.empty() ? -1 : stk.top();
        s.push(num[i]);
    }
    return ans;
}
```

**数组实现**

```cpp
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int stk[N],tt;
int tmp[N],ans[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> tmp[i];
    int x;
    for (int i = n - 1; i >= 0; i --) {
        while (tt && stk[tt] <= tmp[i])tt --;
        //注意此时的操作对象，不开额外ans[]存储结果会导致错误
        if(tt) ans[i] = stk[tt];
        else ans[i] = -1;
        
        stk[++ tt] = tmp[i];
    }
    for(int i = 0; i < n; i ++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
```

##### 例题 ---  Next Greater Number Distance (Lv.3)

给你⼀个数组 T = [73, 74, 75, 71, 69, 72, 76, 73]，这个数组存放的是近⼏天的天⽓⽓温，返回 [1, 1, 4, 2, 1, 1, 0, 0]。

解释：第⼀天 73 华⽒度，第⼆天 74 华⽒度，⽐ 73 ⼤，所以对于第⼀天，只要等⼀天就能等到⼀个更暖和的⽓温。

**Code**

**模版**

```cpp
vector<int> dalityTemperature(vector<int> T){
    vector<int> ans(T.size());
    stack<int> stk;
    for(int i = nums.size() - 1; i >= 0; i --){
        while (!stk.empty() && T[stk.top()] <= T[i]) stk.pop();
        ans[i] = stk.empty() ? 0 : (stk.top() - i);//得到索引间距
        stk.push(i);//push索引而非数据
    }
    return ans;
}
```

**数组实现**

```cpp
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int stk[N],tt;
int tmp[N],ans[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> tmp[i];
    int x;
    for (int i = n - 1; i >= 0; i --) {
        while (stk[tt] && tmp[stk[tt]] <= tmp[i]) tt --;//!
        ans[i] = stk[tt] ? (stk[tt] - i) : 0;
        stk[++ tt] = i;
    }
    
    for(int i = 0; i < n; i ++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
```

##### 例题 --- Next Greater Number ++ (Lv.4)

现在假设数组是环形的。给你⼀个数组 [2,1,2,4,3]，你返回数组 [4,2,4,-1,4]。

拥有了环形属性，最后⼀个元素 3 绕了⼀圈后找到了⽐⾃⼰⼤的元素 4 。

计算机的内存都是线性的，没有真正意义上的环形数组，但是我们可以模拟出环形数组的效果。

⼀般是通过 `%` 运算符求模（余数），获得环形效果。

问题的难点在于：这个 Next 的意义不仅仅是当前元素的右边了，有可能出现在当前元素的左边。

**思路：**将原始数组翻倍，即在原始数组后接上一个原始数组。

**Code**

```cpp
vector<int> nextGreaterNum(vector<int> nums){
    int n = nums.size();
    vector<int> res(n);
    stack<int> stk;
    
    for (int i = 2 * n - 1; i >= 0; i --) {
        while (!stk.empty() && stk.top() <= nums[i % n]) stk.pop();
        res[i % n] = stk.empty() ? -1 : stk.top();
        
        stk.push(nums[i % n]);
    }
    return res;
}
```

##### 例题 --- 移掉K位数字（转专业考试最后一题！）

给你一个以字符串表示的非负整数 `num` 和一个整数 `k` ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。

**示例 1 ：**

```
输入：num = "1432219", k = 3
输出："1219"
```

解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。
**示例 2 ：**

```
输入：num = "10200", k = 1
输出："200"
```

解释：移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
**示例 3 ：**

```
输入：num = "10", k = 2
输出："0"
```

解释：从原数字移除所有的数字，剩余为空就是 0 。

**提示：**

1 <= k <= num.length <= 10^5^
num 仅由若干位数字（0 - 9）组成
除了 0 本身之外，num 不含任何前导零

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-k-digits

**Code**

```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        string res;
        if (k >= num.size()) return "0";
        for (auto it : num) {
            while (!stk.empty() && stk.top() > it && k) {
                stk.pop();
                k --;
            }
            stk.push(it);
        }
        while (k --) stk.pop();
        stack<char> tmp;
        while (!stk.empty()) {
            tmp.push(stk.top());
            stk.pop();
        }
        while (tmp.top() == '0' && tmp.size() > 1) tmp.pop();
        while (!tmp.empty()) {
            res += tmp.top();
            tmp.pop();
        }

        return res;
    }
};
```



#### 单调栈问题 --- 元素 🆚 距离

**元素 --- 栈存原数组满足元素**

**距离 --- 栈存原数组满足元素数组下标，与i相减得到距离**



## 4.队列

hh 初始 = 0 表示队头

tt 初始 = -1 表示队尾

**`q[++ tt]`** 表示在队尾插入元素

**`hh ++`** 表示弹出队头元素

**`q[hh]` **取出队头元素（q[tt] 取出队尾元素）

**`if (hh <= tt)`** *not empty*

**`if (hh > tt)`** *is empty*

##### 例题 --- 模拟队列

实现一个队列，队列初始为空，支持四种操作：

1. `push x` – 向队尾插入一个数 x；
2. `pop` – 从队头弹出一个数；
3. `empty` – 判断队列是否为空；
4. `query` – 查询队头元素。

现在要对队列进行 M 个操作，其中的每个操作 3 和操作 4 都要输出相应的结果。

**输入格式**

第一行包含整数 M，表示操作次数。

接下来 M 行，每行包含一个操作命令，操作命令为 `push x`，`pop`，`empty`，`query` 中的一种。

**输出格式**

对于每个 `empty` 和 `query` 操作都要输出一个查询结果，每个结果占一行。

其中，`empty` 操作的查询结果为 `YES` 或 `NO`，`query` 操作的查询结果为一个整数，表示队头元素的值。

**数据范围**

1≤M≤100000,
1≤x≤10^9^,
所有操作保证合法。

**输入样例：**

```
10
push 6
empty
query
pop
empty
push 3
push 4
pop
query
push 6
```

**输出样例：**

```
NO
6
YES
4
```

**Code**

```cpp
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int q[N];
int hh = 0,tt = -1;//设hh全局变量可自动初始化为0

int main(){
    int M;
    cin >> M;
    while (M --){
        string op;
        cin >> op;
        if(op == "push"){
            int x;
            cin >> x;
            q[++ tt] = x;
        }
        else if(op == "pop"){
            hh ++;
        }
        else if(op == "empty"){
            if(hh > tt)cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else if(op == "query"){
            cout << q[hh] << '\n';
        }
    }
    return 0;
}
```

### 单调队列 Monotonic Queue

##### 例题 --- 滑动窗口

给定一个大小为 n≤10^6^ 的数组。

有一个大小为 k 的滑动窗口，它从数组的最左边移动到最右边。

你只能在窗口中看到 k 个数字。

每次滑动窗口向右移动一个位置。

以下是一个例子：

该数组为 `[1, 3, -1, -3, 5, 3, 6, 7]`，k 为 3。

|      窗口位置       | 最小值 | 最大值 |
| :-----------------: | :----: | :----: |
| [1 3 -1] -3 5 3 6 7 |   -1   |   3    |
| 1 [3 -1 -3] 5 3 6 7 |   -3   |   3    |
| 1 3 [-1 -3 5] 3 6 7 |   -3   |   5    |
| 1 3 -1 [-3 5 3] 6 7 |   -3   |   5    |
| 1 3 -1 -3 [5 3 6] 7 |   3    |   6    |
| 1 3 -1 -3 5 [3 6 7] |   3    |   7    |

你的任务是确定滑动窗口位于每个位置时，窗口中的最大值和最小值。

**输入格式**

输入包含两行。

第一行包含两个整数 n 和 k，分别代表数组长度和滑动窗口的长度。

第二行有 n 个整数，代表数组的具体数值。

同行数据之间用空格隔开。

**输出格式**

输出包含两个。

第一行输出，从左至右，每个位置滑动窗口中的最小值。

第二行输出，从左至右，每个位置滑动窗口中的最大值。

**输入样例：**

```
8 3
1 3 -1 -3 5 3 6 7
```

**输出样例：**

```
-1 -3 -3 -3 3 3
3 3 5 5 6 7
```

**思想 --- 单调队列**

求滑块最小值时，如果在滑块中`a[i] < a[j]`，那么`a[i]`不会被选择，则`pop` `a[i]`，最终队列单调队头元素最小，从队头/队尾查讯时间降为`O(1)`；普通队列做法时间复杂度为`O(n * k * n)`。

**最小值为例**
队列q的队尾为区间内最小元素的下标，队头更新为当前元素的下标，队尾到队头单调递增。每次加入新元素，比队头元素小时删除队头，比队头元素大时成为队头。

**如何保证区间左侧的下标`q[hh]`合法？**
`i-k+1`应该 **> ** `q[hh]`

**如何保证读入前k个数时没有输出最值？**
满足`i-k+1>=0`时`a[q[hh]]`才能输出即可

**Code**

```cpp
#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N],q[N];
int hh = 0,tt = -1;

int main(){
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> a[i];
    
    for (int i = 0; i < n; i ++){
        //判断队头是否已经滑出窗口
        if (hh <= tt && q[hh] < i - k + 1) hh ++;
        while (hh <= tt && a[q[tt]] >= a[i]) tt --;
        //以下两步不可颠倒!因为i可能是最小值
        q[++ tt] = i;
        //i+1小于k时的为创建未创建出完整的窗口，不输出
        if(i - k + 1 >= 0) cout << a[q[hh]] << ' ';
    }
    cout << '\n';
    
    hh = 0, tt = -1;
    for (int i = 0; i < n; i ++){
        if (hh <= tt && q[hh] < i - k + 1) hh ++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt --;
        q[++ tt] = i;
        if(i - k + 1 >= 0) cout << a[q[hh]] << ' ';
    }
    cout << '\n';
    
    return 0;
}
```

**STL实现 Monotonic类与函数接口**

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++ i) {
            if (!q.empty() && q.front() < i - k + 1) q.pop_front();
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            if (i - k + 1 >= 0) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
```



nums 中的每个元素最多被 push_back 和 pop_back ⼀次，没有任何多余操作，所以算法整体的复杂度是 O(N)。

空间复杂度取决于window大小，是O(k)。

#### 单调栈 🆚 单调队列

1.  暴力方法模拟（朴素算法）
2.  去掉没用的元素，看有没有单调性
3.  有单调性优化 - 取极值找端点 - 找点二分

## 5.树

### 二叉树结构

```cpp
struct BTNode{
    int val;
    BTNode * left;
    BTNode * right;
    BTNode(int data) {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
```



### 二叉树遍历

#### 先序遍历

**递归实现**

```cpp
void preTraversal(BTNode * head) {
    if (head == nullptr) return;
    cout << head->val << ' ';

    preTraversal(head->left);
    preTraversal(head->right);
}
```

**栈实现**

**思想**

1. 创建一个栈压入头节点
2. 弹出一个节点cur
3. 打印（处理）cur
4. **先压右再压左**（如果有）
5. 重复

```cpp
void preTraUnRecur(BTNode * head) {
    if (head != nullptr) {
        stack<BTNode *> s;
        s.push(head);
        while (!s.empty()) {
            head = s.top();
            cout << head -> val << '\n';
            s.pop();
            if (head -> right != nullptr) s.push(head -> right);
            if (head -> left != nullptr) s.push(head -> left);
        }
    }
}
```

#### 中序遍历

**递归实现**

```cpp
void inTraversal(BTNode * head) {
    if (head == nullptr) return;
    inTraversal(head->left);
    cout << head->val << ' ';

    inTraversal(head->right);
}
```

**栈实现**

**思路**

对每棵子树，整棵树左边界进栈，依次弹出节点的过程中，打印节点，然后对弹出节点的右树（如果有）重复

整个过程是**先左再头**，再操作右树的先左再头。可以说整棵树会**被左树分解掉**。

```cpp
void inTraUnRecur(BTNode * head) {
    if (head != nullptr) {
        stack<BTNode *> s;
        s.push(head);
        while (!s.empty() || head != nullptr) {
            if (head != nullptr) { // 整棵树左边界进栈
                s.push(head); // 进栈顺序：先头再左
                head = head -> left;
            }
            else {
                head = s.top();
                cout << head -> val << '\n'; // 打印顺序：先左再头（先右）再左再头
                head = head -> right; // 对弹出节点的右树（如果有）重复
                s.pop();
            }
        }
    }
}
```

#### 后序遍历

**递归实现**

```cpp
void posTraversal(BTNode * head) {
    if (head == nullptr) return;
    posTraversal(head->left);
    posTraversal(head->right);

    cout << head->val << ' ';
}
```

**栈实现**

**思路**

1. 创建两个栈
2. 收集栈收集操作栈弹出的栈顶元素
3. 操作栈**先压左后压右**

```cpp
void posTraUnRecur(BTNode * head) {
    if (head != nullptr) {
        stack<BTNode *> s1;
        stack<BTNode *> s2;
        s1.push(head);
        while (!s1.empty()) {
            head = s1.top();
			s2.push(head); // 收集操作栈弹出的栈顶元素
            s1.pop();
            if (head -> left != nullptr) s.push(head -> left);
            if (head -> right != nullptr) s.push(head -> right);
        }
        while (!s2.empty()) {
            cout << s2.top() -> val << '\n';
            s2.pop();
        }
    }
}
```

#### 整体实现


```cpp
#include <iostream>
using namespace std;

struct BTNode{
    int val;
    BTNode * left;
    BTNode * right;
    BTNode(int data) {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BTree{
public:
    BTNode *root;
    BTNode* createTree();

    void preTraversal(BTNode * root);
    void inTraversal(BTNode * root);
    void posTraversal(BTNode * root);
};
BTNode* BTree::createTree() {
    BTNode * p1 = new BTNode(1);
    BTNode * p2 = new BTNode(2);
    BTNode * p3 = new BTNode(3);
    BTNode * p4 = new BTNode(4);
    BTNode * p5 = new BTNode(5);
    BTNode * p6 = new BTNode(6);
    BTNode * p7 = new BTNode(7);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    root = p1;

    return p1;
}
void BTree::preTraversal(BTNode * root) {
    if (root == nullptr) return;
    cout << root->val << ' ';

    preTraversal(root->left);
    preTraversal(root->right);
}
void BTree::inTraversal(BTNode * root) {
    if (root == nullptr) return;
    inTraversal(root->left);
    cout << root->val << ' ';

    inTraversal(root->right);
}
void BTree::posTraversal(BTNode * root) {
    if (root == nullptr) return;
    posTraversal(root->left);
    posTraversal(root->right);

    cout << root->val << ' ';
}

int main() {
    BTree bTree;
    bTree.createTree();

    //recursive
    cout << "=====recursive=====" << '\n';
    cout << "---preTraversal---" << '\n';
    bTree.preTraversal(bTree.root);
    cout << '\n';
    cout << "---inTraversal---" << '\n';
    bTree.inTraversal(bTree.root);
    cout << '\n';
    cout << "---posTraversal---" << '\n';
    bTree.posTraversal(bTree.root);
    cout << '\n';

    return 0;
}
```

**输出**

```
=====recursive=====
---preTraversal---
1 2 4 5 3 6 7
---inTraversal---
4 2 5 1 6 3 7
---posTraversal---
4 5 2 6 7 3 1
```

### 探索二叉树的深度

```cpp
int BTreeDepth(BTNode * root) {
    if (root == nullptr) return 0;
    return max(BTreeDepth(root->left),BTreeDepth(root->right)) + 1;
}
```



### 探索二叉树的广度

```cpp
int BTreeWidth(BTNode * root) {
    if (root == nullptr) return 0;
    deque<BTNode *> q;
    unordered_map<BTNode *,int> levelMap;
    levelMap.push_back({root,1});
    int curLevel = 1; // 当前层
    int curNodes = 0;
    int maxNum = INT_MIN; // -1
    while (!q.empty()) {
        BTNode * cur = q.back(); q.pop_back();
        int curNodeLevel = levelMap[cur]; // 当前节点层
        if (curLevel == curNodeLevel) {
            curNodes ++;
        } else {
            maxNum = max(maxNum,curNodes);
            curLevel ++;
            curNodes = 1;
        }
        if (cur -> left != nullptr) {
            levelMap.push_back({cur->left,curNodeLevel+1});
            q.push_front(cur->left);
        }
        if (cur -> right != nullptr) {
            levelMap.push_back({cur->right,curNodeLevel+1});
            q.push_front(cur->right);
        }
    }
	maxNum = max(maxNum,curNodes);
    return maxNum;
}
```

### 搜索二叉树实现

#### 判断一棵树是否为搜索二叉树


**方案一**

```cpp
void inOrderRecur(BTNode * root,vector<int> vt) {
    if (head == nullpter) return;
    inOrderRecur(root -> left,vt);
    vt.push_back(root -> val);
    inOrderRecur(root -> right,vt);
}
bool isBST(BTNode * root) {
    vector<int> vt;
    inOrderRecur(root,vt);
    return is_ordered(vt.begin(),vt.end());
}
```

**方案二**

```cpp
int preVal = INT_MIN;
bool isBST(BTNode * root) {
    if (root == nullptr) return true;
    if (!isBST(root -> left)) return false;
    if (root->val <= preVal) return false;
    else preVal = root -> val;
    return isBST(root -> right);
}
```

### 判断一棵树是否为完全二叉树



```cpp
bool isCST(BTNode * root) {
    bool leaf = false;
    deque<BTNode *> q; // 广搜用队列
    q.push_front(root);
    while (!q.empty()) {
        root = q.back();
        q.pop();
        if (leaf && (root->left || root->right) // 左右两个孩子不双全，接下来所有的节点都必须是叶节点
           || root->left == nullptr && root->right != nullptr) // 有右无左
            return false;
        
        if (root -> left) q.push_front(root->left);
        if (root -> right) q.push_front(root->right);
        if (root -> left == nullptr || root -> right == nullptr) leaf = true;
    }
    return true;
}
```

### 二叉树递归套路

判断满二叉树、平衡二叉树、搜索二叉树

**平衡二叉树**（左树与右树高度差<=1）成立条件：`左树AVL && 右树AVL && |hl - hr|<= 1`

```cpp
pair<bool,int> PBI;
PBI isBalanced(BTNode * root) {
    if (root == nullptr) return {true,0};
    PBI left = isBalanced(root -> left);
    PBI right = isBalanced(root -> right);
    
    bool isAVL = left.first && right.first && abs(left.second - right.second) <= 1;
    int height = max(left.second,right.second) + 1;
    return {isAVL,height};
}
bool isAVL(BTNode * root) {
    return isBalanced(root).first;
}
```

**搜索二叉树** 成立条件：`左树BST && 右树BST && lmax < root && rmin > root`

```cpp
class returnType{
public:
	bool isBst;
    int lmax;
    int rmin;
    returnType(bool isbst, int max, int min):isBst(isbst), lmax(max), rmin(min){}
};
returnType::isBST(BTNode * root) {
	if (root == nullptr) return NULL;
    returnType left = isBST(root -> left);
    returnType right = isBST(root -> right);
    
    bool isBst = true;
    if (left && (!left.isBst || left.lmax >= root->val)) return false;
    if (right && (!right.isBst || right.rmin <= root->val)) return false;
        
    int lmax = root -> val;
    int lmin = root -> val;
    if (left) {
        rmin = min(rmin,left.rmin);
        lmax = max(lmax,left.lmax);
    }
    if (right) {
        rmin = min(rmin,right.rmin);
        lmax = max(lmax,right.lmax);
    }
    
    return {isBst,lmax,rmin};
}
```

例题 --- 二叉搜索树的最近公共祖先

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]



**示例 1:**

```
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
```

解释: 节点 2 和节点 8 的最近公共祖先是 6。
**示例 2:**

```
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
```

解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。

**说明:**

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉搜索树中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree

**Code**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<TreeNode *> getPath(TreeNode * root, TreeNode * target) {
        vector<TreeNode *> path;
        while (root != target) {
            path.push_back(root);
            if (target->val < root->val) root = root -> left;
            else if (target->val > root->val) root = root -> right;
        }
        path.push_back(root);

        return path;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> p_path = getPath(root,p);
        vector<TreeNode *> q_path = getPath(root,q);
        TreeNode * ancestor;
        for (int i = 0; i < min(p_path.size(),q_path.size()); i ++) {
            if (p_path[i] == q_path[i]) ancestor = p_path[i];
        }

        return ancestor;
    }
};
```

### 判断二叉树某一节点是否存在后继节点

1. 节点p有右子树 -> 右子树最左的节点为后继节点（向下、左找）；
2. 节点p没有右子树 -> 如果p是其父节点的右节点，向上找，直到某一节点q是其父节点的左孩子（此时q的父节点为p的后继节点）、如果直到q的父节点为空也没有找到使q为其左孩子的父节点（说明p是该树最右节点返回空）返回父节点

```cpp
BTNode* getSucessorNode(BTNode * Node) {
    if (Node == nullptr) return nullptr;
    if (Node -> right) { // 情况1.有右子树
        Node = Node -> right;
        while (Node->left) Node = Node -> left;
        return Node;
    } else { // 情况2.无右子树
        while (Node->parent && Node->parent->right == Node) {
            Node = Node -> parent;
        }
        return Node -> parent;
    }
}
```



## 6.堆

### 堆的功能

|       操作       |                      Code                      |
| :--------------: | :--------------------------------------------: |
|    插入一个值    |          heap[++ size] = x; up(size);          |
| 求集合当中最小值 |                    heap[1];                    |
|    删除最小值    |    heap[1] = heap[size]; size --; down(1);     |
| 删除任意一个元素 | heap[k] = heap[size]; size --; down(k); up[k]; |
| 修改任意一个元素 |          heap[k] = x; down(k); up(k);          |

**模板**

```cpp
void heap_swap(int a, int b) {
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(heap[a],heap[b]);
}
void down(int x) {
    int t = x;
    if (x * 2 <= siZ && heap[t] > heap[x * 2]) t = x * 2;
    if (x * 2 + 1 <= siZ && heap[t] > heap[x * 2 + 1]) t = x * 2 + 1;

    if (t != x) {
        swap(heap[x],heap[t]);
        down(t);
    }
}
//递归版up()
void up(int x) {
    if (x / 2 && heap[x / 2] > heap[x]) {
        heap_swap(x / 2, x);
        up(x >> 1);
    }
}
//非递归版up()
void up(int x) {
    while (x / 2 && heap[x / 2] > heap[x]) {
        heap_swap(x / 2, x);
        x /= 2;
    }
}
```



### 堆的结构

**完全二叉树**

#### 分类

##### 小根堆

根结点最小（上小下大）每个节点小于它的左右儿子节点（如果有的话）

##### 存储

左儿子：`2x`、右儿子：`2x+1`

##### 大根堆

根结点最大（上大下小）每个节点大于它的左右儿子节点（如果有的话）



##### 例题 --- 堆排序（正序、小根堆）

输入一个长度为 n 的整数数列，从小到大输出前 m 小的数。

**输入格式**

第一行包含整数 `n` 和 `m`。

第二行包含 `n` 个整数，表示整数数列。

**输出格式**

共一行，包含 `m` 个整数，表示整数数列中前 `m` 小的数。

**数据范围**

1 ≤ m ≤ n ≤ 10^5^
1 ≤ 数列中元素 ≤ 10^9^

**输入样例**：

```
5 3
4 5 1 3 2
```

**输出样例**：

```
1 2 3
```

**Code**

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int heap[N], siZ;

void down(int x) {
    int t = x;
    if (x * 2 <= siZ && heap[t] > heap[x * 2]) t = x * 2;
    if (x * 2 + 1 <= siZ && heap[t] > heap[x * 2 + 1]) t = x * 2 + 1;

    if (t != x) {
        swap(heap[x],heap[t]);
        down(t);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> heap[i];
    siZ = n;
    int i = n / 2;
    while (i) down(i --);

    while (m -- ) {
        cout << heap[1] << ' ';
        heap[1] = heap[siZ];
        siZ --;
        down(1);
    }
    cout << '\n';
    return 0;
}
```

##### 例题 --- 模拟堆

维护一个集合，初始时集合为空，支持如下几种操作：

1. `I x`，插入一个数 x；
2. `PM`，输出当前集合中的最小值；
3. `DM`，删除当前集合中的最小值（数据保证此时的最小值唯一）；
4. `D k`，删除第 k 个插入的数；
5. `C k x`，修改第 k 个插入的数，将其变为 x；

现在要进行 N 次操作，对于所有第 2 个操作，输出当前集合的最小值。

**输入格式**

第一行包含整数 N。

接下来 N 行，每行包含一个操作指令，操作指令为 `I x`，`PM`，`DM`，`D k` 或 `C k x` 中的一种。

**输出格式**

对于每个输出指令 `PM`，输出一个结果，表示当前集合中的最小值。

每个结果占一行。

**数据范围**

1 ≤ N ≤ 10^5^
−10^9^ ≤ x ≤ 10^9^
数据保证合法。

**输入样例**：

```
8
I -10
PM
I -10
D 1
C 2 8
I 6
PM
DM
```

**输出样例**：

```
-10
6
```

**Code**

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int heap[N], ph[N], hp[N], siZ, m;
// ph[]: 存放第k个插入点的下标; hp[]: 存放堆中点的插入次序

void heap_swap(int a, int b) {
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(heap[a],heap[b]);
}
void down(int x) {
    int t = x;
    if (x * 2 <= siZ && heap[x * 2] < heap[t]) t = x * 2;
    if (x * 2 + 1 <= siZ && heap[x * 2 + 1] < heap[t]) t = x * 2 + 1;
    
    if (t != x) {
        heap_swap(t,x);
        down(t);
    }
}
void up(int x) {
    while (x / 2 && heap[x / 2] > heap[x]) {
        heap_swap(x / 2,x);
        x /= 2;
    }
}

int main() {
    int n;
    cin >> n;
    while (n -- ) {
        string ops;
        int x, k;
        cin >> ops;
        if (ops == "I") {
            cin >> x;
            heap[++ siZ] = x;
            m ++; // 记录插入次数
            //每次插入都在堆尾
            ph[m] = siZ;
            hp[siZ] = m;
            up(siZ);
        }
        else if (ops == "PM") cout << heap[1] << '\n';
        else if (ops == "DM") {
            heap_swap(1,siZ);
            siZ --;
            down(1);
        }
        else if (ops == "D") {
            cin >> k;
            k = ph[k]; // 必须要保存当前被删除结点的位置
            heap_swap(k,siZ); // 第k个插入的元素移到了堆尾，此时ph[k]指向堆尾 
            siZ --;
            // k是之前记录被删除的结点的位置
            up(k);
            down(k);
        }
        else if (ops == "C") {
            cin >> k >> x;
            k = ph[k];
            heap[k] = x;
            down(k);
            up(k);
        }
    }
    return 0;
}
```



## 7.哈希表

### 存储结构

#### 开放寻址法



#### 拉链法

##### 例题 --- 模拟散列表

维护一个集合，支持如下几种操作：

1. `I x`，插入一个数 `x`；
2. `Q x`，询问数 `x` 是否在集合中出现过；

现在要进行 `N` 次操作，对于每个询问操作输出对应的结果。

**输入格式**

第一行包含整数 N，表示操作数量。

接下来 N 行，每行包含一个操作指令，操作指令为 `I x`，`Q x` 中的一种。

**输出格式**

对于每个询问指令 `Q x`，输出一个询问结果，如果 x 在集合中出现过，则输出 `Yes`，否则输出 `No`。

每个结果占一行。

**数据范围**

1 ≤ N ≤ 10^5^
−10^9^ ≤ x ≤ 10^9^

**输入样例**：

```
5
I 1
I 2
I 3
Q 2
Q 5
```

**输出样例**：

```
Yes
No
```

**Code**

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int e[N], ne[N], Hash[N], idx;

void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = Hash[k];
    Hash[k] = idx ++;
}
bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = Hash[k]; i != -1; i = ne[i]) {
        if (e[i] == x) return true;
    }
    return false;
}

int main () {
    int n;
    cin >> n;
    memset(Hash, -1, sizeof Hash);
    while (n -- ) {
        char ops;
        int x;
        cin >> ops >> x;

        if (ops == 'I') {
            insert(x);
        }
        else if (ops == 'Q') {
            if (find(x)) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
    }
    return 0;
}
```



### 字符串哈希

**字符串前缀哈希法：**

将字符串看作是 `n` 位 `p进制数` ，转换成十进制数后 `mod q`，便将字符串映射为 `0 ~ q - 1` 的数

***注意***

1. 不要把字符串映射成0！（***Hash[0] = 0***）
2. 人品足够好，不发生冲突情况（一般：**p = 131 / 13331; q = 2^64^** 冲突概率小）
3. 用unsigned long long 存储数据（*溢出相当于取mod*）

Hash[R]: p^R-1^...p^0^

Hash[L-1]: p^L-2^...p^0^

**=> Hash[L ~ R] = Hash[R] - Hash[L - 1] * p^R-L+1^ **

预处理后可用 ***O(1)*** 时间获取每个子串Hash！

##### 例题 --- 字符串哈希

给定一个长度为 n 的字符串，再给定 m 个询问，每个询问包含四个整数 l1,r1,l2,r2，请你判断 `[l1,r1]` 和 `[l2,r2]` 这两个区间所包含的字符串子串是否完全相同。

字符串中只包含大小写英文字母和数字。

**输入格式**

第一行包含整数 `n` 和 `m`，表示字符串长度和询问次数。

第二行包含一个长度为 n 的字符串，字符串中只包含大小写英文字母和数字。

接下来 m 行，每行包含四个整数 `l1,r1,l2,r2`，表示一次询问所涉及的两个区间。

`注意，字符串的位置从 1 开始编号。`

**输出格式**

对于每个询问输出一个结果，如果两个字符串子串完全相同则输出 `Yes`，否则输出 `No`。

每个结果占一行。

**数据范围**

1 ≤ n , m ≤ 10^5^

**输入样例**：

```
8 3
aabbaabb
1 3 5 7
1 3 6 8
1 2 1 2
```

**输出样例**：

```
Yes
No
Yes
```

**Code**

```cpp
#include <iostream>
using namespace std;

typedef unsigned long long ULL;
const int N = 1e5 + 10, P = 131;
ULL Hash[N], p[N];
char s[N];

ULL hashGet(int l, int r) {
    return Hash[r] - Hash[l - 1] * p[r - l + 1];
}
int main() {
    int n, m;
    scanf("%d%d%s", &n, &m, s + 1);
    
    p[0] = 1; // Hash[0] = 0
    for (int i = 1; i <= n; ++ i) {
        p[i] = p[i - 1] * P;
        Hash[i] = Hash[i - 1] * P + s[i];
    }
    
    int l1, r1, l2, r2;
    while (m -- ) {
        cin >> l1 >> r1 >> l2 >> r2;
        if (hashGet(l1, r1) == hashGet(l2, r2)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
```



## 8.图

### 表示方法

#### 邻接表法

#### 邻接矩阵法

**（未完待续...）**
