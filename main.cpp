#include <iostream>
#include <string>
#include "deque.h"

using std::cout;
using std::endl;
using std::string;

// gera uma string com uma representação do conteúdo do deque
// Parâmetros:
//  q: o deque
// delim: um caractere a ser usado como delimitador entre os valores do deque na string
// Resultado: uma string com o conteúdo do deque
string deque2string(const prg2::deque<int> & q, char delim=',') {
    string r;

    // somente gera a string de resultado se deque não estiver vazio
    if (! prg2::deque_vazio(q)) {
        auto len = prg2::deque_tamanho(q);
        // itera o deque, convertendo seus valores para string e unindo-os com o caractere delim
        for (int j = 0; j < len; j++) {
            r += std::to_string(prg2::deque_acessa(q, j)) + delim;
        }
        // remove o caractere delimitador em excesso
        r.pop_back();
    }

    return r;
}

int main() {
    // cria um deque que armazena int
    prg2::deque<int> q1;

    // acrescenta dados ao início
    prg2::deque_insere(q1, 7);
    prg2::deque_insere(q1, 9);
    cout << "Deque após inserir alguns dados: " << deque2string(q1) << endl;

    // acrescenta dados ao final
    prg2::deque_anexa(q1, 2);
    prg2::deque_anexa(q1, 4);
    cout << "Deque após anexar mais alguns dados: " << deque2string(q1) << endl;

    // Remove um dado do início
    prg2::deque_remove_inicio(q1);
    cout << "Deque após remover do início: " << deque2string(q1) << endl;

    // Remove um dado do final
    prg2::deque_remove_final(q1);
    cout << "Deque após remover do final: " << deque2string(q1) << endl;

    return 0;
}
