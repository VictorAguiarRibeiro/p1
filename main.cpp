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

struct Meta
{
    string objetivo = " ";
    string evolucao = " ";
    string resultado = " ";

};

struct Alimentacao
{
    string cafemanha = " ";
    string lanche1 = " ";
    string almoco = " ";
    string lanche2 = " ";
    string janta = " ";
    string ceia = " ";
};

void split(string linha, char at, string S[])
{
    int pos = 0, fim, i=0;

    do
    {
        fim=linha.find(at, pos);
        if (fim == -1) // Ultimo campo
            S[i] = linha.substr(pos);
        else // Primeiro ao penúltimo campo
        {
            S[i++] = linha.substr(pos, fim - pos);
            pos = fim+1;
        }
    } while (fim != -1);
}

void carregaDados(vector<Cliente>&Ct , vector<Alimentacao>&A , vector<Consulta>&Co , vector<Meta>&M)
{
    string linha;
    ifstream arquivo;
    Cliente ct;
    Alimentacao a;
    Consulta co;
    Meta m;

    arquivo.open("dados.txt");
    if (arquivo.is_open()){
        while (getline (arquivo,linha)){
             cout << linha << '\n';
             string S[18];
             split(linha, ',', S);
             ct.nome = S[0];
             ct.peso = S[1];
             ct.idade = S[2];
             ct.altura = S[3];
             ct.genero = S[4];
             ct.motivacao = S[5];
             a.cafemanha = S[6];
             a.lanchemanha = S[7];
             a.almoco = S[8];
             a.lanchetarde = S[9];
             a.janta = S[10];
             a.ceia = S[11];
             co.data = S[12];
             co.horario = S[13];
             co.duracao = S[14];
             co.tipo = S[15];
             m.objetivo = S[16];
             m.evolucao = S[17];
             m.resultado = S[18];

             Ct.push_back(ct);
             A.push_back(a);
             Co.push_back(co);
             M.push_back(m);
        }
        arquivo.close();
    } else {
    cout << "Não foi possível abrir o arquivo!!!";
    }
}

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

void verMeta(string nome , vector<Cliente> Ct , vector<Alimentacao> A , vector<Consulta> Co , vector<Meta> M){

    int aux;

    ofstream arquivoS;
    arquivoS.open("dados.txt");
    for(int i = 0; i < Ct.size(); i++){

        if (Ct[i].nome == nome)
        {
            system("cls");

            cout << "Objetivo: " << M[aux].objetivo << endl
            << "Evolução: " << M[aux].evolucao << endl
            << "Resultado: " << M[aux].resultado << endl;


        }else{
            system("cls");
            cout << "Cliente não encontrado, favor verificar ortografia!" << endl;
            exit;
        }
    }

}

void preencheDados()
{
    setlocale(LC_ALL , "Portuguese");
    system("cls");

    Cliente ct;
    Alimentacao a;
    Consulta co;
    Meta m;

    cout << "\t--Insira os dados do Cliente--" << endl << endl
     << "Nome: ";
    cin >> ct.nome;
    cout << endl << "Peso: ";
    cin >> ct.peso;
    cout << endl << "Idade: ";
    cin >> ct.idade;
    cout << endl << "Altura: ";
    cin >> ct.altura;
    cout << endl << "Gênero: ";
    cin >> ct.genero;
    cout << endl << "Motivação: ";
    cin >> ct.motivacao;

    system("cls");

    cout << "\t--Ficha de Alimentação--" << endl << endl
     << "Café da manhã: ";
    cin >> a.cafemanha;
    cout << endl << "Lanche da Manha: ";
    cin >> a.lanchemanha;
    cout << endl << "Almoço: ";
    cin >> a.almoco;
    cout << endl << "Lanche da Tarde: ";
    cin >> a.lanchetarde;
    cout << endl << "Janta: ";
    cin >> a.janta;
    cout << endl << "Ceia: ";
    cin >> a.ceia;

    system("cls");

    cout << "\t--Insira os dados da Consulta--" << endl << endl
     << "Data: ";
    cin >> co.data;
    cout << endl << "Horário: ";
    cin >> co.horario;
    cout << endl << "Duração: ";
    cin >> co.duracao;
    cout << endl << "Tipo: ";
    cin >> co.tipo;

    system("cls");

    cout << "\t--Meta--" << endl << endl
     << "Objetivo: ";
    cin >> m.objetivo;
    cout << endl << "Evolução: ";
    cin >> m.evolucao;
    cout << endl << "Resultado: ";
    cin >> m.resultado;

    system("cls");

    ofstream arquivo;
    arquivo.open("dados.txt", ios::app );

    arquivo << ct.nome << "," << ct.peso
         << "," << ct.idade << ","
         << ct.altura << "," << ct.genero << "," << ct.motivacao << ","
         << a.cafemanha << "," << a.lanchemanha
         << "," << a.almoco << ","
         << a.lanchetarde << "," << a.janta << "," << a.ceia << ","
         << co.data << "," << co.horario
         << "," << co.duracao << ","
         << co.tipo << ","
         << m.objetivo << "," << m.evolucao
         << "," << m.resultado << endl;

    arquivo.close();
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

        switch(aux)
        {
        case 1:
            {
                preencheDados();
            }break;
        case 2:
            {
                carregaDados(Ct , A , Co, M);
            }break;
        case 3:
            {
                salvaDados(Ct , A , Co, M);
            }break;
        case 4:
            {
                system("cls");
                string nometroca;
                cout << "Digite o nome do cliente: ";
                cin >> nometroca;

                carregaDados(Ct , A , Co, M);
                alteraAlimentacao(nometroca , Ct , A , Co , M);

            }break;
        case 5:
            {
                system("cls");
                string nometroca;
                cout << "Digite o nome do cliente: ";
                cin >> nometroca;

                carregaDados(Ct , A , Co, M);
                alteraMeta(nometroca , Ct , A , Co , M);

            }break;
        case 6:
            {
                system("cls");
                string nometroca;
                cout << "Digite o nome do cliente: ";
                cin >> nometroca;

                carregaDados(Ct , A , Co, M);
                verMeta(nometroca , Ct , A , Co , M);

            }
        }

        system("cls");

    }while (aux != 0);

	system ("pause");
	return 0;
}
