// Pawel Meller (241711)
// C++ course 2015, lab08

#include <random>
#include <iterator>
#include <algorithm>
#include <cstring>

namespace computations {

    template< typename T >
    struct ascending {
        bool operator()(const T& a, const T& b) { return a < b; }
    };

    template< typename T >
    struct ascending< T* > {
        bool operator()(const T* a, const T* b) { return (*a) < (*b); }
    };

    template<>
    struct ascending< char* > {
        bool operator()(const char* a, const char* b) {
            return std::lexicographical_compare(a, a+strlen(a), b, b+strlen(b));
        }
    };

    template<>
    struct ascending< void* > {
        bool operator()(const void* a, const void* b) { return a < b; }
    };

    template< typename T >
    struct descending {
        bool operator()(const T& a, const T& b) { return a > b; }
    };

    template< typename T >
    struct descending< T* > {
        bool operator()(const T* a, const T* b) { return (*a) > (*b); }
    };

    template<>
    struct descending< char* > {
        bool operator()(const char* a, const char* b) {
            return !std::lexicographical_compare(a, a+strlen(a), b, b+strlen(b));
        }
    };

    template<>
    struct descending< void* > {
        bool operator()(const void* a, const void* b) { return a > b; }
    };

    template< typename It >
    void shuffle(It begin, It end) {

        std::random_device random_device;
        std::default_random_engine generator(random_device());
        std::uniform_int_distribution<unsigned int> distribution;

        for (unsigned int i = end - begin - 1; i > 0; i--) {
            std::swap(begin[i], begin[distribution(generator, decltype(distribution)::param_type(0, i))]);
        }
    }

    template< typename It, class C = ascending< typename std::iterator_traits<It>::value_type > >
    void bubblesort(It begin, It end) {
        C compare;
        It i, j;

        for(i = begin; i != end; i++) {
            for(j = begin; j < i; j++) {
                if(compare(*i, *j)) {
                    std::iter_swap(i, j);
                }
            }
        }
    }
}
