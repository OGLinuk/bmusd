#include "daemon.h"

void start() {
    init();

    while(1) {
        syslog(LOG_INFO, "bmusd is working!");
        sleep(42);
        exit(0);
    }
}