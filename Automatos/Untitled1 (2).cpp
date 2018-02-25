#include <iostream>
#include<locale.h>

using namespace std;

int encontrar(char v[], char c, int t) {

    int i=0;
    while(i<t){
        if(v[i] == c){
            break;
        }
        i++;
    }
    return i;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    cout<<"Entre com a Quantidade de Estados da Máquina: "<<endl;
    int numQ;
    cin>>numQ;

    cout<<"Entre com os Elementos dos Estados: "<<endl;
    char estados[numQ];
    int novoEstado[numQ];

    for(int i=0; i<numQ; i++){
        cin>>estados[i];

        novoEstado[i] = encontrar(estados, estados[i], 5);
        cout<<novoEstado[i]<<endl;
    }

    cout<<"Entre com a Quantidade do Alfabeto: "<<endl;
    int numAlfabeto;
    cin>>numAlfabeto;

    cout<<"Entre com os Elementos do Alfabeto: "<<endl;
    char alfabeto[numAlfabeto];
    int novoAlfabeto[numAlfabeto];

    for(int i=0; i<numAlfabeto; i++){
        cin>>alfabeto[i];

        novoAlfabeto[i] = encontrar(alfabeto, alfabeto[i], numAlfabeto);

        cout<<novoAlfabeto[i]<<endl;
    }

    cout<<"Matriz de Tranzição"<<endl;
    char matriz[numQ][numAlfabeto];
    for(int i=0; i<numQ; i++){
        for(int j=0; j<numAlfabeto; j++){
            cin>>matriz[i][j];

            cout<<matriz[i][j]<<endl;
        }
        cout<<"\n"<<endl;
    }

    cout<<"Entre com o Estado Inicial: "<<endl;
    char inicial;
    cin>>inicial;

    cout<<"Entre com a Quantidade de Estados de Aceitação: "<<endl;
    int qtdAceita;
    cin>>qtdAceita;

    cout<<"Entre com o Estado de Aceitação: "<<endl;
    char aceitacao[qtdAceita];
    int novaAceitacao[qtdAceita];
    for(int i=0; i<qtdAceita; i++){
        cin>>aceitacao[i];

        novaAceitacao[i] = encontrar(aceitacao, aceitacao[i], qtdAceita);
    }

    cout<<"Entre com a Quantidade de Cadeias de Teste: "<<endl;
    int qtdTeste;
    cin>>qtdTeste;


    int tamCadeia;
    int atual=0;
    int cont = 0;

    while(cont < qtdTeste){

        cin>>tamCadeia;

        char cadeia[tamCadeia];
        for(int i=0; i<tamCadeia; i++){
            cin>>cadeia[i];
        }

        atual+= encontrar(estados, inicial, numQ);
        cout<<"Atual-> "<<atual<<endl;

        for(int i=0; i<tamCadeia; i++){//comparação da matriz com a cadeia
            atual = matriz[atual][encontrar(cadeia, alfabeto[i], tamCadeia)];

            cout<<"Atual-> "<<atual<<endl;
        }

        for(int i=0; i<qtdAceita; i++){
            if(novaAceitacao[i] == atual)
                cout<<"aceita"<<endl;
                break;
        }

        for(int i=0; i<qtdAceita; i++){
            if(novaAceitacao[i] != atual)
                cout<<"rejeita"<<endl;
                break;
        }

        atual = 0;

        cont++;
    }



    return 0;
}
