#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main (void)
{
    string aux;
    ifstream arquivo("palavras.txt");

    getline(arquivo, aux);
    stringstream fluxo(aux);
    vector<string> palavrasproibidas;
    int N = 0;
    fluxo >> N;
    for (int i = 0; i < N; i++)
    {
        
        string aux;
        getline(arquivo, aux);
        palavrasproibidas.push_back(aux);
    }

    string frase;
    getline(cin, frase);
    map<string, int> m;
    vector<string> aquelascoisas;

    stringstream fluxo2(frase);
    while (fluxo2)
    {
        string auxdoaux;
        fluxo2 >> auxdoaux;
        aquelascoisas.push_back(auxdoaux);
    }

    for (int i = 0; i < aquelascoisas.size();i++)
    {
        for (int j = 0; j < palavrasproibidas.size(); i++)
        {
            if (aquelascoisas[i] == palavrasproibidas[j])
            {
                aquelascoisas[i].clear();
                for (int k = 0; k < aquelascoisas.size(); k++)
                {
                    aquelascoisas[i] += "*";
                }
            }
        }
    }

    for (int i = 0; i < aquelascoisas.size(); i++)
    {
        if (i == aquelascoisas.size() - 1)
        {
            cout << aquelascoisas[i] << endl;
        }
        else
            cout << aquelascoisas[i] << " ";
        
    }

}