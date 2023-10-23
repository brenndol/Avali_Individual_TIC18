#include <iostream>
#include <vector>

using namespace std;

class Paciente {
    string cpf;
    string dtNascimento;
    
    public:
    string nome;

    Paciente(string _nome, string _cpf, string _dtNascimento) {
        this-> nome = _nome;
        this-> setCpf(_cpf);
        this-> setDtNascimento(_dtNascimento);
    }

    string getCpf() {
        return this-> cpf;
    }

    void setCpf(string _cpf) {
       
       this-> cpf = _cpf;

    }

    string getDtNascimento() {
        return this-> dtNascimento;
    }

    void setDtNascimento(string _dtNascimento) {
        
    this->dtNascimento = _dtNascimento;
    }

};

class Medico {
  
  public:
    string nomeMed;
    string espec;
    string crm;

    Medico(string _crm, string _nomeMed, string _espec) {
        this-> nomeMed = _nomeMed;
        this-> setCrm(_crm);
        this-> setEspec(_espec);
    }

    string getCrm() {
        return this->crm;
    }

    void setCrm(string _crm) {
       this-> crm = _crm;
    }

    string getNomeMed() {
        return this-> nomeMed;
    }

    void setNomeMed(string _nomeMed) {
        this->nomeMed = _nomeMed;
    }

    string getEspec() {
        return this-> espec;
    }

    void setEspec(string _espec) {
        this-> espec = _espec;
    }

};


int localizaCpf(vector <Paciente*> pacientes, string cpf) {
    int i=0;
    for(auto el : pacientes) {
        if(el-> getCpf() == cpf) {
            return i;

    }
        i++;
    }

    return -1;

}

int localizaCrm(vector <Medico*> medicos, string crm){
    int i=0;
    for(auto el : medicos){
        if(el-> getCrm() == crm){
            return i;
    }
        i++;
    }

    return -1;
}


