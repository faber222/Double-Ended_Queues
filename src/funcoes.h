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
void mostra_resultado(list<par> &d2);

// chama a funcao que calcula o mms
list<par> calculo_mms(list<par> &d1, int intervalo);

// chama a funcao que calcula o mmp
list<par> calculo_mmp(list<par> &d1, int intervalo);

// faz o calculo da media movel ponderada usando deque
par media_movel_ponderada(prg2::deque<par> &d1);

// faz o calculo da media movel simples usando deque
par media_movel_simples(prg2::deque<par> &d1);

#include "funcoes_impl.h"

#endif