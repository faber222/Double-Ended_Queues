#ifndef DEQUE_FILA_CIRCULAR_IMPL_H
#define DEQUE_FILA_CIRCULAR_IMPL_H

#include <stdexcept>

namespace prg2 {
// create the deque
template <typename T>
fila_circular<T> fila_cria(int capacidade) {
  if (capacidade <= 0) {
    throw std::invalid_argument("capacidade deve ser > 0!");
  }

  fila_circular<T> fila;

  fila.inicio = 0;
  fila.fim = 0;
  fila.n = 0;
  fila.capacidade = capacidade;
  fila.area = new T[capacidade];

  return fila;
}

// remove the deque
template <typename T>
void fila_destroi(fila_circular<T>& fila) {
  delete[] fila.area;
  fila.area = nullptr;
  fila.n = 0;
  fila.inicio = 0;
  fila.fim = 0;
  fila.capacidade = 0;
}

// add data at the end
template <typename T>
void fila_anexa(fila_circular<T>& fila, const T& dados) {
  if (fila_cheia(fila)) {
    throw std::invalid_argument("fila está cheia");
  }
  fila.area[fila.fim] = dados;
  fila.n++;
  fila.fim++;
  if (fila.fim == fila.capacidade) {
    fila.fim = 0;
  }
}

// add data at the begin
template <typename T>
void fila_insere(fila_circular<T>& fila, const T& dados) {}

// remove the last data
template <typename T>
void fila_remove_final(fila_circular<T>& fila) {}

// remove the first data
template <typename T>
void fila_remove_inicio(fila_circular<T>& fila) {}

// show randon data
template <typename T>
T& fila_acessa(fila_circular<T>& fila, int pos) {}

// show the fist data
template <typename T>
T& fila_frente(fila_circular<T>& fila) {}

// show the last data
template <typename T>
T& fila_atras(fila_circular<T>& fila) {}

// check if is empty
template <typename T>
bool fila_vazia(const fila_circular<T>& fila) {
  return fila.n == 0;
}

// check if is full
template <typename T>
bool fila_cheia(const fila_circular<T>& fila) {
  return fila.n == fila.capacidade;
}

// check the size of
template <typename T>
int fila_tamanho(const fila_circular<T>& fila) {
  return fila.n;
}

}  // namespace prg2

#endif  // FILA_CIRCULAR_IMPL_H