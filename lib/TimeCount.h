//
// Created by zr on 9/11/23.
//

#ifndef SORT_TIMECOUNT_H
#define SORT_TIMECOUNT_H
#include <chrono>

class TimeCount {
private:
    std::chrono::high_resolution_clock::time_point current;
public:
    TimeCount();
    void end();
};


#endif //SORT_TIMECOUNT_H
