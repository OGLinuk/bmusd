#pragma once

#include <cstring>
#include <dirent.h>
#include <iostream>
#include <string>
#include <syslog.h>
#include <sys/inotify.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <unordered_map>

void init();
void initLog();
void initFork();
void initClosure();