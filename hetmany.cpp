//ZADANIE SZKOPUŁ - PROBLEM 8 HETMANÓW V1
//Źródło: https://szkopul.edu.pl/problemset/problem/Tyx1ndO71ei9bbnFgQBNMB6S/site/?key=statement
//Autor: G. Nowak-Włodyga
//6.10.2025
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int d, kolumna;
    int hetmany[8];
    bool szachowanie = false;
    cin >> d;
    for (int i = 0; i < d; i++)
    {
        bool kolumny[8] = { false,false,false,false,false,false,false,false };
        szachowanie = false;
        //wczytywanie 8 liczb (kolumny w ktorych sa kolejne hetmany)
        for (int j = 0; j < 8; j++)
        {
            cin >> kolumna;
            //sprawdzenie szachowania po kolumnach (czy co najmniej dwa hetmany stoj¹ w jednej dowolnej kolumnie)
            if(kolumny[kolumna-1] == false)
                kolumny[kolumna-1] = true;
            else
            {
                cout << "NIE" << endl;
                szachowanie = true;
                break;
            }
            hetmany[j] = kolumna - 1;
        }
        //sprawdzanie szachowania po przekatnych (tylko jesli nie szachuja sie po kolumnach)
        if (szachowanie == false)
        {
            //cout << "test";
            //sprawdzamy przekatne
            for (int j = 0; j < 7; j++)
            {
                if (szachowanie == true)
                    break;
                for (int k = j + 1; k < 8; k++)
                {
                    if (szachowanie == true)
                        break;
      //sprawdzam hetmany stojace na pozycjach (w komentarzu na koncu kodu jest wersja nieoptymalna
                    //(j,hetmany[j]) , (k,hetmany[k])
                    if (abs(j - k) == abs(hetmany[j] - hetmany[k]))
                    {
                        szachowanie = true;
                        cout << "NIE" << endl;
                    }
                }
            }
            if (szachowanie == false)
                cout << "TAK" << endl;
        }

    }
}

/*
for (int x = 1; x < 7; x++)
                    {
                        if (j == k + x and hetmany[j] == hetmany[k] + x and k + x < 8 and hetmany[k] + x < 8)
                        {
                            cout << "NIE" << endl;
                            szachowanie = true;
                            break;
                        }
                        else if (j == k - x and hetmany[j] == hetmany[k] + x and k - x >= 0 and hetmany[k] + x < 8)
                        {
                            cout << "NIE" << endl;
                            szachowanie = true;
                            break;
                        }
                        else if (j == k - x and hetmany[j] == hetmany[k] - x and k - x >= 0 and hetmany[k] - x >= 0)
                        {
                            cout << "NIE" << endl;
                            szachowanie = true;
                            break;
                        }
                        else if (j == k + x and hetmany[j] == hetmany[k] - x and k + x < 8 and hetmany[k] - x >= 0)
                        {
                            cout << "NIE" << endl;
                            szachowanie = true;
                            break;
                        }
                    }
*/
