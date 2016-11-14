// Lista 1
// Program licz�cy znaki, bia�e znaki i ilo�� linii.
// Autor: Tomasz Musia�a
//
//


#include <iostream>
#include <string>

using namespace std;

int main()
{
    int characters = 0;// ilo�� wszystkich znak�w
    int whites = 0;    // ilo�� znak�w bia�ych - uwaga !Program nie liczy znaku EOF!
    int lines = 0;     // ilo�� linii
    string line;

    while(getline(cin, line) && lines < 2)
    {
       for(int i = 0; i < line.size(); i++)
       {
            if(isspace(line[i])) whites++;
            characters++;
       }
       whites++;    // getline nie do��cza
       characters++;// znaku nowej linii
       lines++;
    }

    cout << "Lines = " << lines <<"\nCharacters = "<< characters << "\nWhites = " << whites <<"\n";

    return 0;
}
