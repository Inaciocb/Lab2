#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>

template<typename T>
struct Arvore {
  void inicia(std::list<T>& entrada){
    if(entrada.empty() == true)
      return;
  }

  bool vazio(){
    return true;
  }

  bool posOrdem(std::list<T>& saida){
    return true;
  }

  void destroi(void){
    //
  }
};


TEST_CASE("Teste vazio") {
    Arvore<int> a;
    std::list<int> entrada {};
    a.inicia(entrada);
    REQUIRE(a.vazio() == true);
    a.destroi();
}

TEST_CASE("Teste nao vazio") {
    Arvore<int> a;
    std::list<int> entrada {1};
    a.inicia(entrada);
    REQUIRE(a.vazio() == false);
    a.destroi();
}

TEST_CASE("Caso 1") {
    Arvore<int> a;
    std::list<int> entrada {5, 3, 7};
    std::list<int> saida;
    std::list<int> resultado {3, 7, 5};
    a.inicia(entrada);
    a.posOrdem(saida);
    REQUIRE(saida == resultado);
    a.destroi();
}

TEST_CASE("Caso 3") {
    Arvore<char> a;
    std::list<char> entrada {'F', 'C', 'A', 'D', 'J', 'H', 'I', 'K'};
    std::list<char> saida;
    std::list<char> resultado {'A', 'D', 'C', 'I', 'H', 'K', 'J', 'F'};
    a.inicia(entrada);
    a.posOrdem(saida);
    REQUIRE(saida == resultado);
    a.destroi();
}

TEST_CASE("Caso N") {
    Arvore<int> a;
    std::list<int> entrada {50, 30, 24, 5, 28, 45, 98, 52, 60};
    std::list<int> saida;
    std::list<int> resultado {5, 28, 24, 45, 30, 60, 52, 98, 50};
    a.inicia(entrada);
    a.posOrdem(saida);
    REQUIRE(saida == resultado);
    a.destroi();
}
