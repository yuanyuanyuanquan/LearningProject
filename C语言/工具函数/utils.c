#include "stdio.h"
#include "regex.h"
#include "fcntl.h"
#include "string.h"
#include "unistd.h"
#include "stdlib.h"
#include "arpa/inet.h"
#include "sys/socket.h"
#include "net/ethernet.h"

/**
 * 使用指定的字符分割字符串 (原字符串中的分隔符号将被替换成 '\0')
 * 
 * @param src 待分割字符串
 * @param separator 分割字符
 * @param dest 接收子字符串的数组
 * @param size 数组长度
 * 
 * @return -1:参数错误; 其他:分割后的子字符串个数
 **/
int split_string_with_maxlen(char* src, char separator, char** dest, int size) {
    if (src == NULL || dest == NULL || size <= 0) {
        return -1;
    }

    int count = 0;
    char* prev = src;
    char* next;

    while ((next = strchr(prev, separator)) != NULL) {
        dest[count++] = prev;
        *next = '\0';

        if (count >= size) {
            break;
        }
        prev = next + 1;
    }
    if (count < size) {
        dest[count++] = prev;
    }
    return count;
}

/**
 * 使用指定的字符分割字符串(不会出现空字符串: 忽略开头和末尾的空格, 多个空格当一个处理)
 *
 * @param src 待分割字符串
 * @param separator 分割字符
 * @param dest 接收子字符串的数组
 * @param size 数组长度
 *
 * @return -1:参数错误; 其他:分割后的子字符串个数
 **/
int split_string_with_maxlen_2(char* src, char separator, char** dest, int size) {
    if (src == NULL || dest == NULL || size <= 0) {
        return -1;
    }

    int count = 0;
    char* prev = src;
    char* next;

    while ((next = strchr(prev, separator)) != NULL) {
        if (next != prev) {
            dest[count++] = prev;
            *next = '\0';

            if (count >= size) {
                break;
            }
        }
        prev = next + 1;
    }
    if (*prev != '\0' && count < size) {
        dest[count++] = prev;
    }
    return count;
}

/**
 * 校验IPv4的合法性
 *
 * @param ipv4 IPv4
 *
 * @return 0:IPv4合法;其他:非法IPv4
 **/
int validata_ipv4_start(const char *ipv4) {
    int temp = 0;
    regex_t regex = {0};
    regmatch_t match[10] = {0};
    char *pattern = "^(([0-9]|[0-9][0-9])|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$";

    if (ipv4 == NULL || ipv4[0] == '\0') {
        return -1;
    }

    if (regcomp(&regex, pattern, 1) < 0) {
        return -1;
    }

    temp = regexec(&regex, ipv4, 10, match, 0);
    regfree(&regex);

    return (temp ? -1 : 0)
}





















