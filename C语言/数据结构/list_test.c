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

/* 在链表头部插入（参数列表：目标链表、节点数据） */
void insertNodeByHead(struct Node* headNode, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = headNode->next;
    headNode->next = newNode;
}

/* 指定位置插入（参数列表：目标链表、指定位置、节点数据） */
int insertNodeSpecifyLocation(struct Node* list, int location, int data) {
    struct Node* pList = list;
    int count = 0;

    while(pList != NULL && count < location-1) {
        pList = pList->next;
	 count++;
    }

    if (pList == NULL) {
        return -1;
    } else {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	 node->data = data;
	 node->next = pList->next;
	 pList->next = node;

	 return 0;
    }
}

/* 在链表尾部插入（参数列表：目标链表、链表长度、节点数据） */
void insertNodeByTail(struct Node* list, int length, int data) {
    struct Node* newNode = createNode(data);
    struct Node* pList = list->next;
    int count = 0;

    while(count < length-1) {
        pList = pList->next;
        count++;
    }

    pList->next = newNode;
}

/* 求链表的长度 */
int listLength(struct Node* list) {
    struct Node* pList = list->next;
    int length = 0;

    while(pList != NULL) {
        pList = pList->next;
	 length++;
    }

    return length;
}

/* 单链表的查找操作（参数列表：查找链表、查找元素） */
int queryList(struct Node* list, int query) {
    struct Node* pList = list->next;
    int seat = 1;

    while(pList != NULL) {
        if (pList->data == query) {
	    printf("查找的该元素在链表的第 %d 个节点。 \n", seat);
	    return 0;
	}
	pList = pList->next;
	seat++;
    }
    printf("未找到该元素值!! \n");

    return -1;
}

/* 根据数据删除链表中的某个节点 */
int deleteNode(struct Node* list, int data) {
    if (list == NULL || list->next == NULL) {
        return -1;
    }

    struct Node* pList = list->next;
    struct Node* qList = list;

    while(pList != NULL) {
        if (pList->data == data) {
	    qList->next = pList->next;
	    free(pList);

	    return 0;
	} else {
	    qList = pList;
	    pList = pList->next;
	}
    }

    return -1;
}

/* 单链表的释放 */
void clearList(struct Node* list) {
    struct Node* pList;

    while(list != NULL) {
        pList = list;
        list = list->next;
        free(pList);
    }
}

/* 测试链表（输出链表内容） */
void printList(struct Node* list) {
    struct Node* pList = list->next;

    while(pList != NULL) {
        printf("************(%d) \n", pList->data);
	 pList = pList->next;
    }
}

int main()
{
    /* 动态生成链表 */
    struct Node* list = createList();
    /* 链表头部插入数据 */
    insertNodeByHead(list, 10001);
    insertNodeByHead(list, 10002);
    insertNodeByHead(list, 10003);
    printList(list);
    /* 打印链表的长度 */
    printf("当前单链表的长度为：%d \n", listLength(list));
    /* 根据数值查找链表节点的位置 */
    queryList(list, 10002);
    /* 指定位置插入数据 */
    insertNodeSpecifyLocation(list, 2, 10004);
    /* 链表尾部插入数据 */
    insertNodeByTail(list, listLength(list), 10005);
    printList(list);
    /* 删除指定数据位置的节点 */
    deleteNode(list, 10003);
    printList(list);
    /* 释放链表 */
    clearList(list);

    return 0;
}
