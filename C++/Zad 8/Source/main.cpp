// Pawel Meller (241711)
// C++ course 2015, lab08

#include <iostream>
#include <algorithm>

#include "computations.hpp"

template< typename T >
void print_array(T* arr, unsigned int size) {
    std::copy(arr, arr + size, std::ostream_iterator<T>(std::cout, ", "));
}

template<>
void print_array(double* arr[], unsigned int size) {
    std::transform(arr, arr + size, std::ostream_iterator<double>(std::cout, ", "), [](double* e) { return *e; });
}

template< typename T >
void test(T* arr, unsigned int size) {
    computations::shuffle(arr, arr + size);
    std::cout << "SHUFFLED: ";
    print_array(arr, size);
    std::cout << "\n";

    computations::bubblesort(arr, arr + size);
    std::cout << "SORTED <: ";
    print_array(arr, size);
    std::cout << "\n";

    computations::shuffle(arr, arr + size);
    computations::bubblesort< T*, computations::descending<T> >(arr, arr + size);
    std::cout << "SORTED >: ";
    print_array(arr, size);
    std::cout << "\n\n";
}

int main() {
    int a1[] = {8, 7, 10, 4, 9, 6, 2, 1, 5, 3};
    double* a2[] = {new double(0.1), new double(0.5), new double(0.3), new double(0.4), new double(0.2)};
    char* a3[] = {"W", "czasie", "suszy", "sucha", "szosa", "Sasza", "szedl"};
    std::string a4[] = {"Lojalna", "Jola", "lubi", "lojalnego", "jelenia"};

    test(a1, 10);
    test(a2, 5);
    test(a3, 7);
    test(a4, 5);

    return 0;
}
