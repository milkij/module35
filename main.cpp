#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <algorithm>
#include <filesystem>

int main() {
    std::cout << "1-st task" << std::endl;
    std::array<int, 5> arr{1,2,3,7,6} ;
    std::sort(arr.begin(),arr.end());
    for(auto &i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout<<std::endl;
    std::cout << "2-nd task" << std::endl;
    std::vector<int> vec{1,2,1,3,4,1,2,7, 0, 0, -1,12};
    auto f = [] (const std::vector<int> &vec)
            {
                if(vec.empty())
                {
                    return std::unique_ptr<std::vector<int>>(nullptr);
                };
                std::unordered_set<int> mySet;
                std::vector<int> newVec;
                for(auto &i : vec)
                {
                    if (mySet.count(i))
                    {
                        continue;
                    }
                    else
                    {
                        mySet.insert(i);
                        newVec.push_back(i);
                    }
                }
                std::sort(newVec.begin(),newVec.end());
                return std::make_unique<std::vector<int>>(newVec);
            };
    auto data = f(vec);
    for (auto &it : *data)
    {
        std::cout << it << ' ';
    }
    std::cout<<std::endl;
    std::cout << "3-d task" << std::endl;


    auto recursiveGetFileNamesByExtension =
            [](std::filesystem::path path,
               const std::string extension)
            {
                for(auto& p: std::filesystem::recursive_directory_iterator(path))

                    if(std::filesystem::is_regular_file(p) && std::filesystem::path(p).extension()==extension ){
                        std::cout << p.path().filename() << " | ... | " << std::filesystem::path(p).extension() << std::endl;
                    }


            };
    recursiveGetFileNamesByExtension("/Users/alexander/CLionProjects/module35/task3",".sql");
    return 0;
}
