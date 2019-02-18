//
// Created by Afterburner on 2019-02-18.
//
#include <vector>
#include <iostream>
#include <numeric>

class QuickUnion{
    std::vector<size_t> indecies;

public:
    explicit QuickUnion(size_t numComponents) : indecies(std::vector<size_t>(numComponents)){
        std::iota(indecies.begin(), indecies.end(), 0);
    }

    size_t getRoot(size_t index) {
        while (index != indecies[index]) {
            index = indecies[index];
        }

        return index;
    }

    size_t getParent(size_t index){
        return indecies[index];
    }

    bool connect(size_t index_a, size_t index_b){
        bool unionSuccess = false;
        if (index_a != index_b) {
            const size_t root_a = this->getRoot(index_a);
            const size_t root_b = this->getRoot(index_b);
            if (root_a != root_b) {
                indecies[root_a] = root_b;
                unionSuccess = true;

                // connection compression
                while (root_b != indecies[index_a]) {
                    const auto index_a_copy = index_a;
                    index_a = indecies[index_a];
                    indecies[index_a_copy] = root_b;
                }
            }
        }
        return unionSuccess;
    }

    bool is_connected(size_t index_a, size_t index_b) {
        return this->getRoot(index_a) == this->getRoot(index_b);
    }

    void print() const{
        for (size_t index = 0; index < indecies.size(); index++) {
            std::cout<< index <<' ';
        }
        std::cout << '\n';
        for(const auto& ele : indecies) {
            std::cout<< ele <<' ';
        }
        std::cout << '\n';
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
    assert(quickUnion.getParent(5) == 2);
    quickUnion.connect(5, 6);

    quickUnion.print();
}

//      2                         0
//   1      3                  4     6
//          5
// then connect(5, 6)