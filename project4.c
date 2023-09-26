#include <stdio.h>
#include <stdlib.h>

// 이진 트리 노드를 나타내는 구조체 정의
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 새로운 노드를 생성하는 함수
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 중위 순회 함수
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// 노드의 부모를 찾는 함수
int findParent(struct TreeNode* root, int target, int parent) {
    if (root == NULL) {
        return -1; // 노드를 찾지 못한 경우
    }

    if (root->data == target) {
        return parent; // 노드를 찾은 경우 부모 노드 반환
    }

    // 왼쪽 서브트리에서 찾기
    int leftResult = findParent(root->left, target, root->data);
    if (leftResult != -1) {
        return leftResult; // 왼쪽 서브트리에서 찾은 경우 반환
    }

    // 오른쪽 서브트리에서 찾기
    int rightResult = findParent(root->right, target, root->data);
    return rightResult; // 오른쪽 서브트리에서 찾은 경우 반환
}

int main() {
    // 이진 트리 생성
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->left->left->left = newNode(4);
    root->left->left->right = newNode(5);
    root->right->right = newNode(9);
    root->right->right->left = newNode(10);
    root->right->left = newNode(8);
    root->right->right->right = newNode(11);

    // 중위 순회 결과 출력
    printf("1. 중위 순회 결과: ");
    inorderTraversal(root);
    printf("\n");

    // 각 노드의 부모 출력
    printf("2. Node 4의 부모: %d\n", findParent(root, 4, -1));
    printf("3. Node 5의 부모: %d\n", findParent(root, 5, -1));
    printf("4. Node 6의 부모: %d\n", findParent(root, 6, -1));

    return 0;
}
