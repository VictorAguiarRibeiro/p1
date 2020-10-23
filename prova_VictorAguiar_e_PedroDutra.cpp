#include<iostream>
#include<fstream>
#include<cstdlib>
#include<locale.h>
#include<vector>
#include<stdlib.h>

using namespace std;

struct Cliente
{
    string nome = " ";
    string genero = " ";
    string motivacao = " ";
    string peso = " ";
    string altura = " ";
    string idade = " ";

};

struct Consulta
{
    string data = " ";
    string horario = " ";
    string duracao = " ";
    string tipo = " ";
    //tipo diz respeito a ser presencial ou remota

};

void salvaDados(vector<Cliente> Ct , vector<Alimentacao> A , vector<Consulta> Co , vector<Meta> M){
    ofstream arquivo;
    arquivo.open("dados.txt", ios::app );
    for(int i = 0; i < Ct.size(); i++){
        arquivo << Ct[i].nome << "," << Ct[i].peso
         << "," << Ct[i].idade << ","
         << Ct[i].altura << "," << Ct[i].genero << "," << Ct[i].motivacao << ",";
    }

    for(int i = 0; i < A.size(); i++){
        arquivo << A[i].cafemanha << "," << A[i].lanchemanha
         << "," << A[i].almoco << ","
         << A[i].lanchetarde << "," << A[i].janta << "," << A[i].ceia << ",";
    }

    for(int i = 0; i < Co.size(); i++){
        arquivo << Co[i].data << "," << Co[i].horario
         << "," << Co[i].duracao << ","
         << Co[i].tipo << ",";
    }

    for(int i = 0; i < M.size(); i++){
        arquivo << M[i].objetivo << "," << M[i].evolucao
         << "," << M[i].resultado << endl;
    }

    arquivo.close();
}

void alteraAlimentacao(string nome , vector<Cliente> Ct , vector<Alimentacao> A , vector<Consulta> Co , vector<Meta> M){

    int aux;

    ofstream arquivoS;
    arquivoS.open("dados.txt");
    for(int i = 0; i < Ct.size(); i++){

        if (Ct[i].nome == nome)
        {
            aux = i;
        }else{
            system("cls");
            cout << "Cliente não encontrado, favor verificar ortografia!" << endl;
            exit;
        }
    }

    system("cls");

    cout << "\t--Ficha de Alimentação--" << endl << endl
     << "Café da manhã: ";
    cin >> A[aux].cafemanha;
    cout << endl << "Lanche da Manha: ";
    cin >> A[aux].lanchemanha;
    cout << endl << "Almoço: ";
    cin >> A[aux].almoco;
    cout << endl << "Lanche da Tarde: ";
    cin >> A[aux].lanchetarde;
    cout << endl << "Janta: ";
    cin >> A[aux].janta;
    cout << endl << "Ceia: ";
    cin >> A[aux].ceia;

    system("cls");

    for(int i = 0; i < Ct.size(); i++){
        arquivoS << Ct[i].nome << "," << Ct[i].peso
         << "," << Ct[i].idade << ","
         << Ct[i].altura << "," << Ct[i].genero << "," << Ct[i].motivacao << ",";
    }

    for(int i = 0; i < A.size(); i++){
        arquivoS << A[i].cafemanha << "," << A[i].lanchemanha
         << "," << A[i].almoco << ","
         << A[i].lanchetarde << "," << A[i].janta << "," << A[i].ceia << ",";
    }

    for(int i = 0; i < Co.size(); i++){
        arquivoS << Co[i].data << "," << Co[i].horario
         << "," << Co[i].duracao << ","
         << Co[i].tipo << ",";
    }

    for(int i = 0; i < M.size(); i++){
        arquivoS << M[i].objetivo << "," << M[i].evolucao
         << "," << M[i].resultado << endl;
    }

    arquivoS.close();

}

void alteraMeta(string nome , vector<Cliente> Ct , vector<Alimentacao> A , vector<Consulta> Co , vector<Meta> M){

    int aux;

    ofstream arquivoS;
    arquivoS.open("dados.txt");
    for(int i = 0; i < Ct.size(); i++){

        if (Ct[i].nome == nome)
        {
            aux = i;
        }else{
            system("cls");
            cout << "Cliente não encontrado, favor verificar ortografia!" << endl;
            exit;
        }
    }

    system("cls");

    cout << "\t--Meta--" << endl << endl
     << "Objetivo: ";
    cin >> M[aux].objetivo;
    cout << endl << "Evolução: ";
    cin >> M[aux].evolucao;
    cout << endl << "Resultado: ";
    cin >> M[aux].resultado;

    system("cls");

    for(int i = 0; i < Ct.size(); i++){
        arquivoS << Ct[i].nome << "," << Ct[i].peso
         << "," << Ct[i].idade << ","
         << Ct[i].altura << "," << Ct[i].genero << "," << Ct[i].motivacao << ",";
    }

    for(int i = 0; i < A.size(); i++){
        arquivoS << A[i].cafemanha << "," << A[i].lanchemanha
         << "," << A[i].almoco << ","
         << A[i].lanchetarde << "," << A[i].janta << "," << A[i].ceia << ",";
    }

    for(int i = 0; i < Co.size(); i++){
        arquivoS << Co[i].data << "," << Co[i].horario
         << "," << Co[i].duracao << ","
         << Co[i].tipo << ",";
    }

    for(int i = 0; i < M.size(); i++){
        arquivoS << M[i].objetivo << "," << M[i].evolucao
         << "," << M[i].resultado << endl;
    }

    arquivoS.close();

}

int main()
{
	setlocale(LC_ALL , "Portuguese");

    int aux;
    vector<Cliente> Ct;
    vector<Alimentacao> A;
    vector<Consulta> Co;
    vector<Meta> M;

    do{
        cout << "\t-- Clinica de Nutrição --\n" << endl
        << "1 - Preencher dados" << endl << "2 - Carregar dados"
        << endl << "3 - Salvar dados" << endl << "4 - Alterar (Ficha de Alimentação)"
        << endl << "5 - Alterar (Meta)" << endl << "6 - Ver metas" << endl << "0 - SAIR" << endl << endl << "Digite: ";

        cin >> aux;
        
        system("cls");

    }while (aux != 0);

	system ("pause");
	return 0;
}
