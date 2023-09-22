# 1 

- 这个相当于把生成树，和前序遍历合到一起

# 2 

- 经典算法，把前序中序 or 后序中序 生成树
- 结构体

```c++
struct node {
    char val;
    node *left;
    node *right;
    node() : val(0), left(nullptr), right(nullptr){}
    node(int x) : val(x), left(nullptr), right(nullptr){}
    node(int val, node *left, node *right) : val(val), left(left), right(right){}
};
```
