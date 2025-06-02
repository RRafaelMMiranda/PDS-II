#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main (void)
{
    string texto;
    bool palindromo = true;

    getline(cin, texto);

    int tamanho = texto.size();
    int naoalpha = 0;
    for(int i = 0; i <= tamanho/2; i++)
    {
        if (texto[i] != texto[tamanho - i - 1])
        {
            palindromo = false;
            cout << i << endl;

            cout << texto[i] << endl;
        }
    }

    if (palindromo == true)
    {
        cout << "SIM";
    }
    else
    {
        cout << "NAO";
    }

}
