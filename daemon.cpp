#include "daemon.h"

void start(const char *root) {
    init();

    while(1) {
        syslog(LOG_INFO, "Starting bmusd ...");
        Mapper m;
        m.MapTree(root);
        bmus();
        sleep(1800);
    }
}

// TODO: use the path passed to start as target for bmus
void bmus() {
    pid_t pid;

    if(pid = fork() == 0) {
        syslog(LOG_INFO, "Scotty is backing me up ...");

        char *argv[] = {
            "bmus",
            "-t",
            "/home/oglinuk/deve/bmusd",
            NULL
        };
        execvp(argv[0], argv);

        syslog(LOG_INFO, "Scotty successfully backed me up ...");
        exit(0);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}