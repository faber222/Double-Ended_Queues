#ifndef DEQUE_DEQUE_IMPL_H
#define DEQUE_DEQUE_IMPL_H

namespace prg2 {
template <typename T>
trecho<T>* trecho_cria(int tam_trecho) {
  auto p_trecho = new trecho<T>;

  p_trecho->fila = fila_cria<T>(tam_trecho);
  p_trecho->proximo = nullptr;
  return p_trecho;
}

// create a empty deque
template <typename T>
deque<T> deque_cria(int tam_trecho) {
  deque<T> q;

  auto p_trecho = trecho_cria<T>(tam_trecho);

  q.tamanho = 0;
  q.primeiro = p_trecho;
  q.ultimo = p_trecho;

  return q;
}

// remove deque
template <typename T>
void deque_destroi(deque<T>& q) {}

// return the size of deque
template <typename T>
int deque_tamanho(const deque<T>& q) {
  return q.tamanho;
}

// try if is empty
template <typename T>
bool deque_vazio(const deque<T>& q) {
  return q.tamanho == 0;
}

// include a data on the end
template <typename T>
void deque_anexa(deque<T>& q, const T& dado) {
  if (fila_cheia(q.ultimo->fila)) {
    auto tamanho = fila_tamanho(q.ultimo->fila);
    q.ultimo->proximo = trecho_cria<T>(tamanho);
    q.ultimo = q.ultimo->proximo;
  }
  fila_anexa(q.ultimo->fila, dado);
  q.tamanho++;
}

// insert a data on the begin
template <typename T>
void deque_insere(deque<T>& q, const T& dado) {
  if (fila_cheia(q.primeiro->fila)) {
    auto tamanho = fila_tamanho(q.primeiro->fila);
  }
}

// remove the last data
template <typename T>
void deque_remove_final(deque<T>& q) {}

// remove the first data
template <typename T>
void deque_remove_inicio(deque<T>& q) {}

// show the last data
// if is empty, throw invalid_argument!
template <typename T>
T& deque_acessa_final(deque<T>& q) {}

// show the first data
// if is empty, throw invalid_argument!
template <typename T>
T& deque_acessa_inicio(deque<T>& q) {}

// show any data
// if is empty, throw invalid_argument!
template <typename T>
T& deque_acessa(deque<T>& q, int pos) {}

}  // namespace prg2

#endif