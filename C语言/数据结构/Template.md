/* 模板类文件:常见的方法技巧 */

/* 滑动窗口的模板 */

/* 
 * 寻找最长子串的模板
 * @param left 左指针(窗口左侧)
 * @param right 右指针
 * @param result 当前结果
 * 
 * @return bestResult 最优结果
 **/
findMaxLenFunc() {
    初始化left、right、result、bestResult
    while (右指针没有到结尾) {
        窗口扩大,加入right对应的元素,更新当前的result
        while(result不满足要求) {
            窗口缩小,移除left对应元素,left右移
        }
        更新最优结果bestResult
        right++;
    }

    return bestResult;
}

/* 
 * 寻找最长子串的模板
 * @param left 左指针(窗口左侧)
 * @param right 右指针
 * @param result 当前结果
 * 
 * @return bestResult 最优结果
 **/
findMinLenFunc() {
    初始化left、right、result、bestResult
    while (右指针没有到结尾) {
        窗口扩大,加入right对应的元素,更新当前的result
        while(result满足要求) {
            更新最优结果bestResult
            窗口缩小,移除left对应元素,left右移
        }
        right++;
    }

    return bestResult;
}