//
// Created by zr on 9/11/23.
//

#include "TimeCount.h"
#include <iostream>
TimeCount::TimeCount() {
    // 获取当前时间点
    this->current = std::chrono::high_resolution_clock::now();

}

void TimeCount::end() {
    // 获取当前时间点
    std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();

    // 计算程序段的运行时间
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - this->current);

    // 输出运行时间
    std::cout << "程序段运行时间: " << duration.count() << " 毫秒" << std::endl;

    this->current = std::chrono::high_resolution_clock::now();
}
