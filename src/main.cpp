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
/*
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
*/

string fila2string(prg2::fila_circular<int>& q, char delim = ',') {
  string r;

  // somente gera a string de resultado se deque não estiver vazio
  if (!prg2::fila_vazia(q)) {
    auto len = prg2::fila_tamanho(q);
    // itera o deque, convertendo seus valores para string e unindo-os com o
    // caractere delim
    for (int j = 0; j < len; j++) {
      r += std::to_string(prg2::fila_acessa(q, j)) + delim;
    }
    // remove o caractere delimitador em excesso
    r.pop_back();
  }

  return r;
}

int main() {
  auto q = prg2::fila_cria<int>(4);
  prg2::fila_anexa(q, 4);
  prg2::fila_anexa(q, 7);
  prg2::fila_insere(q, 5);
  prg2::fila_insere(q, 8);
  
  cout << fila2string(q) << endl;

  prg2::fila_remove_inicio(q);
  cout << fila2string(q) << endl;

  prg2::fila_anexa(q, 9);
  cout << fila2string(q) << endl;

  for (int i = 0; i < q.capacidade; i++) {
    cout << "pos " << i << "=" << q.area[i] << endl;
  }

  auto teste = prg2::fila_frente(q);
  auto teste2 = prg2::fila_atras(q);
  auto teste3 = prg2::fila_acessa(q, 2);
  cout << teste << endl;
  cout << teste2 << endl;
  cout << teste3 << endl;

  /*
    // cria um deque que armazena int
    auto q1 = prg2::deque_cria<int>();

    // acrescenta dados ao início
    prg2::deque_insere(q1, 7);
    prg2::deque_insere(q1, 9);
    cout << "Deque após inserir alguns dados: " << deque2string(q1) << endl;

    // acrescenta dados ao final
    prg2::deque_anexa(q1, 2);
    prg2::deque_anexa(q1, 4);
    cout << "Deque após anexar mais alguns dados: " << deque2string(q1) << endl;

    // Remove um dado do início
    prg2::deque_remove_inicio(q1);
    cout << "Deque após remover do início: " << deque2string(q1) << endl;

    // Remove um dado do final
    prg2::deque_remove_final(q1);
    cout << "Deque após remover do final: " << deque2string(q1) << endl;

    prg2::deque_destroi(q1);
    return 0;
  */
}
