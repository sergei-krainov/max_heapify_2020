#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template<typename T>
void print_vector(std::vector<T> v)
{
    if (v.empty()) {
        return;
    }

    std::copy(v.cbegin(), --v.cend(), std::ostream_iterator<T>(std::cout, " "));
    std::cout << v.back() << "\n";
}

/* Just to have it for future
template<typename Container, typename CST = typename Container::size_type>
void max_heapify(Container& v, CST i)
{
    CST largest_i = i;
    CST left_i = left_node_index(i);
    CST right_i = right_node_index(i);
    CST size = v.size();

    if (left_i > size && right_i > size) {
        return;
    }

    if (left_i < size && v[left_i] > v[largest_i]) {
        largest_i = left_i;
    } 
    
    if (right_i < size && v[right_i] > v[largest_i]) {
        largest_i = right_i;
    }

    if (i != largest_i) {
        std::swap(v[i], v[largest_i]);
        max_heapify(v, largest_i);
    }
}

template<typename Container>
void build_max_heap_bad(Container& v, typename Container::size_type i)
{
    auto middle = v.size()/2 - 1;
    while(middle) {
        max_heapify(v, middle);
        middle--;
    }
    max_heapify(v, middle);
}

template<typename Container, typename CST = typename Container::size_type>
void build_max_heap_in_infinite_loop(Container& v, typename Container::size_type i)
{
    auto middle = v.size()/2 - 1;
    while(true) {
        max_heapify(v, middle);

        if (middle == 0)
            return;

        middle--;
    }
} */


template<typename T>
T left_node_index(T in)
{
    return in * 2 + 1;
}

template<typename T>
T right_node_index(T in)
{
    return in * 2 + 1 + 1;
}

template<typename Container>
void max_heapify(Container& v, typename Container::size_type i)
{
    auto largest_i = i;
    const auto size = v.size();

    const auto left_i = left_node_index(i);
    const auto right_i = right_node_index(i);

    if (left_i > size && right_i > size) {
        return;
    }

    if (left_i < size && v[left_i] > v[largest_i]) {
        largest_i = left_i;
    } 
    
    if (right_i < size && v[right_i] > v[largest_i]) {
        largest_i = right_i;
    }

    if (i != largest_i) {
        std::swap(v[i], v[largest_i]);
        max_heapify(v, largest_i);
    }
}

template<typename Container>
void build_max_heap(Container& v)
{
    auto middle = v.size()/2;
    do {
        middle--;
        max_heapify(v, middle);
    } while(middle);
}

int main()
{
    std::vector<int> v{5, 13, 2, 25, 7, 17, 20, 8, 4};
    print_vector(v);

    build_max_heap(v);
    print_vector(v);

    std::make_heap(v.begin(), v.end());
    print_vector(v);

    return 0;
}
