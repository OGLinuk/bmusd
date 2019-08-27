#include "daemon.h"

main(int argc, char const *argv[]) {
    if(argc < 2) {
        exit(1);
    }
    start(argv[1]);
}