#include <numeric>
#include <iostream>
#include <vector>

template <typename Iter>
void merge_step(Iter iter_first, Iter iter_mid, Iter iter_last){
    const long size = std::distance(iter_first, iter_last) + 1;
    const auto iter_mid_copy = iter_mid;
    auto iter_first_copy = iter_first;
//    assert(std::is_sorted(iter_first, iter_mid));
//    assert(std::is_sorted(iter_mid, iter_last));
    std::vector<typename Iter::value_type> aux;
    while (aux.size() != size) {
        if (iter_first == iter_mid_copy) {
            aux.push_back(*iter_mid);
            iter_mid++;
        }else if(iter_mid == iter_last){
            aux.push_back(*iter_first);
            iter_first++;
        }else if(*iter_first < *iter_mid) {
            aux.push_back(*iter_first);
            iter_first++;
        }else{
            aux.push_back(*iter_mid);
            iter_mid++;
        }
    }
    std::move(aux.begin(), aux.end(), iter_first_copy);
}

template<typename Iter_t>
void merge_sort(Iter_t first, Iter_t last){
    auto mid = first + (std::distance(first, last) >> 1);
    if(last - first == 1){
        return;
    }else{
        merge_sort(first, mid);
        merge_sort(mid, last);
//        std::inplace_merge(first, mid, last);
        merge_step(first, mid, last);
    }
}

int main(){
    std::vector<int> arr{8, 9, 7, 3, 5, 4, 0};
    merge_sort(arr.begin(), arr.end());
    for (const auto &ele: arr) {
        std::cout << ele << ' ';
    }
}