#include <iostream>
#include <SortVector.h>
#include <random>
#include <algorithm>
#include "TimeCount.h"

#define RANDNUMLEN 50000
using namespace std;

// 创建一个伪随机数生成器
vector<int> randint(int len) {

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, len); // 修改范围以适应您的需求
    std::vector<int> randomNumbers(len);
    // 填充向量数组
    for (int i = 0; i < len; ++i) {
        randomNumbers[i] = distribution(generator);
    }
    return randomNumbers;
}

int main() {

    TimeCount t;
    SortVector<int> sortVector({10,9,8,7,6,5,4,3,6,2,1,0});
//    SortVector<int> sortVector(randint(1e6));
//    SortVector<int> sortVector(randint(10));

//    sortVector.insertSort();  //插入排序
//    sortVector.BubbleSort();    //冒泡排序
//    sortVector.ShellSort();   //希尔排序
//    sortVector.SelectSort();  //选择排序
//    sortVector.SelectSortAdvance();   //选择排序改进版
//    sortVector.QuickSortHoare();      //快速排序Hoare
//    sortVector.HeapSort();      //堆排序
    sortVector.MergeSort();
    sortVector.print();
    t.end();
}
