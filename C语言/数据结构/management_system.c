#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_LENGTH (20)

/* 定义学生结构体 */
typedef struct Student{
    char studentID[MAX_LENGTH];
    char studentName[MAX_LENGTH];
} Student;

/* 定义链表结构 */
struct Node{
    Student data;
    struct Node* next;
};

/* 定义提示菜单 */
void checkMenu() {
    printf("******************************************************* \n");
    printf("* * * * * * * * * * *   菜    单  * * * * * * * * * * * \n");
    printf("*      1.增加学生记录             2.删除学生记录      * \n");
    printf("*      3.查找学生记录             4.修改学生记录      * \n");
    printf("*      5.统计学生人数             6.显示学生记录      * \n");
    printf("*      7.退 出  系 统                                 * \n");
    printf("******************************************************* \n");
}

/* 打印提示信息 */
void inputStudent(struct Node* list) {
    printf("请输入添加学生的学号：");
    scanf("%s", list->data.studentID);
    printf("请输入添加学生的姓名：");
    scanf("%s", list->data.studentName);

    // 每个新创建节点的next均初始化为NULL
    list->next = NULL;
}

void inputStudentID(char* menu, char* id) {
    printf("请输入要%d的学生学号：", menu);
    scanf("%s", id);
}

void displayNode(struct Node* list) {
    struct Node* pList = list->next;
    int length = 1;

    while(pList != NULL) {
        printf("%d.学生学号：%s, 学生姓名：%s \n", length, pList->data.studentID, pList->data.studentName);
	pList = pList->next;
    }
}

/* 增加学生记录 */
int addNode(struct Node* list) {
    struct Node* pList = NULL;
    struct Node* qList = NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    inputStudent(node);
    qList = list;
    pList = list->next;
    if (list->next == NULL) {
        list->next = node;
    } else {
        while(pList != NULL) {
	    if (node->data.studentID < pList->data.studentID) {
	        qList->next = node;
		node->next = pList;

		return 0;
	    } else {
	        qList = pList;
		pList = pList->next;
	    }
	}
	qList->next = node;
    }

    return 0;
}

int deleteNode(struct Node* list) {
    char tips[MAX_LENGTH];
    inputStudentID("删除", tips);

    return -1;
}

int queryNode(struct Node* list) {
    char tips[MAX_LENGTH];
    inputStudentID("查询", tips);

    return -1;
}

int modifyNode(struct Node* list) {
    char tips[MAX_LENGTH];
    inputStudentID("修改", tips);

    return -1;
}

int countNode(struct Node* list) {
    struct Node* pList = list->next;
    int count = 0;

    while(pList != NULL) {
        pList = pList->next;
	count++;
    }

    return count;
}

void clearList(struct Node* list) {
    struct Node* pList;

    while(list != NULL) {
        pList = list;
	list = list->next;
	free(pList);
    }
}

int main() {
    int select;
    int count;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->next = NULL;

    while(1) {
        checkMenu();
	printf("\n请输入你的选择(1-7)：");
	scanf("%d", &select);
	switch(select) {
	    case 1:
                if (!addNode(node)) {
		    printf("成功插入一个学上记录。\n\n");
		}
		break;
	    case 2:
		if (!deleteNode(node)) {
		    printf("已成功删除学生记录。\n\n");
		} else {
		    printf("未找到该学号的学生。\n\n");
		}
		break;
	    case 3:
		if (!queryNode(node)) {
		    printf("成功找到学生记录。\n\n");
		} else {
		    printf("未找到该学号的学生。\n\n");
		}
		break;
	    case 4:
		if (!modifyNode(node)) {
		    printf("已成功修改学生记录。\n\n");
		} else {
		    printf("未找到该学号的学生。\n\n");
		}
		break;
	    case 5:
		count = countNode(node);
		printf("学生人数为：%d \n\n", count);
		break;
	    case 6:
		displayNode(node);
		break;
	    case 7:
		clearList(node);
		return 0;
	    default:
		printf("输入不正确，应该输入1-7之间的数。");
		break;
	}
    }

    return 0;
}


















