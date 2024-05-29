#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//oj��һ�����
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

// �������Ĵ�С
int TreeSize(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + TreeSize(root->left) + TreeSize(root->right); // �������ڵ�
}

// ��������ݹ麯��
void _inorderTraversal(struct TreeNode* root, int* arry, int* pi)
{
    if (root == NULL)
    {
        return;
    }
    _inorderTraversal(root->left, arry, pi);
    arry[*pi] = root->val; // ʹ����ȷ������
    (*pi)++; // �ƶ�����һ��λ��
    _inorderTraversal(root->right, arry, pi);
}

// �������������
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int Size = TreeSize(root);
    int* arry = (int*)malloc(sizeof(int) * Size);
    int i = 0;
    *returnSize = 0; // ��ʼ�����ش�СΪ0
    _inorderTraversal(root, arry, &i);
    *returnSize = Size; // ����ʵ�ʷ��صĴ�С
    return arry; // �����������������
}

//// ʾ�����룬���ʹ��inorderTraversal����
//int main() {
//    // ����һ�ü򵥵���
//    struct TreeNode root;
//    root.val = 1;
//    root.left = NULL;
//    root.right = NULL;
//
//    int returnSize;
//    int* result = inorderTraversal(&root, &returnSize);
//
//    // ��ӡ����������
//    for (int i = 0; i < returnSize; i++) {
//        printf("%d ", result[i]);
//    }
//    free(result); // ��Ҫ�����ͷ��ڴ�
//    return 0;
//}
