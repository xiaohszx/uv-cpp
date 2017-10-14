/*
   Copyright 2017, object_he@yeah.net  All rights reserved.

   Author: object_he@yeah.net 
    
   Last modified: 2017-10-10
    
   Description: 
*/

#ifndef   EVENT_LOOP_H
#define   EVENT_LOOP_H

#include <uv.h>
#include <thread>

namespace uv
{

class EventLoop
{
public:
    enum Mode
    { 
        DefaultLoop,
        NewLoop 
    };

    EventLoop(Mode mode = Mode::DefaultLoop);
    ~EventLoop();

    int run();
    bool isRunInLoopThread();
    uv_loop_t* hanlde();

private:
    std::shared_ptr<std::thread::id> loopThreadId;
    uv_loop_t* loop;
};
}
#endif // !  LOOP_H
