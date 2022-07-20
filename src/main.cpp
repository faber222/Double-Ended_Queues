#include <iostream>
#include <string>

#include "deque.h"

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

int main() {
  // cria um deque que armazena int
  auto q1 = prg2::deque_cria<int>();
  int pos = 10;

  // acrescenta dados ao início
  prg2::deque_insere(q1, 7);
  cout << "primeiro : " << prg2::deque_acessa_inicio(q1) << endl;
  prg2::deque_insere(q1, 9);
  cout << "primeiro : " << prg2::deque_acessa_inicio(q1) << endl;

  // acrescenta dados ao final
  prg2::deque_anexa(q1, 2);
  prg2::deque_anexa(q1, 4);
  prg2::deque_anexa(q1, 5);
  prg2::deque_anexa(q1, 6);
  prg2::deque_anexa(q1, 15);
  prg2::deque_anexa(q1, 20);
  prg2::deque_anexa(q1, 30);
  prg2::deque_anexa(q1, 40);
  cout << "ultimo : " << prg2::deque_acessa_final(q1) << endl;
  cout << "posicao : " << pos << " " << prg2::deque_acessa(q1, pos) << endl;

  // Remove um dado do início
  prg2::deque_remove_inicio(q1);

  // Remove um dado do final
  prg2::deque_remove_final(q1);

  prg2::deque_destroi(q1);
  return 0;
}
