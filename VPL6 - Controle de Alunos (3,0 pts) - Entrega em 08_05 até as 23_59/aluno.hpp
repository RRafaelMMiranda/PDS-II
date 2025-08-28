#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>

using namespace std;

class Aluno{
    private:
        string nome;
        int matricula;
        vector<int> notas;

    public:
        Aluno();
        Aluno(string nome, int matricula);
        void sortear();
        void adicionar(int notaaux);
        void printar();
        float media ();
        int notamax ();
        int notamin ();
        string getnome();
        bool operator<(Aluno other);
};

#endif
