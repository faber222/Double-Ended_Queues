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
void mostra_resultado(prg2::deque<par> &d2) {
  // itera todas as posicoes existentes
  for (int i = 0; i < prg2::deque_tamanho(d2); i++) {
    // fixed and setprecision, fazem o arredondamento do double
    cout << prg2::deque_acessa(d2, i).first << " " << fixed << setprecision(2)
         << prg2::deque_acessa(d2, i).second << endl;
  }
}

// funcao usada para decidir entre o calculo de mms e mmp
void mm(list<par> &dados, int intervalo, const string tipo) {
  auto d1 = prg2::deque_cria<par>(intervalo);  // cria um par de deque
  auto d2 = prg2::deque_cria<par>(intervalo);  // cria um par de deque

  for (auto &x : dados) {  // itera a lista para armazenar os dados no deque 1
    prg2::deque_anexa(d1, x);  // adiciona os dados no final
  }
  if (tipo == "mms") {
    // faz o calculo da media movel simples
    calculo_mms(d1, d2, intervalo);
  } else {
    // faz o calculo da media movel ponderada
    calculo_mmp(d1, d2, intervalo);
  }
  // mostra os dados do deque 2
  mostra_resultado(d2);

  // destroi os deques para nao ocupar memoria
  prg2::deque_destroi(d1);
  prg2::deque_destroi(d2);
}

// calcula o mms usando o deque
void calculo_mms(prg2::deque<par> &d1, prg2::deque<par> &d2, int intervalo) {
  int count = 1;  // contador para manter loop
  string data;    // string que armazena a data do mms atual

  // enquanto o deque nao for vazio e o tamanho nao for menor que o intervalo
  while (!prg2::deque_vazio(d1) && prg2::deque_tamanho(d1) >= intervalo) {
    float soma = 0;  // float usado para armazenar o mms
    // itera o contador para acessar cada posicao
    for (; count != intervalo + 1; count++) {
      // concatena os dados na soma
      soma += prg2::deque_acessa(d1, count - 1).second;
      data = prg2::deque_acessa(d1, count - 1).first;
    }
    // anexa os dados de soma e data dentro do deque 2 e calcula a media movel
    anexa_dados(d1, d2, data, soma, intervalo, count);
  }
}

// calcula a mmp usando o deque
void calculo_mmp(prg2::deque<par> &d1, prg2::deque<par> &d2, int intervalo) {
  int count = 1;  // contador para manter loop
  string data;    // string que armazena a data do mms atual

  // enquanto o deque nao for vazio e o tamanho nao for menor que o intervalo
  while (!prg2::deque_vazio(d1) && prg2::deque_tamanho(d1) >= intervalo) {
    float soma = 0;       // float usado para armazenar o mmp
    int s_ponderado = 0;  // valor inteiro usado para a divisao do mmp
    // itera o contador para acessar cada posicao
    for (; count != intervalo + 1; count++) {
      // concatena os dados multiplicados por i dentro da soma
      float m_ponderado;
      m_ponderado = count * prg2::deque_acessa(d1, count - 1).second;
      soma += m_ponderado;
      data = prg2::deque_acessa(d1, count - 1).first;
      // concatena o contador dentro de s_ponderado
      s_ponderado += count;
    }
    // anexa os dados de soma e data dentro do deque 2 e calcula a media movel
    anexa_dados(d1, d2, data, soma, s_ponderado, count);
  }
}

// salva os dados das medias dentro do deque
void anexa_dados(prg2::deque<par> &d1, prg2::deque<par> &d2, string &data,
                 float soma, int divisor, int &count) {
  par valor;           // para usado para ser amazenado no deque
  valor.first = data;  // declara o primeiro dado = data
  // divide os dados por um divisor qualquer e declara como sendo o segundo par
  valor.second = (double)(soma / divisor);
  // anexa os dados no segundo deque
  prg2::deque_anexa(d2, valor);
  // remove os dados do primeiro deque
  prg2::deque_remove_inicio(d1);
  // declara o contador = 1 para continuar loop
  count = 1;
}

#include "funcoes.h"

#endif
