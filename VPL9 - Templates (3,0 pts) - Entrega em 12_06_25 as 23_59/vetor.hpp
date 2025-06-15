#include <iostream>
#include <string>

template <typename k>
class Vetor{
    private:
    k* iniciovetor;
    int tamanho;
    int atual;
    

    public:
    Vetor(int tamanhoRecebe) : tamanho(tamanhoRecebe)
    {
        iniciovetor = new k[this->tamanho];
        atual = -1;
    }
    Vetor(const Vetor &vetorizado)
    {
        this->tamanho = vetorizado.tamanho;
        this->atual = vetorizado.atual;
        this->iniciovetor = new k[this->tamanho];
        for (int i = 0; i <= vetorizado.atual; i++)
        {
            this->iniciovetor[i] = vetorizado.iniciovetor[i];
        }
    }
    ~Vetor()
    {
        delete[] this->iniciovetor;
    };

    void SetElemento(int i, const k& x)
    {
        this->iniciovetor[i] = x;
        return;
    };
    const k& GetElemento(int i)
    {
        return this->iniciovetor[i];
    }
    void AdicionaElemento(const k& x)
    {
        this->atual++;
        this->iniciovetor[this->atual] = x;
        
        return;
    }
    void Imprime()
    {
        for (int i = 0; i <= this->atual; i++)
        {
            if (i != atual)
            {
                std::cout << iniciovetor[i] << " ";
            }
            else
                std::cout << iniciovetor[i] << std::endl;
            
        }
    }
};

