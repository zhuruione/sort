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
    cout << "len=" << v.size() << endl;
}

//插入排序---------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------


//选择排序---------------------------------------------------------------------------------------------------------------
template<typename T>
void SortVector<T>::SelectSort() {
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
//----------------------------------------------------------------------------------------------------------------------



//选择排序改进版-----------------------------------------------------------------------------------------------------------
/*使用两个指针分别从两边遍历，每次遍历都将最大或最小的值放在最右边又或者最左边*/
template<typename T>
void SortVector<T>::SelectSortAdvance() {
    for (int l = 0, r = v.size() - 1; l < r; ++l, --r) {
        for (int l1 = l, r1 = r; l1 < r; ++l1, --r1) {
            if (v[l1] < v[l]) {
                T tem = v[l1];
                v[l1] = v[l];
                v[l] = tem;
            }
            if (v[r1] > v[r]) {
                T tem = v[r1];
                v[r1] = v[r];
                v[r] = tem;
            }
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------



//希尔排序  增量gap=length/2，缩小增量继续以gap = gap/2的方式-----------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------


//冒泡排序---------------------------------------------------------------------------------------------------------------
template<typename T>
void SortVector<T>::BubbleSort() {
    for (int i = 0; i < this->v.size(); ++i) {
        bool issorted = true;
        for (int j = 1; j < v.size() - i; ++j) {
            if (v[j - 1] > v[j]) {
                T tem = v[j];
                v[j] = v[j - 1];
                v[j - 1] = tem;
                issorted = false;
            }
        }
        if (issorted)  //如果这一次遍历中右边的数总是大于左边的数，说明数组已经排序好了
            break;
    }
}
//----------------------------------------------------------------------------------------------------------------------

/*----------------------------------------------------------------------------------------------------------------------
1、选出一个key，一般是最左边或是最右边的。
2、定义一个begin和一个end，begin从左向右走，end从右向左走。（需要注意的是：若选择最左边的数据作为key，则需要end先走；若选择最右边的数据作为key，则需要bengin先走）。
3、在走的过程中，若end遇到小于key的数，则停下，begin开始走，直到begin遇到一个大于key的数时，将begin和right的内容交换，end再次开始走，如此进行下去，直到begin和end最终相遇，此时将相遇点的内容与key交换即可。（选取最左边的值作为key）
4.此时key的左边都是小于key的数，key的右边都是大于key的数
5.将key的左序列和右序列再次进行这种单趟排序，如此反复操作下去，直到左右序列只有一个数据，或是左右序列不存在时，便停止操作，此时此部分已有序
*/
//快速排序  hoare版本(左右指针法)    最强排序算法
//将数组分为左右两边的递归方法
template<typename T>
void QuickSortHoareRecursionFun(vector<T> &v, int left, int right) {
    if (left >= right)
        return;
    int l = left, r = right;
    T key = v[left];
    while (1) {
        while (v[right] > key && right > left)  //右边全是大于key的
            right--;
        while (v[left] <= key && left < right)  //左边的全是小于等于key的
            left++;
        if (left == right)
            break;
        T tem = v[right];
        v[right] = v[left];
        v[left] = tem;
        right--;
    }
    T tem = v[right];
    v[right] = key;
    v[l] = tem;
    QuickSortHoareRecursionFun(v, l, right - 1);
    QuickSortHoareRecursionFun(v, right + 1, r);
}

template<typename T>
void SortVector<T>::QuickSortHoare() {
    QuickSortHoareRecursionFun(v, 0, v.size() - 1);
}
//其他方法和这个方法都大差不差，直接省略---------------------------------------------------------------------------------------



//堆排序-----------------------------------------------------------------------------------------------------------------
//迭代的维护大根堆  时间复杂度为log(n)
template<typename T>
void setHeap(vector<T> &v, int start, int end) {
    for (int i = (start * 2) + 1; i < end; i = (i * 2) + 1) {
        if (i + 1 < v.size() && v[i] < v[i + 1])        //保证节点i肯定是儿子节点中最大的那个
            i++;
        if (v[i] >= v[start]) {       //若孩子节点大于父节点，则交换
            swap(v[i], v[start]);
            start = i;              //将父节点设置为刚刚交换的节点
        } else {
            break;                  //若不需要改动，则直接结束
        }
    }
}

template<typename T>
void SortVector<T>::HeapSort() {
    //先将数组转为大根堆 时间复杂度为n/2*log(n)
    for (int i = (v.size() - 2) / 2; i >= 0; i--) {
        setHeap(v, i, v.size());
    }
    swap(v[0], v[v.size() - 1]);//因为已经是大根堆了,直接交换头尾元素
    //依次将树根和最后的节点互换,然后再次维护一下大根堆,时间复杂度为n*log(n)
    for (int i = v.size() - 2; i >= 0; --i) {
        setHeap(v, 0, i);//继续维护大根堆
        swap(v[0], v[i]);
    }
}
//----------------------------------------------------------------------------------------------------------------------


//归并排序---------------------------------------------------------------------------------------------------------------
//将两个排序好的数组合并
template<typename T>
void MergeSortMerge(vector<T> &v, int left, int right) {
    int mid = (right + left) >> 1;//数组v的前半个部分的右边界
    vector<T> v_tem(v.begin() + mid + 1, v.begin()+right+1); //获取数组的后半部分
    int i = right;  //整合数组的指针
    int v_tem_p = v_tem.size() - 1;
    for (; mid >= left && v_tem_p >= 0 > 0; --i) {  //只需保证前半部分不要遍历到左边界,并且后半部分不能遍历超过中间边界
        v[i] = v[mid] >= v_tem[v_tem_p] ? v[mid--] : v_tem[v_tem_p--];
    }
    for (; v_tem_p >= 0; --v_tem_p,--i) {  //若右半部分的数组还没遍历完,说明左边已经全部擦痕如到了v中,只需将右半部分剩下的添加到v中即可
        v[i]=v_tem[v_tem_p];
    }
}
//归并排序的递归方法,将数组分为左右两个部分,将两边都排序好后再进行合并
template<typename T>
void MergeSortRecursionFun(vector<T> &v, int left, int right) {
    //如果数组数量小于2,递归结束
    if (left >= right)
        return;
    int mid = (left + right) >> 1;
    MergeSortRecursionFun(v, left, mid);        //排序左边的数组
    MergeSortRecursionFun(v, mid+1, right);   //排序右边的数组
    MergeSortMerge(v, left, right);             //合并两边数组
}

template<typename T>
void SortVector<T>::MergeSort() {
    MergeSortRecursionFun(v,0,v.size()-1);
}
//----------------------------------------------------------------------------------------------------------------------
