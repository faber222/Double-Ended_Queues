#ifndef FUNCOES_H
#define FUNCOES_H

using namespace std;

using par = pair<string, double>;

list<string> separa(const string &texto, string sep);

void separa_em_pares(const string &texto, string sep, list<par> &pares);

void le_arquivo(ifstream &arq, list<par> &valores, const string sep);

void mostra_resultado(prg2::deque<par> &d2);

void mm(list<par> &dados, int intervalo, const string tipo);

void calculo_mms(prg2::deque<par> &d1, prg2::deque<par> &d2, int intervalo);

void calculo_mmp(prg2::deque<par> &d1, prg2::deque<par> &d2, int intervalo);


#include "funcoes_impl.h"

#endif