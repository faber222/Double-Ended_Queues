#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

#include "deque.h"
#include "funcoes.h"

using std::cout;
using std::endl;
using std::string;

// gera uma string com uma representação do conteúdo do deque
// Parâmetros:
//  q: o deque
// delim: um caractere a ser usado como delimitador entre os valores do deque na
// string Resultado: uma string com o conteúdo do deque

string deque2string(prg2::deque<int>& q, char delim = ',') {
  string r;

  // somente gera a string de resultado se deque não estiver vazio
  if (!prg2::deque_vazio(q)) {
    auto len = prg2::deque_tamanho(q);
    // itera o deque, convertendo seus valores para string e unindo-os com o
    // caractere delim
    for (int j = 0; j < len; j++) {
      r += std::to_string(prg2::deque_acessa(q, j)) + delim;
    }
    // remove o caractere delimitador em excesso
    r.pop_back();
  }

  return r;
}

int main(int argc, char* argv[]) {
  std::ifstream arq(argv[1]);
  int intervalo = std::stoi(argv[2]);
  string tipo_media = "mms";
  if (argc == 4) {
    tipo_media = argv[3];
  }
  if (tipo_media == "mmp") {
    // do
  } else if (tipo_media == "mms") {
    std::cout << "chama" << endl;
  }

  // cria um deque que armazena int
  auto q1 = prg2::deque_cria<int>();
}
