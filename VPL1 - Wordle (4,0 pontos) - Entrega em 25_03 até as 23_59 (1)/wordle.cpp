#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>


int main (void)
{

    std::string nomefile = "cusujo.txt";
    std::ifstream in(nomefile);

    if (!in.is_open())
    {
        std::cout << "EXPLODIR" << std::endl;
        return 1;
    }

    int n = 0;
    std::cin >> n;
    int linhacerta = 0;
    bool issotacerto = false;

    std::string palavra;
    std::string tentativa;
    int tentativas = 0;
    std::string podres;
    int contapodre = 0;

    while(std::getline(in, palavra))
    {
        if ((n) == linhacerta)
        {
           while (std::cin >> tentativa) 
           {
                tentativas++;
                for (int i = 0; i < 5; i++)
                {
                    issotacerto = false;
                    if (palavra[i] == tentativa[i])// caso a letra esteja na posição correta
                    {
                        std::cout << palavra[i];
                        continue;
                    }

                    for (int r = 0; r < 5; r++)
                    {
                        if (palavra[r] == tentativa[i])
                        {
                            char comp = tolower(tentativa[i]);
                            std::cout << comp;
                            issotacerto = true;
                            break;
                        }
                    }    

                    if(issotacerto != true)
                    {
                        std::cout << "*";

        
                        if (podres.find(tentativa[i]) == std::string::npos)
                        {
                            podres.insert(contapodre, 1, tentativa[i]);
                            contapodre++;
                        }
                        continue;
                    }
                }
                if (contapodre > 0)
                {
                    std::cout << " (" << podres << ")";
                }
                std::cout << std::endl;

                if (tentativa == palavra)
                {
                    std::cout << "GANHOU!";
                    return 0;
                }
                if (tentativas == 5)
                {
                    std::cout << "PERDEU! " << palavra;
                    return 0;
                }
            }
       }
       linhacerta++;
    }
}