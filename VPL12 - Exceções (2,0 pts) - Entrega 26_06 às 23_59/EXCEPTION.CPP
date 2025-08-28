#include <iostream>
#include <vector>

class NegativeResultException : public std::exception{
    public:
    int receba;
    public:
    NegativeResultException(int recebaa) : receba(recebaa){
    };
    void what(){
        std::cout << "Erro: Resultado Negativo." << std::endl;
    }


};

int main (void)
{
    std::vector<int> vetor = {-20, -10, 0, 10, 20};
    try{
        int aux = 0;
        std::cin >> aux;
        if(aux > 4) 
        {
            throw std::out_of_range("Erro: Parametro invalido");
        }
        vetor.at(aux);
        if(vetor.at(aux) < 0)
        {
            throw NegativeResultException(vetor.at(aux));
        }
        else if (vetor.at(aux) == 0)
        {
            throw std::logic_error("Erro: O resultado nao deve ser zero");
        }
        else{
            std::cout << vetor.at(aux) << std::endl;
        }
        
    }catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
    }
    catch(NegativeResultException& e){
        e.what();
        std::cout << e.receba << std::endl;
    }
    catch(std::logic_error& e){
        std::cout << e.what() << std::endl;
    }
}