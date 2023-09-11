//
// Created by zr on 9/11/23.
//
#include "stdio.h"
#include "SortVector.h"
#include <iostream>

using namespace std;

template
class SortVector<int>;

template
class SortVector<float>;

//构造函数
template<typename T>
SortVector<T>::SortVector(std::vector<T> v):std::vector<T>(v) {
    this->v = v;
}

//打印内容
template<typename T>
void SortVector<T>::print() {
    for (const auto &item: this->v)
        cout << item << " ";
    cout << endl;
}

//插入排序
template<typename T>
void SortVector<T>::insertSort() {
    for (int i = 1; i < this->v.size(); ++i) {
        T tem = this->v[i];
        for (int j = i - 1; j >= 0 && this->v[j] > tem; --j) {
            this->v[j + 1] = this->v[j];
            this->v[j] = tem;
        }
    }
}

//冒泡排序
template<typename T>
void SortVector<T>::BubbleSort() {
    for (int i = 0; i < this->v.size(); ++i) {
        for (int j = i + 1; j < this->v.size(); ++j) {
            if (this->v[j] < this->v[i]) {
                T tem = this->v[i];
                this->v[i] = this->v[j];
                this->v[j] = tem;
            }
        }

    }
}

//希尔排序  增量gap=length/2，缩小增量继续以gap = gap/2的方式
template<typename T>
static void shellinsertSort(vector<T> &v, int gap) {
    for (int i = gap; i < v.size(); i += gap) {
        T tem = v[i];
        for (int j = i - gap; j >= 0 && tem > v[j]; j -= gap) {
            v[j + gap] = v[j];
            v[j] = tem;
        }
    }
}

template<typename T>
void SortVector<T>::ShellSort() {
    for (int gap = this->v.size() / 2; gap > 0; gap /= 2) {
        shellinsertSort(this->v, gap);
    }
}