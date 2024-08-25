#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;
//https://www.sendspace.com/file/fqi3ww
void convert(signed type)
{
    fstream plik_from;
    plik_from.open("savedpositions.txt", ios::in);
    bool err = false;
    if(!plik_from.good()) err = true;
    string linia;
    size_t przecinek;
    signed znak, ile = 0, typ_set = 4;
    switch(type)
    {
        case 0: typ_set = 4; break;
        case 1: typ_set = 3; break;
        case 2: typ_set = 2; break;
        default: typ_set = 4; break;
    }
    fstream plik_target;
    plik_target.open("converted.txt", ios::out);
    while(getline(plik_from, linia))
    {
        przecinek = linia.find(",");
        linia.erase(0, przecinek+1);
        znak = 0;
        przecinek = 0;
        while(linia.length() > znak)
        {
            if(linia[znak] == ',')
            {
                przecinek++;
                if(przecinek == typ_set)
                {
                    linia.erase(znak, linia.length());
                }
            }
            znak++;
        }
        ile++;
        cout << "{" << linia << "}, //" << ile-1 << endl;
        plik_target << "{" << linia << "}, //" << ile-1 << endl;

    }
    plik_from.close();
    plik_target.close();
    system("cls");
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    if(!err)
    {
    cout << "=> Przekonwertowano " << ile << " koordynatow. <=" << endl;
    cout << "=> Sa one w pliku 'converted.txt'! <=" << endl;
    }
    else
    {
    cout << "=> Nie mam dostepu do pliku 'savedpositions.txt'. <=" << endl;
    cout << "=> Musi byc w tym samym katalogu co converter. <=" << endl;
    cout << "=> Nie moze byc uzywany przez inny program. <=" << endl;
    }
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
}

int main()
{
    system("title Converter 'savedpositions.txt' do tablic by sebaqq6 :)");
    while(true)
    {
        cout << endl << "Converter z 'savedpositions.txt' do raw by sebaqq6" << endl;
        cout << "--------MENU---------" << endl;
        cout << "1. savedpositions.txt => {x, y, z, r}" << endl;
        cout << "2. savedpositions.txt => {x, y, z}" << endl;
        cout << "3. savedpositions.txt => {x, y}" << endl;
        cout << "4. Wyjdz z convertera." << endl;
        cout << "Wybierz opcje(1-4): ";
        char wybor;
        wybor = getch();
        system("cls");
        switch(wybor)
        {
            case '1':
            {
                convert(0);
                break;
            }
            case '2':
            {
                convert(1);
                break;
            }
            case '3':
            {
                convert(2);
                break;
            }
            case '4':
            {
                exit(0);
                break;
            }
            default: cout << endl << "=> Nie ma takiej opcji, wybierz ponownie(od 1 do 4). <=";
        }
    }
    return 0;
}
