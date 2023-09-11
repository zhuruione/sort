//
// Created by zr on 9/11/23.
//

#ifndef SORT_SORTVECTOR_H
#define SORT_SORTVECTOR_H

#include <vector>


template<typename T>
class SortVector : std::vector<T> {
private:
    std::vector<T> v;
public:
    SortVector()=default;
    SortVector(std::vector<T> v); //构造函数
    void print();       //打印
    void insertSort();  //插入排序
    void BubbleSort();  //冒泡排序
    void ShellSort();   //希尔排序
};




#endif //SORT_SORTVECTOR_H
