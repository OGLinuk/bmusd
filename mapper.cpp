#include "mapper.h"

void Mapper::MapTree(const char * root) {
    DIR * d;

    d = opendir(root);

    if(!d) {
        syslog(LOG_ERR, "Cannot open directory '%s'\n", root);
        exit(1);
    }
    
    while(1) {
        struct dirent * entry;

        entry = readdir(d);
        if(!entry) {
            break;
        }

        if(entry->d_type & DT_DIR) {
            if(check(entry)) {
                int path_length;
                char path[PATH_MAX];

                path_length = snprintf(path, PATH_MAX,
                                        "%s/%s", root, entry->d_name);

                if(path_length >= PATH_MAX) {
                    syslog(LOG_ERR, "Path length has got too long.\n");
                    exit(1);
                }

                syslog(LOG_INFO, "%s\n", path);

                MapTree(path);
            }
        }
    }

    if(closedir(d)) {
        syslog(LOG_ERR, "Could not close '%s'\n", root);
        exit(1);
    }
}

bool Mapper::check(dirent *e) {
    if(strcmp(e->d_name, "..") != 0 &&
        strcmp(e->d_name, ".") != 0 &&
        e->d_type == DT_DIR) {
            return 1;
        }
    return 0;
}