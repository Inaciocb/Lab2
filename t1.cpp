#include <iostream>
#include <sstream>

using namespace std;

bool eh_valido(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return false;
    if (a + b <= c || a + c <= b || b + c <= a)
        return false;
    else
    return true;
}

int main()
{
    int qtdTriangulos, lados[3];
    std:: cout << "Quantos triângulos você irá digitar? " << std::endl;
    std:: cin >> qtdTriangulos;

    for(int i = 0 ; i < qtdTriangulos ; i++)
    {
        std:: cout << "Digite os lados do triângulo: " << std::endl;
        std:: cin >> lados[0] >> lados[1] >> lados[2];
        while(eh_valido(lados[0], lados[1], lados[2]) == false)
        {
            std:: cout << "Triângulo inválido, digite novamente: " << std::endl;
            std:: cout << "Digite os lados do triângulo: " << std::endl;
            std:: cin >> lados[0] >> lados[1] >> lados[2];
        }
        if(lados[0] == lados[1] && lados[1] == lados[2])
            std:: cout << "equilatero" << std::endl;
        else if(lados[0] == lados[1] || lados[1] == lados[2] || lados[0] == lados[2])
            std:: cout << "isosceles" << std::endl;
        else
            std:: cout << "escaleno" << std::endl;
    }    
}
