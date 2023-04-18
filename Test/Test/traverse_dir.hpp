//
//  traverse_dir.hpp
//  Test
//
//  Created by MarkWu on 2023/3/31.
//

#ifndef traverse_dir_hpp
#define traverse_dir_hpp

#include <iostream>
#include <dirent.h>
#include <stdlib.h>
#include <functional>
#include <unordered_set>
#include <vector>

using namespace std;

void TraverseDir(const string& path) {
    struct dirent *dirp;

    DIR* dir = opendir(path.c_str());
    
    printf("\n<<<<<< dir: %s\n", path.c_str());

    while ((dirp = readdir(dir)) != nullptr) {
        if (dirp->d_type == DT_REG) {
            // 文件
            printf("%s\n", dirp->d_name);
        } else if (dirp->d_type == DT_DIR) {
            
            if (!strcmp(dirp->d_name, ".") or !strcmp(dirp->d_name, ".."))
                continue;
            
            string subdir_path = path + "/" + dirp->d_name;
            printf("%s\n", subdir_path.c_str());
            TraverseDir(subdir_path);
        }
    }

    closedir(dir);
}

//int main(int argc, const char * argv[]) {
////    TraverseDir("/Users/mark/Codes/Temp/CppPractice/AlgorithmPractice/poems");
////    cout << realpath("/Users/mark/Codes/Temp/CppPractice/AlgorithmPractice/poems", NULL) << endl;
//    
//    std::vector<int> nums = {3, 0, 1};
//    
//    std::unordered_set<int> st;
//    for (auto it : nums)
//        st.emplace(it);
//    
//    for (int i = 0, size = (int)nums.size(); i <= size; i++) {
//        if (st.count(i) == 0)
//            cout << "got: " << i << endl;
//    }
//    
//    return 0;
//}



#endif /* traverse_dir_h */
