#include <cassert>
#include <iostream>
#include <stdexcept>
#include "../containers/vector/vector.cpp"

int main() {
    Vector<int> vec;
    assert(vec.empty());
    assert(vec.get_size() == 0);
    assert(vec.get_capacity() == 0);

    vec.push_back(10);
    assert(!vec.empty());
    assert(vec.get_size() == 1);
    assert(vec.get_capacity() >= 1);
    assert(vec[0] == 10);

    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    assert(vec.get_size() == 4);
    assert(vec[0] == 10 && vec[1] == 20 && vec[2] == 30 && vec[3] == 40);

    vec.insert(0, 5);
    assert(vec.get_size() == 5);
    assert(vec[0] == 5 && vec[1] == 10);

    vec.insert(2, 15);
    assert(vec.get_size() == 6);
    assert(vec[0] == 5);
    assert(vec[1] == 10);
    assert(vec[2] == 15);
    assert(vec[3] == 20);
    assert(vec[4] == 30);
    assert(vec[5] == 40);

    vec.insert(vec.get_size(), 50);
    assert(vec[vec.get_size() - 1] == 50);

    const Vector<int>& const_vec = vec;
    assert(const_vec[0] == 5);
    assert(const_vec[const_vec.get_size() - 1] == 50);

    vec.pop_back();
    assert(vec.get_size() == 6);
    assert(vec[vec.get_size() - 1] == 40);

    while (!vec.empty()) {
        vec.pop_back();
    }

    assert(vec.get_size() == 0);
    assert(vec.empty());

    bool threw = false;
    try {
        vec.pop_back();
    } catch (const std::out_of_range&) {
        threw = true;
    }
    assert(threw);

    threw = false;
    try {
        vec.insert(1, 1);
    } catch (const std::out_of_range&) {
        threw = true;
    }
    assert(threw);

    threw = false;
    try {
        int value = vec[0];
        (void)value;
    } catch (const std::out_of_range&) {
        threw = true;
    }
    assert(threw);

    vec.push_back(100);
    vec.clear();
    assert(vec.get_size() == 0);
    assert(vec.empty());
    assert(vec.get_capacity() == 0);

    std::cout << "All Vector tests passed.\n";
    return 0;
}
