/* 力扣(LeetCode)题库：用C语言实现
 *
 * CreateTime: 2022-06-13  11:50
 */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"

#define TRUE  (true)
#define FALSE (false)

/* 定义常规的单向链表 */
struct ListNode{
    int value;
    struct ListNode* next;
};

/* 1. 两数之和
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 *
 * 难度：简单
 * 思路：暴力解法。推荐使用链表的方式
 **/
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    static int out[2];
    for (int i = 0; i < numsSize-1; i++) {
        int temp = target - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == temp) {
                out[0] = i;
                out[1] = j;
                goto OUT;
            } 
        }
    }
OUT:
    return out;
}

/* 2. 两数相加
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 * 难度：中等
 * 思路：采用链表的方式
 **/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode* node = NULL;
    int carry = 0;  // 用于记录进位信息
    int val_1 = 0;  // 记录链表l1的节点数据
    int val_2 = 0;  // 记录链表l2的节点数据

    while(l1 != NULL || l2 != NULL) {
        if (head) {
            node->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            node = node->next;
        } else {
            head = (struct ListNode*)malloc(sizeof(struct ListNode));
            head->value = 0;
            head->next = NULL;
            node = head;
        }

        if (l1 == NULL) {
            val_1 = 0;
        } else {
            val_1 = l1->value;
            l1 = l1->next;
        }

        if (l2 == NULL) {
            val_2 = 0;
        } else {
            val_2 = l2->value;
            l2 = l2->next;
        }

        node->value = (val_1 + val_2 + carry) % 10;
        carry = (val_1 + val_2 + carry) / 10;
        node->next = NULL;
    }

    if (carry == 1) {
        node->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        node = node->next;
        node->value = carry;
        node->next = NULL;
    }

    return head;
}

/* 9. 回文数
 * 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 难度：简单
 * 思路：
 **/
bool isPalindrome(int x) {
    bool is = TRUE;
    int  div = 1;

    if (x < 0) {
        return is = FALSE;
    }

    while(x/div >= 10) div = div * 10;
    
    while(x > 0) {
        int min = x % 10;
        int max = x / div;
        if (min != max) {
            return is = FALSE;
        }
        x = (x % div) / 10;
        div = div / 100;
    }

    return is;
}

/* 14. 最长公共前缀
 * 编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。
 * 
 * 难度：简单
 * 思路：
 **/
char * longestCommonPrefix(char ** strs, int strsSize) {
    if (!strsSize) {
        return "";
    }

    int minLen = strlen(strs[0]);
    
    for(int i = 1; i < strsSize; ++i) {
        if(minLen > strlen(strs[i])) {
            minLen = strlen(strs[i]);
        }
    }
    
    char* result = (char*)malloc(sizeof(char)*(minLen+1));
    result[0] = 0;
    
    for(int i = 0; i < minLen; ++i) {
        for(int j = 1; j < strsSize; ++j) {
            if(strs[j][i] != strs[0][i])
            return result;
        }

        result[i] = strs[0][i];
        result[i+1] = 0;
    }

    return result;
}

/* 21. 合并两个有序链表
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 难度：简单
 * 思路：递归法
 **/
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (list1 == NULL) {
        return list2;
    }

    if (list2 == NULL) {
        return list1;
    }

    if (list1->value < list2->value) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

/* 83. 删除排序链表中的重复元素 
 * 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
 * 
 * 难度：简单
 * 思路：
 **/
struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* pList = head;
    struct ListNode* qList = head->next;

    while(qList != NULL) {
        if (qList->value == pList->value) {
            pList->next = qList->next;
            free(qList);
            qList = pList->next;
        } else {
            pList = qList;
            qList = qList->next;
        }
    }

    return head;
}

/* 136. 只出现一次的数字
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 难度：简单
 * 思路：题中明确提出每个元素均出现两次，按位异或(^=)两次后保持不变
 **/
int singleNumber(int* nums, int numsSize){
    int reslut = nums[0];

    for (int i = 1; i < numsSize; i++) {
        reslut ^= nums[i];  // 同一数两次异或后保持只出现一次的数
    }

    return reslut;
}

/* 35. 搜索插入位置
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 请必须使用时间复杂度为 O(log n) 的算法。
 * 
 * 难度：简单
 * 思路：
 **/
int searchInsert(int* nums, int numsSize, int target){
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= target) {
            return i;
        }
    }

    return numsSize;
}

/* 3. 无重复字符的最长子串
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 * 难度：中等
 * 思路：采用滑动窗口的方式解决
 **/
int lengthOfLongestSubstring(char * s){
    if (s == NULL) {
        return 0;
    }

    int slen  = strlen(s);
    int left  = 0;
    int right = -1;
    int max   = right - left +1;

    for (int i = 0; i < slen; i++) {
        for (int j = left; j <= right; j++) {
            if (s[i] == s[j]) {
                left = j + 1;
                break;
            }
        }
        right++;
        if (max <= right - left +1) {
            max = right - left + 1;
        }
    }

    return max;
}