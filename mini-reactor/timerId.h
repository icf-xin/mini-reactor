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

#ifndef TIMEID_H
#define TIMEID_H

#include "timer.h"

//使timeQueue中addTimer函数返回的Timer对用户来说是不可见的，内部实现Timer
class TimerId 
{
 public:
  explicit TimerId(Timer* timer)
    : value_(timer)
  {
      
  }
 private:
  Timer* value_;
};

#endif