#include <bits/stdc++.h>
using namespace std;

class luva{
    private:
        int id;
        static int quantos;
        static int prox;

    public:
        
        luva (int x)
        {
            id = x;
            luva::quantos++;
        }
        luva()
        {
            id = luva::prox++;
            luva::quantos++; 
        }
        int getId()
        {
            return this->id;
        }
        static int getQuantos()
        {
            return luva::quantos;
        }
        luva* endereco()
        {
            return this;
        }
        ~luva()
        {
            luva::quantos--;
        }
};
int luva::quantos = 0;
int luva::prox = 1;

int main (void)
{

    list<luva*> luveiros;
    char c;
    while (1)
    {
        cin >> c;
        if (c == 'E')
        {
            break;
        }
        if (c == 'A')
        {
            luva *aux;
            aux = new luva();
            luveiros.push_back(aux);
            cout << aux->getId() << " " << aux->endereco();
        }
        if (c == 'C')
        {
            int par = 0;
            cin >> par;
            if (par >= 0)
            {
                cout << "ERRO";            }
            else{
            luva *aux;
            aux = new luva(par);
            cout << aux->getId() << " " << aux->endereco();
            luveiros.push_front(aux);}
        }
        if (c == 'R')
        {
            if (luveiros.empty())
            {
                cout << "ERRO";
            }
            else {
            cout << luveiros.front()->getId() << " " << luveiros.front()->endereco();
            delete luveiros.front();
            luveiros.pop_front();}
        }
        if (c == 'N')
        {
            cout << luva::getQuantos();
        }
        if (c == 'P')
        {
            int par = 0;
            cin >> par;
            if (par < 1 || par > luveiros.size())
            {
                cout << "ERRO";
            }
            else {
            list<luva*>::iterator it;
            int contador = 0;
            for (it = luveiros.begin(); it != luveiros.end(); it++)
            {
                if(par-1 != contador)
                {                
                    contador++;
                }
                else
                {
                    cout << (*it)->getId() << " " << (*it)->endereco();
                    break;
                }
                    
            }
        }

        }
        if (c == 'L')
        {
            list<luva*>::iterator it;
            for (it = luveiros.begin();it != luveiros.end();it++)
            {
                cout << (*it)->getId() << " " << (*it)->endereco() << endl;
            }
            continue;
        }
        cout << endl;
    }
}