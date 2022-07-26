#ifndef FUNCOES_H
#define FUNCOES_H

using namespace std;

// declaracao de um pair, usado durante todo o codigo
using par = pair<string, double>;

// funcao separa default
list<string> separa(const string &texto, string sep);

// separa os dados que estão entre espacos vazios
void separa_em_pares(const string &texto, string sep, list<par> &pares);

// captura os dados do arquivo de texto
void le_arquivo(ifstream &arq, list<par> &valores, const string sep);

// mostra os resultados
void mostra_resultado(prg2::deque<par> &d2);

// funcao usada para decidir entre o calculo de mms e mmp
void mm(list<par> &dados, int intervalo, const string tipo);

// calcula o mms usando o deque
void calculo_mms(prg2::deque<par> &d1, prg2::deque<par> &d2, int intervalo);

// calcula a mmp usando o deque
void calculo_mmp(prg2::deque<par> &d1, prg2::deque<par> &d2, int intervalo);

// salva os dados das medias dentro do deque
void anexa_dados(prg2::deque<par> &d1, prg2::deque<par> &d2, string &data,
                 float soma, int divisor, int &count);

#include "funcoes_impl.h"

#endif