//
// Created by Afterburner on 2019-02-18.
//
#include <vector>
#include <iostream>
#include <numeric>

class QuickUnion{
    std::vector<size_t> indecies, weights;

public:
    explicit QuickUnion(size_t numComponents) : indecies(std::vector<size_t>(numComponents)){
        std::iota(indecies.begin(), indecies.end(), 0);
        std::copy(indecies.begin(), indecies.end(), std::back_inserter(weights));
    }

    size_t getRoot(size_t index) const{
        while (index != indecies[index]) {
            index = indecies[index];
        }
        return index;
    }

    bool connect(size_t index_a, size_t index_b){
        bool unionSuccess = false;
        if (index_a != index_b) {
            const size_t root_a = this->getRoot(index_a);
            const size_t root_b = this->getRoot(index_b);
            if (root_a != root_b) {
                indecies[root_a] = root_b;
                unionSuccess = true;
            }
        }
        return unionSuccess;
    }

    bool is_connected(size_t index_a, size_t index_b) const{
        return this->getRoot(index_a) == this->getRoot(index_b);
    }

};

int main(){
    QuickUnion quickUnion(7);
    assert(   quickUnion.connect(4, 0)&&
              quickUnion.connect(6, 4)&&
              quickUnion.connect(1, 2)&&
              quickUnion.connect(3, 2)&&
              quickUnion.connect(5, 3));

    assert(!quickUnion.connect(5, 1));

    assert(quickUnion.getRoot(5) == 2 and quickUnion.getRoot(1) == 2 and quickUnion.getRoot(3) == 2);
    assert(quickUnion.getRoot(4) == 0 and quickUnion.getRoot(6) == 0 and quickUnion.getRoot(0) == 0);
}