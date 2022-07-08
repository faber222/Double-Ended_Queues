#ifndef DEQUE_DEQUE_H
#define DEQUE_DEQUE_H

#include "fila_circular.h"

namespace prg2 {

// deque template
template <typename T>
struct trecho {
  // deque and a pointer for the next deque
  fila_circular<T> fila;
  trecho<T>* proximo;
};

// template for using on the entire code
template <typename T>
struct deque {
  trecho<T>*primeiro, ultimo;
  int tamanho;
};

// create a empty deque
template <typename T>
deque<T> deque_cria();

// remove deque
template <typename T>
void deque_destroi(deque<T>& q);

// return the size of deque
template <typename T>
int deque_tamanho(const deque<T>& q);

// try if is empty
template <typename T>
bool deque_vazio(const deque<T>& q);

// insert a data on deque
template <typename T>
void deque_anexa(deque<T>& q, const T& dado);

// insert a data on the begin
template <typename T>
void deque_insere(deque<T>& q, const T& dado);

// remove the last data
template <typename T>
void deque_remove_final(deque<T>& q);

// remove the first data
template <typename T>
void deque_remove_inicio(deque<T>& q);

// show the last data
// if is empty, throw invalid_argument!
template <typename T>
T& deque_acessa_final(deque<T>& q);

// show the first data
// if is empty, throw invalid_argument!
template <typename T>
T& deque_acessa_inicio(deque<T>& q);

// show any data
// if is empty, throw invalid_argument!
template <typename T>
T& deque_acessa(deque<T>& q, int pos);

}  // namespace prg2
#include "fila_circular.h"

#endif  // DEQUE_DEQUE_H
