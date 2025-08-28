#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "aluno.hpp"

using namespace std;

int main (void)
{
    vector<Aluno> alunos;
    string final = {"END"};
    int flag = -1;
    vector<Aluno>::iterator it = alunos.begin();

    while(1)
    {
        string receber;
        cin >> receber;
        if (receber == final)
        {
            break;
        }
        int matricula = 0;
        cin >> matricula;
        Aluno temp(receber, matricula);
        int notaaux = 0;
        while (cin >> notaaux)
        {
            if (notaaux == flag)
            {
                break;
            }
            temp.adicionar(notaaux);
        }
        alunos.push_back(temp);
    }

    sort(alunos.begin(), alunos.end());
    for (int i = 0; i < alunos.size(); i++)
    {
        alunos[i].printar();
    }
    return 0;
}