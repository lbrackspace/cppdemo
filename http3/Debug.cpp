#include "Debug.h"

#include<boost/thread.hpp>
#include<cstdlib>

const double MICROSECS_PER_SEC = 1 * 1000000.0;

Debug::Debug() {
}

Debug::Debug(const Debug& orig) {
}

Debug::~Debug() {
}

void Debug::thread_sleep(double secs) {
    int64_t ms = int64_t(secs * MICROSECS_PER_SEC);
    boost::this_thread::sleep(boost::posix_time::microseconds(ms));
}
