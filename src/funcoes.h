#ifndef FUNCOES_H
#define FUNCOES_H

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <utility>

#include "deque.h"

using namespace std;

using par = pair<string, double>;

void separa_em_pares(const string &texto, string sep, list<par> &pares);

list<string> separa(const string &texto, string sep);

void le_arquivo(ifstream &arq, list<par> &valores, const string sep);

void mms(list<par> &dados, int intervalo);

void mmp(list<par> &dados, int intervalo);

void calculo_mms(prg2::deque<par> &d1, prg2::deque<par> &d2, int intervalo);

void calculo_mmp(prg2::deque<par> &d1, prg2::deque<par> &d2, int intervalo);

void mostra_resultado(prg2::deque<par> &d2);

#endif