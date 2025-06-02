#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main (void)
{
    int n = 0;
    cin >> n;
    float soma = {0};

    float coisas[n];

    for (int i = 0; i < n; i++)
    {
        cin >> coisas[i];
        soma += coisas[i];
    }

    float  media = soma / n;
    float dp = {0};

    for (int i = 0; i < n; i++)
    {
        dp += pow((coisas[i] - media), 2);
    }

    dp = sqrt(dp / n);

    cout << fixed << setprecision(4);
    cout << media << endl;
    cout << dp << endl;
}