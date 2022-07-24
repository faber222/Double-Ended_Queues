#ifndef DEQUE_DEQUE_IMPL_H
#define DEQUE_DEQUE_IMPL_H

namespace prg2 {
template <typename T>
void trecho_destroi(trecho<T>* p) {
  fila_destroi(p->fila);
  delete p;
}

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
void deque_destroi(deque<T>& q) {
  for (auto ptr = q.primeiro; ptr != nullptr;) {
    auto proximo = ptr->proximo;
    trecho_destroi(ptr);
    ptr = proximo;
  }
}

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
    auto novo_trecho = trecho_cria<T>(tamanho);
    novo_trecho->proximo = q.primeiro;
    q.primeiro = novo_trecho;
  }
  fila_insere(q.primeiro->fila, dado);
  q.tamanho++;
}

// remove the last data
template <typename T>
void deque_remove_final(deque<T>& q) {
  fila_remove_final(q.ultimo->fila);

  if (fila_vazia(q.ultimo->fila)) {
    auto trecho_atual = q.primeiro;
    while (trecho_atual->proximo != q.ultimo) {
      trecho_atual = trecho_atual->proximo;
    }
    fila_destroi(trecho_atual->proximo->fila);
    q.ultimo = trecho_atual;
  }
  q.tamanho--;
}

// remove the first data
template <typename T>
void deque_remove_inicio(deque<T>& q) {
  auto trecho_novo = q.primeiro->proximo;
  fila_remove_inicio(q.primeiro->fila);

  if (fila_vazia(q.primeiro->fila)) {
    auto primeiro = q.primeiro;
    q.primeiro = trecho_novo;
    fila_destroi(primeiro->fila);
  }
  q.tamanho--;
}

// show the last data
// if is empty, throw invalid_argument!
template <typename T>
T& deque_acessa_final(deque<T>& q) {
  return fila_atras(q.ultimo->fila);
}

// show the first data
// if is empty, throw invalid_argument!
template <typename T>
T& deque_acessa_inicio(deque<T>& q) {
  return fila_frente(q.primeiro->fila);
}

// show any data
// if is empty, throw invalid_argument!
template <typename T>
T& deque_acessa(deque<T>& q, int pos) {
  if (deque_vazio(q)) {
    throw std::invalid_argument("deque vazio");
  }
  if (pos > q.tamanho - 1) {
    throw std::invalid_argument("posicao invalida");
  }

  auto salto = q.primeiro;
  while (pos >= fila_tamanho(salto->fila)) {
    pos = pos - fila_tamanho(salto->fila);
    salto = salto->proximo;
  }

  return fila_acessa(salto->fila, pos);
}
}  // namespace prg2

#endif