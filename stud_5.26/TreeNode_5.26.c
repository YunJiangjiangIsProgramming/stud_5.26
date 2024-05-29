#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//oj第一题错误
//struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//    
//};
//
//int TreeSize(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//    return 1 + TreeSize(root->left) + TreeSize(root->right);
//
//}
//void _inorderTraversal(struct TreeNode* root, int* arry, int* pi)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    _inorderTraversal(root->left, arry, pi);
//    arry[(*pi) + 1] = root->val;
//    _inorderTraversal(root->right, arry, pi);
//
//
//}
//
//int* inorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    int Size = TreeSize(root);
//    int* arry = (int*)malloc(sizeof(int) * Size);
//    int i = 0;
//    _inorderTraversal(root, arry, &i);
//    *returnSize = Size;
//    return root;
//}


#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 计算树的大小
int TreeSize(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + TreeSize(root->left) + TreeSize(root->right); // 包括根节点
}

// 中序遍历递归函数
void _inorderTraversal(struct TreeNode* root, int* arry, int* pi)
{
    if (root == NULL)
    {
        return;
    }
    _inorderTraversal(root->left, arry, pi);
    arry[*pi] = root->val; // 使用正确的索引
    (*pi)++; // 移动到下一个位置
    _inorderTraversal(root->right, arry, pi);
}

// 中序遍历主函数
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int Size = TreeSize(root);
    int* arry = (int*)malloc(sizeof(int) * Size);
    int i = 0;
    *returnSize = 0; // 初始化返回大小为0
    _inorderTraversal(root, arry, &i);
    *returnSize = Size; // 设置实际返回的大小
    return arry; // 返回中序遍历的数组
}

//// 示例代码，如何使用inorderTraversal函数
//int main() {
//    // 构建一棵简单的树
//    struct TreeNode root;
//    root.val = 1;
//    root.left = NULL;
//    root.right = NULL;
//
//    int returnSize;
//    int* result = inorderTraversal(&root, &returnSize);
//
//    // 打印中序遍历结果
//    for (int i = 0; i < returnSize; i++) {
//        printf("%d ", result[i]);
//    }
//    free(result); // 不要忘记释放内存
//    return 0;
//}
