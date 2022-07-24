#include "funcoes.h"

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

void separa_em_pares(const string &texto, string sep, list<par> &pares) {
  par valores;
  list<string> dados = separa(texto, sep);
  valores.first = dados.front();
  valores.second = stof(dados.back());
  pares.push_back(valores);
}

void le_arquivo(ifstream &arq, list<par> &valores, const string sep) {
  string dados;
  while (true) {
    if (std::getline(arq, dados)) {
      separa_em_pares(dados, sep, valores);
    } else {
      arq.clear();
      break;
    }
  }
}

void mms(list<par> &dados, int intervalo) {
  auto d1 = prg2::deque_cria<par>(intervalo);
  auto d2 = prg2::deque_cria<par>(intervalo);

  for (auto &x : dados) {
    prg2::deque_anexa(d1, x);
  }

  calculo_mms(d1, d2, intervalo);

  mostra_resultado(d2);

  prg2::deque_destroi(d1);
  prg2::deque_destroi(d2);
}

void mmp(list<par> &dados, int intervalo) {
  auto d1 = prg2::deque_cria<par>(intervalo);
  auto d2 = prg2::deque_cria<par>(intervalo);

  for (auto &x : dados) {
    prg2::deque_anexa(d1, x);
  }

  calculo_mmp(d1, d2, intervalo);

  mostra_resultado(d2);

  prg2::deque_destroi(d1);
  prg2::deque_destroi(d2);
}

void mostra_resultado(prg2::deque<par> &d2) {
  while (!prg2::deque_vazio(d2)) {
    cout << prg2::deque_acessa_inicio(d2).first << " " << std::fixed
         << std::setprecision(2) << prg2::deque_acessa_inicio(d2).second
         << endl;
    prg2::deque_remove_inicio(d2);
  }
}

void calculo_mms(prg2::deque<par> &d1, prg2::deque<par> &d2, int intervalo) {
  int count = 1;
  string data;
  par valor;

  while (!prg2::deque_vazio(d1) && prg2::deque_tamanho(d1) >= intervalo) {
    float soma = 0;
    for (; count != intervalo + 1; count++) {
      soma = soma + prg2::deque_acessa(d1, count - 1).second;
      data = prg2::deque_acessa(d1, count - 1).first;
    }
    valor.first = data;
    valor.second = (double)(soma / intervalo);
    prg2::deque_anexa(d2, valor);
    prg2::deque_remove_inicio(d1);
    count = 1;
  }
}

void calculo_mmp(prg2::deque<par> &d1, prg2::deque<par> &d2, int intervalo) {
  int count = 1;
  string data;
  par valor;

  while (!prg2::deque_vazio(d1) && prg2::deque_tamanho(d1) >= intervalo) {
    float soma = 0;
    int s_ponderado = 0;
    for (; count != intervalo + 1; count++) {
      float m_ponderado;
      m_ponderado = count * prg2::deque_acessa(d1, count - 1).second;
      soma = soma + m_ponderado;
      data = prg2::deque_acessa(d1, count - 1).first;
      s_ponderado += count;
    }
    valor.first = data;
    valor.second = (double)(soma / s_ponderado);
    prg2::deque_anexa(d2, valor);
    prg2::deque_remove_inicio(d1);
    count = 1;
  }
}
