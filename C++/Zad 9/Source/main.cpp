// [Kurs C++] Zadanie 9
//
// Manipulatory, klasa opakowująca tablicę
// oraz krótki program testowy.
//
// Autor: Tomasz Musiała

#include "manipulators.hpp"
#include <fstream>
#include "table.hpp"


int main()
{
    std::ifstream inFile ("testin.txt", std::ifstream::in);
    std::ofstream outFile ("testout.txt", std::ofstream::out);

    int a[5] = {1,2,3,4,5};
    std::string s[5] = {"asd","cde","erty","dewq", "ewqeqw"};
    char str[5] = "abcd";

//testy manipulatora Array<>
    std::cout << Array<int>(a, 5) << "\n";
    std::cout << Array<std::string>(s, 5) << "\n";
    std::cout << Array<char>(str, 5) << "\n";
    std::cout << Array<char>(str, -1) << "\n";

//testy strumieni zapisujących i odczytujących z/do pliku

    Table<int> f1(3);
    Table<int> f2(4);

    Table<char> fc1(3);
    Table<char> fc2(4);

    inFile >> f1;
    inFile >> f2;

    inFile >> fc1;
    inFile >> fc2;

    outFile << f1 << f2 << fc1 << fc2;

    inFile.close();
    outFile.close();

    return 0;
}
