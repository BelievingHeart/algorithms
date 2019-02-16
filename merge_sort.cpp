#include <fmt/printf.h>
#include <vector>
#include <numeric>
#include <iostream>

int main()
{
    auto mergeSort_step = [](size_t arr[], size_t sz, std::vector<size_t>& aux){
        aux.clear();
        std::string temp;
        for(size_t i=0, j= sz / 2; aux.size() != sz;){
            if(j == sz){
                aux.push_back(arr[i]);
                i++;
            }else if(i == sz/2){
                aux.push_back(arr[j]);
                j++;
            }else if(arr[j]<arr[i]) {
                aux.push_back(arr[j]);
                j++;
            }else {
                aux.push_back(arr[i]);
                i++;
            }
        }
        for (size_t i = 0; i < sz; i++) {
            arr[i] = aux[i];
        }
    };

    auto bottomUP_mergeSort = [&](std::vector<size_t>& arr){
        std::vector<size_t> aux; aux.reserve(arr.size());
        for(size_t n=1; n+n<=arr.size(); n += n){
            for(size_t segmentStart=0; segmentStart<arr.size(); segmentStart+=2*n){
                mergeSort_step(&(arr[segmentStart]), n + n, aux);
            }
        }
        for (const auto &ele : arr) {
            std::cout<<ele<<' ';
        }
    };

    std::vector<size_t> arr{1,8,3,2,5,4,725,0};
    bottomUP_mergeSort(arr);

}