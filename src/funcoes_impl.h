#ifndef FUNCOES_IMPL_H
#define FUNCOES_IMPL_H

using namespace std;

// declaracao de um pair, usado durante todo o codigo
using par = pair<string, double>;

// funcao separa default
list<string> separa(const string &texto, string sep) {
  int x = 0;
  string memoria;  // string que armazena o valor da separacao
  list<string> dados;
  while (x != string::npos) {
    int z = texto.find_first_not_of(sep, x);  // encontra o primeiro caracter
                                              // que nao for o separador
    if (z == string::npos) break;             // se a busca for o fim, para loop
    x = texto.find(sep, z);                   // encontra o primerio separador
    memoria = texto.substr(z, x - z);         // captura os dados do z até x-z
    dados.push_back(memoria);
  }
  return dados;
}

// separa os dados que estão entre espacos vazios
void separa_em_pares(const string &texto, string sep, list<par> &pares) {
  par valores;
  list<string> dados = separa(texto, sep);  // separa os dados do arquivo
  valores.first = dados.front();            // armazena as datas
  valores.second = stof(dados.back());      // converte string para float
  pares.push_back(valores);                 // adiciona na lista
}

// captura os dados do arquivo de texto
void le_arquivo(ifstream &arq, list<par> &valores, const string sep) {
  string dados;
  while (true) {                // le o arquivo enquanto for possivel
    if (getline(arq, dados)) {  // captura uma linha do arquivo
      separa_em_pares(dados, sep,
                      valores);  // chama funcao para adicionar dados a lista
    } else {
      arq.clear();  // caso nao de certo, limpa o arquivo e encerra
      break;
    }
  }
}

// mostra os resultados
void mostra_resultado(list<par> &d2) {
  // itera todas as posicoes existentes
  for (auto &x : d2) {
    // fixed and setprecision, fazem o arredondamento do double
    cout << x.first << " " << fixed << setprecision(2) << x.second << endl;
  }
}

// calcula o mms usando o deque
list<par> calculo_mms(list<par> &d1, int intervalo) {
  auto deque = prg2::deque_cria<par>(intervalo);
  list<par> d2;

  for (auto &x : d1) {
    prg2::deque_anexa(deque, x);
    if (prg2::deque_tamanho(deque) == intervalo) {
      auto val = media_movel_simples(deque);
      d2.push_back(val);
      prg2::deque_remove_inicio(deque);
    }
  }

  return d2;
}

list<par> calculo_mmp(list<par> &d1, int intervalo) {
  auto deque = prg2::deque_cria<par>(intervalo);
  list<par> d2;
  for (auto &x : d1) {
    prg2::deque_anexa(deque, x);
    if (prg2::deque_tamanho(deque) == intervalo) {
      auto val = media_movel_ponderada(deque);
      d2.push_back(val);
      prg2::deque_remove_inicio(deque);
    }
  }

  return d2;
}

// faz o calculo da media movel ponderada usando deque
par media_movel_ponderada(prg2::deque<par> &d1) {
  float soma = 0;
  auto divisor = prg2::deque_tamanho(d1);
  par valor;
  int count = 1;
  int somador = 0;

  for (int i = 0; i != divisor ; i++) {
    float m_ponderado;
    m_ponderado = count * prg2::deque_acessa(d1, i).second;
    soma += m_ponderado;
    somador += count;
    count++;
  }
  valor.first = prg2::deque_acessa_final(d1).first;
  valor.second = (double)(soma / somador);

  return valor;
}

// faz o calculo da media movel simples usando deque
par media_movel_simples(prg2::deque<par> &d1) {
  float soma = 0;
  auto divisor = prg2::deque_tamanho(d1);
  par valor;

  for (int i = 0; i != divisor; i++) {
    soma += prg2::deque_acessa(d1, i).second;
  }
  valor.first = prg2::deque_acessa_final(d1).first;
  valor.second = (double)(soma / divisor);

  return valor;
}

#include "funcoes.h"

#endif
