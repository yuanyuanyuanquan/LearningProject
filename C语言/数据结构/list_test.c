#include <stdio.h>
#include <stdlib.h>

/* 声明链表结构体 */
struct Node{
    int data;           // 数据域
    struct Node* next;  // 指针域
};

/* 创建链表以及初始化链表 */
struct Node* createList() {
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;

    return headNode;
}

/* 创建新的节点 */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

/* 插入节点（参数列表：目标链表、节点数据） */
void insertNodeByHead(struct Node* headNode, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = headNode->next;
    headNode->next = newNode;
}

/* 测试链表（输出链表内容） */
void testList(struct Node* list) {
    struct Node* pList = list->next;
    while(pList) {
        printf("************(%d) \n", pList->data);
	pList = pList->next;
    }
}

int main()
{
    /* 动态生成链表 */
    struct Node* list = createList();
    insertNodeByHead(list, 10086);
    insertNodeByHead(list, 1008611);
    insertNodeByHead(list, 10000);
    testList(list);

    return 0;
}
