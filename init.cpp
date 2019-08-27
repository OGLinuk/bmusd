#include "init.h"

void init() {
    initLog();
    initFork();
    initClosure();
}

void initLog() {
    openlog("bmusd", LOG_PID | LOG_NDELAY, 0);
    syslog(LOG_INFO, "Successfully initialized log ...");
}

void initFork() {
    pid_t pid, sid;

    pid = fork();

    if(pid < 0) {
        syslog(LOG_ERR, "Failed to fork the parent process ...");
        exit(1);
    }

    if(pid > 0) {
        syslog(LOG_INFO, "Successfully created process %d ...", pid);
        exit(0);
    }

    umask(0);

    sid = setsid();
    if(sid < 0) {
        syslog(LOG_ERR, "Failed to create session ID ...");
        exit(1);
    }
}

void initClosure() {      
    if(chdir("/") < 0) {
        syslog(LOG_ERR, "Failed to change to root dir ...");
        exit(1);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}