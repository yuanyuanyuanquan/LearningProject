#include <stdio.h>
#include <stdlib.h>

/* 单链表的实现与基本功能测试 */

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

/* 求链表的长度 */
int listLength(struct Node* list) {
    struct Node* pList = list->next;
    int length = 0;
    while(pList) {
        pList = pList->next;
	length++;
    }

    return length;
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
    insertNodeByHead(list, 10001);
    insertNodeByHead(list, 10002);
    insertNodeByHead(list, 10003);
    testList(list);
    printf("当前单链表的长度为：%d \n", listLength(list));

    return 0;
}
