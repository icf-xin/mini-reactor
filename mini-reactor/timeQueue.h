// Copyright 2021 icf
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*
    需要实现的功能
    1）管理所有的time
    2）存在一个channel绑定时间描述符
    3）需要有所属的时间循环线程
    4）当可读事件发生时，epool返回调用channel对应的回调函数

*/

#ifndef TIMEQUEUE_H
#define TIMEQUEUE_H

#include "timestamp.h"
#include "timer.h"
#include "eventLoop.h"
#include "channel.h"
#include "timerId.h"


#include <set>
#include <vector>

class TimerQueue{
public:
    //
    TimerQueue(EventLoop* loop);
    ~TimerQueue();

    TimerId addTimer(const TimerCallback& cb,Timestamp when,double interval);

private:
    typedef  std::pair<Timestamp,Timer*> Entry;
    typedef  std::set<Entry> TimerLists;

    void handleRead();

    std::vector<Entry> getExpired(Timestamp now);
    void reset(const std::vector<Entry>& expired,Timestamp now);

    bool insert(Timer *timer);

    EventLoop *loop_;
    const int timefilefd_;
    Channel channelOfTimerfd_;

    //所有的timer
    TimerLists timers_;
};


#endif