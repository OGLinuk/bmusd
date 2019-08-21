#include <iostream>
#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void init();
void initLog();
void initFork();
void initClosure();