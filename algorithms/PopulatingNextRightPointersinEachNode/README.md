## Populating Next Right Pointers in Each Node

Given a binary tree

```cpp
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
```
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.

Initially, all next pointers are set to `NULL`.

Note:

* You may only use constant extra space.
* You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

```
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
```

After calling your function, the tree should look like:

```
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
```

## Solution

层次遍历，若当前节点和下一个节点的层次相同，则连接当前节点指向下一个节点

```cpp
struct Bucket {
	TreeLinkNode *node;
	int level;
	Bucket(TreeLinkNode *p, int l) : node(p), level(l){}
};
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == nullptr)
			return;
		queue<Bucket> q;
		q.push(Bucket(root, 0));
		while (!q.empty()) {
			Bucket current = q.front();
			TreeLinkNode *p = current.node;
			int level = current.level;
			q.pop();
			if (!q.empty()) { // 注意检查是否还存在节点
				Bucket next = q.front();
				if (current.level == next.level) {
					p->next = next.node;
				}
			}
			if (p->left)
				q.push(Bucket(p->left, level + 1));
			if (p->right)
				q.push(Bucket(p->right, level + 1));
		}
	}
};
```
