#include <dirent.h>
#include <vector>
#include <iostream>
#include <cstddef>

int list_dir(const char *path, std::vector<std::string> &dirs) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            dirs.push_back(ent->d_name);
        }
        closedir(dir);
    } else {
        /* could not open directory */
        return -1;
    }
    return 0;
}

int main(){
    std::vector<std::string> dirs;
    list_dir(".", dirs);
    for (int i = 0; i < dirs.size(); i++) {
        std::cout << dirs[i] << std::endl;
    }
    return 0;
}
