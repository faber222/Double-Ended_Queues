#ifndef DEQUE_FILA_CIRCULAR_H
#define DEQUE_FILA_CIRCULAR_H

// a definição da fila circular, que é usada pelo deque !
namespace prg2 {
template <typename T>
struct fila_circular {
  T* area;  // vector pointer

  int inicio, fim;
  int n;           // database amount
  int capacidade;  // vector size
};

// create the deque
template <typename T>
fila_circular<T> fila_cria(int capacidade);

// remove the deque
template <typename T>
void fila_destroi(fila_circular<T>& fila);

// add data at the end
template <typename T>
void fila_anexa(fila_circular<T>& fila, const T& dados);

// add data at the begin
template <typename T>
void fila_insere(fila_circular<T>& fila, const T& dados);

// remove the last data
template <typename T>
void fila_remove_final(fila_circular<T>& fila);

// remove the first data
template <typename T>
void fila_remove_inicio(fila_circular<T>& fila);

// show randon data
template <typename T>
T& fila_acessa(fila_circular<T>& fila, int pos);

// show the fist data
template <typename T>
T& fila_frente(fila_circular<T>& fila);

// show the last data
template <typename T>
T& fila_atras(fila_circular<T>& fila);

// check if is empty
template <typename T>
bool fila_vazia(const fila_circular<T>& fila);

// check if is full
template <typename T>
bool fila_cheia(const fila_circular<T>& fila);

// check the size of
template <typename T>
bool fila_tamanho(const fila_circular<T>& fila);

}  // namespace prg2

#include "fila_circular_impl.h"
#endif  // DEQUE_FILA_CIRCULAR_H
