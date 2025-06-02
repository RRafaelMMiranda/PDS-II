    #include <iostream>
#define _USE_MATH_DEFINES
    #include <cmath>
    #include <vector>
    #include <iomanip>
    #include <string>
    using namespace std;

    class Ponto{
        protected:
        int x;
        int y;

        public:
        Ponto(int _x, int _y) : x(_x), y(_y){}
        int get_pontox()
        {
            return this->x;
        }
        void set_pontox(int a)
        {
            this-> x = a;
            return;
        }
        int get_pontoy()
        {
            return this->y;
        }
        void set_pontoy(int a)
        {
            this->y = a;
            return;
        }
        ~Ponto()
        {
        }
    };

    class Figura
    {
        protected:
        Ponto centro;

        public:
        Figura(int _x, int _y) : centro(_x, _y){};
        virtual ~Figura(){};
        virtual void desenha()
        {
            int xtemp, ytemp;
            xtemp = this->centro.get_pontox();
            ytemp = this->centro.get_pontoy();
            cout << xtemp << " " << ytemp << " ";
        }
        virtual float CalcularArea() = 0;
    };
    class Retangulo : public Figura
    {
        private:
        int lado1;
        int lado2;

        public:
        Retangulo(int _x, int _y,int _lado1, int _lado2) : Figura(_x,_y), lado1(_lado1), lado2(_lado2) {};
        
        void desenha()
        {
        Figura::desenha();
        cout << "RETANGULO" << endl; 
        }
        float CalcularArea()
        {
            return this->lado1 * this->lado2;
        }
    };
    class Circulo : public Figura
    {
        private:
        int raio;

        public:
        Circulo(int _x, int _y, int _raio) : Figura(_x, _y), raio(_raio) {};
        void desenha()
        {
        Figura::desenha();
        cout << "CIRCULO" << endl;
        }
        float CalcularArea()
        {
            float area = pow(raio,2) * M_PI;
            return area;
        }
    };
    class Triangulo : public Figura
    {
        private:
        int altura;
        int base;

        public:
        Triangulo(int _x, int _y, int _altura, int _base) : Figura(_x, _y), altura(_altura), base(_base){}; 
        void desenha()
        {
            Figura::desenha();
            cout << "TRIANGULO" << endl;
        }
        float CalcularArea()
        {
            return (this->base * this->altura)/2.0;
        }
    };


    int main (void)
    {
        vector<Figura*> figuras;
        while (1)
        {
            char recebe;
            cin >> recebe;

            if (recebe == 'R')
            {
                int auxX, auxY, auxL1, auxL2;
                cin >> auxX >> auxY >> auxL1 >> auxL2;
                Retangulo* p = nullptr;
                p = new Retangulo(auxX, auxY, auxL1, auxL2);
                figuras.push_back(p);
            }
            if (recebe == 'C')
            {
                int auxX, auxY, auxR;
                cin >> auxX >> auxY >> auxR;
                Circulo* p = nullptr;
                p = new Circulo(auxX, auxY, auxR);
                figuras.push_back(p);
            }
            if (recebe == 'T')
            {
                int auxX,auxY, auxB, auxH;
                cin >> auxX >> auxY >> auxB >> auxH;
                Triangulo* p = nullptr;
                p = new Triangulo(auxX, auxY, auxB, auxH);
                figuras.push_back(p);
            }
            if (recebe == 'D')
            {
                for (int i = 0; i < figuras.size(); i++)
                {
                    figuras[i]->desenha();
                }
            }

            if (recebe == 'A')
            {
                float temp = 0;
                for (int i = 0; i < figuras.size(); i++)
                {   
                    temp += figuras[i]->CalcularArea();
                }
                cout << fixed << setprecision(2) << temp << endl;            
            }

            if (recebe == 'E')
            {
                for (Figura* figura : figuras) 
                {
                    delete figura;
                }
                return 0;
            }
        }


    } 