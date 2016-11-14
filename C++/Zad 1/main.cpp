// Lista 1
// Program licz¹cy znaki, bia³e znaki i iloœæ linii.
// Autor: Tomasz Musia³a
//
//


#include <iostream>
#include <string>

using namespace std;

int main()
{
    int characters = 0;// iloœæ wszystkich znaków
    int whites = 0;    // iloœæ znaków bia³ych - uwaga !Program nie liczy znaku EOF!
    int lines = 0;     // iloœæ linii
    string line;

    while(getline(cin, line) && lines < 2)
    {
       for(int i = 0; i < line.size(); i++)
       {
            if(isspace(line[i])) whites++;
            characters++;
       }
       whites++;    // getline nie do³¹cza
       characters++;// znaku nowej linii
       lines++;
    }

    cout << "Lines = " << lines <<"\nCharacters = "<< characters << "\nWhites = " << whites <<"\n";

    return 0;
}
