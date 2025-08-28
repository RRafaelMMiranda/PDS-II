#include <iostream>
#include <memory>


class Teste{
    public:
    int receba;

    public:
    Teste() : Teste(0){};
    Teste(int x) : receba(x){

        std::cout << "Construtor " << receba << std::endl;
    }

    ~Teste(){
        std::cout << "Destrutor " << receba << std::endl;
    }
};

int main (void)
{
    int n = 0;
    std::cin >> n;
    if (n % 2 == 0)
    {
        for (int c = 1; c <= n; c++)
        {
            Teste *ptr = nullptr;
            ptr = new Teste(c);
            std::unique_ptr<Teste> ptru(new Teste(c));
        }
    }
    else if (n % 2 != 0)
    {
        std::shared_ptr<Teste> ptrs(new Teste(0));
        for (int c = 1; c <= n; c++)
        {
            std::shared_ptr<Teste> ptrs2;
            ptrs2 = ptrs;
            (*ptrs2).receba = c;
        }
        std::cout << ptrs.use_count() << std::endl;
    }
}