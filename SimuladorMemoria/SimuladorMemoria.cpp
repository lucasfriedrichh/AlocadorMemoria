/*
    Lucas Muliterno Tomasini Friedrich
    Leonardo Salinet
*/
#include <iostream>
#include <random>
using namespace std;

int memoria[12];
int copia[12];
int aleatorio[10];
int tamanhoPrint = 12;
int indiceNextFit = 0;
int indicePrint = -1;
bool encaixePerfeito = false;

void carregarMemoria(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    for(int i = 0; i < 12; i++){
        memoria[i] = dist(gen);
        copia[i] = dist(gen);
    }
}

void carregarCopiaMemoria(){
    tamanhoPrint = 12;
    indiceNextFit = 0;
    indicePrint = -1;
    encaixePerfeito = false;
    for(int i = 0; i < 12; i++){
        memoria[i] = copia[i];
    }
}

void gerarAleatorios(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    for(int i = 0; i < 10; i++){
        aleatorio[i] = dist(gen);
    }
}

void ajustar(int indice){
    int tempIndice = indice;
    while(tempIndice < tamanhoPrint - 1){
        memoria[tempIndice] = memoria[tempIndice + 1];
        tempIndice++;
    }
    tamanhoPrint--;
}

void firstFit(int valor){
    for(int i = 0; i < tamanhoPrint; i++){
        if(memoria[i] == valor){
            memoria[i] -= valor;
            indicePrint = i;
            encaixePerfeito = true;
            break;
        }
        else if(memoria[i] > valor){
            memoria[i] -= valor;
            indicePrint = i;
            break;
        }
    }
    if(indicePrint == -1){
        cout << "\33[31m Solicitacao nao pode ser atendida \33[0m" << endl;
        return;
    }
    cout << "[";
    for(int i = 0; i < tamanhoPrint; i++){
        if(i == tamanhoPrint - 1){
            if(i == indicePrint){
                cout << "\33[31m" << memoria[i] << "\33[0m" << "]";
            }
            else{
                cout << memoria[i] << "]";
            }
        }
        else if(i == indicePrint){
            cout << "\33[31m" << memoria[i] << "\33[0m" << " - "; 
        }
        else{
            cout << memoria[i] << " - ";
        }
    }
    if(encaixePerfeito){
        cout << "\33[31m Encaixe perfeito \33[0m" << endl;
        ajustar(indicePrint);
    }
    else{
        cout << endl;
    }
    encaixePerfeito = false;
    indicePrint = -1;
}

void bestFit(int valor){
    int melhor = 1123456789;
    int indiceMelhor = -1;
    for(int i = 0; i < tamanhoPrint; i++){
        if(memoria[i] >= valor && memoria[i] < melhor){
            melhor = memoria[i];
            indiceMelhor = i;
            if(memoria[i] == valor){
                encaixePerfeito = true;
            }
        }
    }
    if(indiceMelhor == -1){
        cout << "\33[31m Solicitacao nao pode ser atendida \33[0m" << endl;
        return;
    }
    memoria[indiceMelhor] -= valor;
    cout << "[";
    for(int i = 0; i < tamanhoPrint; i++){
        if(i == tamanhoPrint - 1){
            if(i == indiceMelhor){
                cout << "\33[31m" << memoria[i] << "\33[0m" << "]";
            }
            else{
                cout << memoria[i] << "]";
            }
        }
        else if(i == indiceMelhor){
            cout << "\33[31m" << memoria[i] << "\33[0m" << " - "; 
        }
        else{
            cout << memoria[i] << " - ";
        }
    }
    if(encaixePerfeito){
        cout << "\33[31m Encaixe perfeito \33[0m" << endl;
        ajustar(indiceMelhor);
    }
    else{
        cout << endl;
    }
    encaixePerfeito = false;
}

