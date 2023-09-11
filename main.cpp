#include <iostream>
#include <SortVector.h>
#include <random>
#include "TimeCount.h"

#define RANDNUMLEN 50000
using namespace std;

// 创建一个伪随机数生成器
vector<int> randint() {

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, RANDNUMLEN); // 修改范围以适应您的需求
    std::vector<int> randomNumbers(RANDNUMLEN);
    // 填充向量数组
    for (int i = 0; i < RANDNUMLEN; ++i) {
        randomNumbers[i] = distribution(generator);
    }
    return randomNumbers;
}

int main() {

    TimeCount t;
    SortVector<int> sortVector({randint()});
//    sortVector.insertSort();
    sortVector.BubbleSort();
//    sortVector.ShellSort();
    sortVector.print();
    t.end();
    return 0;
}
