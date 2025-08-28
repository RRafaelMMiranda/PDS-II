#include "aluno.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

Aluno::Aluno() : Aluno("", 0) {}
Aluno::Aluno(string nome, int matricula)
{
    this->nome = nome;
    this->matricula = matricula;
}
void Aluno::adicionar(int notaaux)
{
    this->notas.push_back(notaaux);
}
void Aluno::sortear()
{
    sort(this->notas.begin(), this->notas.end());
}
void Aluno::printar()
{  
    cout << this->matricula << " ";
    cout << this->nome << " ";
   
   
    for (int i = 0; i < notas.size();i++)
    {
        cout << notas[i] << " ";
    }
    cout << endl;
    cout << fixed << setprecision(2) << this->media() << " ";
    this->sortear();
    cout << this->notamax() << " " << this->notamin() << endl;
}
float Aluno::media()
{
    float temp = 0;
    int tam = notas.size();
    for(int i = 0; i < tam;i++)
    {
        temp += notas[i];
    }
    float resp = temp / tam;
    return resp;
}
string Aluno::getnome()
{
    string aux;
    aux = this->nome;
    return aux;
}

int Aluno::notamin()
{
    //vector<int>::iterator it = notas.begin();
    int auxx;
    auxx = notas[0];
    return auxx;
}
int Aluno::notamax()
{
    int auxx;
    auxx = notas[notas.size()-1];
    return auxx;
}
bool Aluno::operator<(Aluno other) 
{
    return this->nome < other.nome;
}
