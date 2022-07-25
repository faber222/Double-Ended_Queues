#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>

#include "deque.h"
#include "funcoes.h"

using std::cout;
using std::endl;
using std::stoi;
using std::string;
using par = std::pair<string, double>;

int main(int argc, char* argv[]) {
  std::ifstream arq(argv[1]);  // abre o arquivo em modo leitura
  if (!arq.is_open()) {
    cerr << "Algum erro ao abrir o arquivo ..." << endl;
    exit(true);
  }

  list<par> valores;
  string sep = " ";           // caracter para separar os dados
  string tipo_media = "mms";  // define string padrao
  int intervalo;              // variavel de intervalo

  // verifica se o intervalo é valido
  try {
    intervalo = stoi(argv[2]);  // converte uma string para inteiro
    if (intervalo <= 0) {
      cerr << "o valor de intervalo deve ser maior que 0" << endl;
      exit(true);
    }
  } catch (...) {
    // retorna invalido caso a operação acima não seja possivel
    throw std::invalid_argument("valor de argv[2] invalido");
  }

  if (argc == 4) {         // se for digitado um terceiro argumento
    tipo_media = argv[3];  // salva em tipo_media
  }
  // obtem dados do arquivo;
  le_arquivo(arq, valores, sep);
  if (tipo_media == "mms") {
    mms(valores, intervalo);
  }
  if (tipo_media == "mmp") {
    mmp(valores, intervalo);
  }
}