int main() {
    int opcaoPrincipal;
    int opcao;
    vector <Paciente*> listaPaciente;
    vector <Medico*> listaMedicos;

    do {
        cout << "INFORME A OPCAO 0 // 2: " << endl;
        cout << "1 - PACIENTE " << endl;
        cout << "2 - MEDICO " << endl;
        cin >> opcaoPrincipal; 
     
    if (opcaoPrincipal == 1){

      
    do {
        cout << "----- OPCOES ------ (0-5):" << endl;
        cout << " 1-INCLUIR " << endl;
        cout << " 2-EXCLUIR (por CPF) " << endl;
        cout << " 3-ALTERAR (por CPF) " << endl;
        cout << " 4-LISTAR " << endl;
        cout << " 5-LOCALIZAR (por CPF) " << endl;
        cout << " 0- SAIR" << endl;
        cin >> opcao;


        string auxNome, auxCpf, auxDtNasc;
        if(opcao == 1){
       
            cout << "Informe o nome: " ;
            getline(cin >> ws,auxNome);
            
            cout << "Informe o CPF: " ;
            getline(cin >> ws,auxCpf);
        
            cout << "Informe a Data de Nascimento: " ;
            getline(cin >> ws,auxDtNasc);

        int posicao = localizaCpf(listaPaciente, auxCpf);

        if(posicao < 0){
        Paciente *paciente =  new Paciente(auxNome, auxCpf, auxDtNasc);
            
            listaPaciente.push_back(paciente);
        }

        else{
            cout << "PACIENTE JA INSERIDO" << endl;
        }
        
        }  

        else if(opcao == 2){
            cout << "INFORME O CPF DO PACIENTE QUE DESEJA EXLUIR: ";
            getline (cin >> ws, auxCpf); 
            
            int posicao = localizaCpf(listaPaciente, auxCpf);


            if (posicao < 0)
            cout << "PACIENTE NAO ENCONTRADO" << endl;
            
            else {
                listaPaciente.erase(listaPaciente.begin() + posicao);
            }
        }

            else if(opcao == 3){
            cout << "INFORME O CPF DO PACIENTE QUE DESEJA ALTERAR: ";
            getline (cin >> ws, auxCpf); 
            
            int posicao = localizaCpf(listaPaciente, auxCpf);

            if (posicao < 0)
                cout << "PACIENTE NAO ENCONTRADO" << endl;
            
            else{
                int escolha;
                string novoNome;
                string novaData;
                
                cout << "NOME: " << listaPaciente[posicao]-> nome << endl;
                cout << "CPF: " << listaPaciente[posicao]-> getCpf() << endl;
                cout << "DATA de NASCIMENTO: " << listaPaciente[posicao]-> getDtNascimento() << endl;

                cout << "DESEJA ALTERAR O NOME DO PACIENTE? 1- SIM // 2- NAO" << endl;
                cin >> escolha;

            if(escolha == 1){
                cout << "INFORME O NOME DO PACIENTE: " << endl;
                getline (cin >> ws, novoNome);
                listaPaciente[posicao]-> nome = novoNome;
        } 
                cout << "DESEJA ALTERAR A DATA DE NASCIMENTO? SIM 1- // 2- NAO" << endl;
                cin >> escolha;  

            if (escolha ==1){
                cout << " INFORME A DATA DE NASCIMENTO: " << endl;
                getline (cin >> ws, novaData); listaPaciente[posicao]-> setDtNascimento(novaData);
            }
        
        }

        }
            else if(opcao == 4){
            for(auto el : listaPaciente) {
                cout << el->nome << endl;
                cout << el->getCpf() << endl;
                cout << el->getDtNascimento() << endl;
                cout << endl;
        }
        }
        else if(opcao == 5){
            cout << "INFORME O CPF DO PACIENTE QUE DESEJA LOCALIZAR: ";
            getline(cin >> ws, auxCpf);

            int posicao = localizaCpf(listaPaciente, auxCpf);

            if (posicao < 0)
            cout << "PACIENTE NAO ENCONTRADO" << endl;

            else {
                cout << listaPaciente.at(posicao)->nome << endl;
        }
        }
      
        else {
            cout << "OPÇAO INVALIDA" << endl;
        }
        
        }
        while (opcao !=0); 
        
        }
        
        else if (opcaoPrincipal == 2){

            do {
                cout << "----- OPCOES ----- (0-5): " << endl;
                cout << "1-INCLUIR " << endl;
                cout << "2-EXCLUIR (por CRM) " << endl;
                cout << "3-ALTERAR (por CRM) " << endl;
                cout << "4-LISTAR " << endl;
                cout << "5-LOCALIZAR por (CRM) " << endl;
                cout << "0- SAIR" << endl;
                cin >> opcao;

           
            if (opcao == 1){
                 string auxNomeMed, auxCrm, auxEspec;
                cout << "INFORME O NOME: ";
                getline (cin >> ws, auxNomeMed);

                cout << "INFORME O CRM: ";
                getline (cin >> ws, auxCrm);

                cout << "INFORME A SUA ESPECIALIDADE: ";
                getline (cin >> ws, auxEspec);

                int posicao = localizaCrm (listaMedicos, auxCrm);

                if (posicao < 0) {
                    Medico *medico = new Medico (auxNomeMed, auxCrm, auxEspec);
                    listaMedicos.push_back(medico);
                }

                else {
                    cout << "MEDICO JA INSERIDO! " << endl;
                }
            }

            else if(opcao == 2) {
                 string auxNomeMed, auxCrm, auxEspec;
                cout << "INFORME O CRM DO MEDICO QUE DESEJA EXCLUIR:";
                getline (cin >> ws, auxCrm);

                int posicao = localizaCrm (listaMedicos, auxCrm);

                if (posicao < 0)
                  cout << "PACIENTE NAO ENCONTRADO!" << endl;
                
                else {
                    listaMedicos.erase(listaMedicos.begin() + posicao);
                }
            }

            else if (opcao == 3) {
                string auxCrm;
                cout << "INFORME O CRM DO MEDICO QUE DESEJA ALTERAR: ";
                getline (cin >> ws, auxCrm);

                int posicao = localizaCrm(listaMedicos, auxCrm);
                if (posicao < 0)
                    cout << "MEDICO NAO ENCONTRADO!" << endl;
                
                else {
                   int escolha;
                   string novoNomeMed;
                   string novaEspec;
                   
                    cout << "NOME:" << listaMedicos[posicao]-> nomeMed << endl;
                    cout << "CRM:" << listaMedicos[posicao]-> getCrm() << endl;
                    cout << "ESPECIALIZAÇAO:" << listaMedicos[posicao]-> getEspec() << endl;

                    cout << "DESEJA ALTERAR O MEDICO? 1- SIM // 2- NAO" << endl;
                    cin >> escolha;

                    if (escolha == 1) {
                        cout << "INFORME O CRM: " << endl;
                        getline (cin >> ws, novoNomeMed);
                        listaMedicos[posicao]-> nomeMed = novoNomeMed;
            }

                   cout << "DESEJA ALTERAR A ESPECIALIZAÇAO? 1- SIM // 2- NAO " << endl;
                   cin >> escolha;

                   if (escolha == 1){
                       cout << "INFORME A ESPECIALIZAÇAO " << endl;
                       getline (cin >> ws, novaEspec);
                       listaMedicos[posicao]-> setEspec(novaEspec);
                   } 
                   
            }
            }
                else if (opcao == 4) {
                    for(auto el : listaMedicos){
                        cout << el->nomeMed << endl;
                        cout << el->crm << endl;
                        cout << el->espec << endl;
                        cout << endl;
                    }
            }

                else if (opcao ==5) {
                     string auxNomeMed, auxCrm, auxEspec;
                    cout << "INFORME O CRM DO MEDICO QUE DESEJA LOCALIZAR: ";
                    getline (cin >> ws, auxCrm);

                    int posicao = localizaCrm (listaMedicos, auxCrm);

                    if (posicao < 0)
                         cout << "MEDICO NAO ENCONTRADO" << endl;

                    else {
                        cout << listaMedicos.at(posicao)->nomeMed << endl;
                    }
                }
                    
                else if (opcao == 0) {}

                else {
                    cout << "OPÇAO INVALIDA" << endl;
                }

            }   
               while (opcao != 0);

            }else if(opcaoPrincipal == 0){
                break;
            }

            }while (opcaoPrincipal != 0);

              return 0;


        }