#include "init.h"

#define MAX_EVENT 2048
#define NAME_LEN 32
#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN MAX_EVENT*(EVENT_SIZE+NAME_LEN)

class Mapper{
    public:
        std::unordered_map<const char *, int> getMap() {
            return this->mapped;
        }

        void appendMap(const char *path, int wd) {
            this->mapped[path] = wd;
        }

        Mapper(){};
        Mapper(const char *root){
            this->MapTree(root);
        };

        void MapTree(const char *root);
        bool check(dirent *e);

    private:
        std::unordered_map<const char *, int> mapped;
};