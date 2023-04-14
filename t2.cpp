#include <iostream>
#include <fstream>
#include <vector>

bool eh_bomba(char c)
{
    return c == '@';
}

int main()
{
    std::ifstream mapa("mapa.txt"); 
    std::vector<std::vector<char>> matriz;
  
    std::string linha;
    while (std::getline(mapa, linha)) 
    {
        std::vector<char> nova_linha(linha.begin(), linha.end()); 
        matriz.push_back(nova_linha); 
    }
    int n_linhas = matriz.size();
    int n_colunas = matriz[0].size();
    for (int i = 0; i < n_linhas; i++) 
    {
        for (int j = 0; j < n_colunas; j++) 
        {
            int bombas_ao_redor = 0;
            if (eh_bomba(matriz[i][j])) 
            {
                std::cout << '@'; 
            } else 
            {
                for (int di = -1; di <= 1; di++) 
                {
                    for (int dj = -1; dj <= 1; dj++) 
                    {
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < n_linhas && nj >= 0 && nj < n_colunas && eh_bomba(matriz[ni][nj])) 
                            bombas_ao_redor++;
                    }
                }
                std::cout << bombas_ao_redor;
            }
        }
        std::cout << std::endl; 
    }

    return 0;
}