void worstFit(int valor){
    int pior = -1;
    int indicePior = -1;
    for(int i = 0; i < tamanhoPrint; i++){
        if(memoria[i] >= valor && memoria[i] > pior){
            pior = memoria[i];
            indicePior = i;
        }
    }
    if(indicePior == -1){
        cout << "\33[31m Solicitacao nao pode ser atendida \33[0m" << endl;
        return;
    }
    if(memoria[indicePior] == valor){
        encaixePerfeito = true;
    }
    memoria[indicePior] -= valor;
    cout << "[";
    for(int i = 0; i < tamanhoPrint; i++){
        if(i == tamanhoPrint - 1){
            if(i == indicePior){
                cout << "\33[31m" << memoria[i] << "\33[0m" << "]";
            }
            else{
                cout << memoria[i] << "]";
            }
        }
        else if(i == indicePior){
            cout << "\33[31m" << memoria[i] << "\33[0m" << " - "; 
        }
        else{
            cout << memoria[i] << " - ";
        }
    }
    if(encaixePerfeito){
        cout << "\33[31m Encaixe perfeito \33[0m" << endl;
        ajustar(indicePior);
    }
    else{
        cout << endl;
    }
    encaixePerfeito = false;
}

void nextFit(int valor){
    for(int i = indiceNextFit; i < tamanhoPrint; i++){
        if(memoria[i] == valor){
            memoria[i] -= valor;
            indicePrint = i;
            encaixePerfeito = true;
            break;
        }
        else if(memoria[i] > valor){
            memoria[i] -= valor;
            indicePrint = i;
            break;
        }
    }
    if(indicePrint == -1){
        indiceNextFit = 0;
        cout << "\33[31m Solicitacao nao pode ser atendida \33[0m" << endl;
        return;
    }
    cout << "[";
    for(int i = 0; i < tamanhoPrint; i++){
        if(i == tamanhoPrint - 1){
            if(i == indicePrint){
                cout << "\33[31m" << memoria[i] << "\33[0m" << "]";
            }
            else{
                cout << memoria[i] << "]";
            }
        }
        else if(i == indicePrint){
            cout << "\33[31m" << memoria[i] << "\33[0m" << " - "; 
        }
        else{
            cout << memoria[i] << " - ";
        }
    }
    if(encaixePerfeito){
        cout << "\33[31m Encaixe perfeito \33[0m" << endl;
        ajustar(indicePrint);
    }
    else{
        cout << endl;
    }
    encaixePerfeito = false;
    indicePrint = -1;
    indiceNextFit++;
}

int main(){
    carregarMemoria();
    gerarAleatorios();
    cout << "===== Gerenciador de memoria por particoes dinamicas =====" << endl << endl;
    cout << "===== Algoritmo First-fit! =====" << endl << endl;
    cout << "Original [";
    for(int i = 0; i < 11; i++){
        cout << memoria[i] << " - ";
    }
    cout << memoria[11] << "]" << endl;
    for(int i = 0; i < 10; i++){
        cout << "[" << i << " - " << aleatorio[i] << "] ";
        firstFit(aleatorio[i]);
    }
    carregarCopiaMemoria();
    cout << endl << "===== Algoritmo Best-fit! =====" << endl << endl;
    cout << "Original [";
    for(int i = 0; i < 11; i++){
        cout << memoria[i] << " - ";
    }
    cout << memoria[11] << "]" << endl;
    for(int i = 0; i < 10; i++){
        cout << "[" << i << " - " << aleatorio[i] << "] ";
        bestFit(aleatorio[i]);
    }
    carregarCopiaMemoria();
    cout << endl << "===== Algoritmo Worst-fit! =====" << endl << endl;
    cout << "Original [";
    for(int i = 0; i < 11; i++){
        cout << memoria[i] << " - ";
    }
    cout << memoria[11] << "]" << endl;
    for(int i = 0; i < 10; i++){
        cout << "[" << i << " - " << aleatorio[i] << "] ";
        worstFit(aleatorio[i]);
    }
    carregarCopiaMemoria();
    cout << endl << "===== Algoritmo Next-fit! =====" << endl << endl;
    cout << "Original [";
    for(int i = 0; i < 11; i++){
        cout << memoria[i] << " - ";
    }
    cout << memoria[11] << "]" << endl;
    for(int i = 0; i < 10; i++){
        cout << "[" << i << " - " << aleatorio[i] << "] ";
        nextFit(aleatorio[i]);
    }
    return 0;
}