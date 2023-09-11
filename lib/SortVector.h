//
// Created by zr on 9/11/23.
//

#ifndef SORT_SORTVECTOR_H
#define SORT_SORTVECTOR_H

#include <vector>


template<typename T>
class SortVector : public std::vector<T> {
private:
    std::vector<T> v;
public:
    SortVector() = default;

    SortVector(std::vector<T> v); //构造函数
    void print();       //打印
    void insertSort();  //插入排序
    void SelectSort();  //选择排序
    void SelectSortAdvance();//选择排序改进版
    void ShellSort();   //希尔排序
    void BubbleSort();  //冒泡排序
    void HeapSort();    //堆排序
    void QuickSortHoare();   //快速排序 hoare版本(左右指针法)

    std::vector<T> getList() { return v; }
};


#endif //SORT_SORTVECTOR_H
