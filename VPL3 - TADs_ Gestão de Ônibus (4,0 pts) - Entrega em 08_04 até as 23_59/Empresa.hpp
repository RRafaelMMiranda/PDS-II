#ifndef EMPRESA_H
#define EMPRESA_H
#include <string>
#include "Onibus.hpp"

struct Empresa{
    int _numeroonibus;
    Onibus* _vetor[20];

    Empresa(int);
    Onibus* adicionar_onibus(std::string, int);
    Onibus* busca_onibus(std::string _placa);
    void imprimir_estado();

};

#endif