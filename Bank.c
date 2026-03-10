#include <stdio.h>
#include <windows.h>

#define max_users 10
int loggedUser = -1;

//Cria a struct de usuários;
struct user {
    int id, senha, idade;
    char nome[30];
    float saldo;
};
struct user users[max_users];
int totalusers = 0;
int opcao;

//Função de cadastro
void cadastro(){
    //Cria um novo usuario pra storar em users;
 struct user new;
 new.id = totalusers + 1;
    printf("-=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=-");
    printf("\n");
    printf("CADASTRO BANCARIO\n");
    printf("Digite seu nome: \n");
    scanf("%s", new.nome);
    printf("Digite sua idade: \n");
    scanf("%d", &new.idade);
    printf("Crie uma senha com 4 numeros: \n");
    scanf("%d", &new.senha);
    if (new.idade < 18){
        printf("Voce precisa ter 18 anos ou mais para criar uma conta.");
    }
    new.saldo = 0;
    Sleep(10);
    

    users[totalusers] = new;
    totalusers++;
    if(totalusers >= max_users){//Prevenção contra criação de mais de 10 Usuarios;
        printf("Nao foi possivel fazer o cadastro. Total de usuarios atingido!");
    }
    printf("Cadastro feito, seu id e %d . Use-o para logar no banco.", new.id);

}

//Menu de login criado em int para retornar um valor
int login(){
    int id_login, senha_login;
    printf("-=--=--=--=--=--=--=--=--=--=-Menu de login-=--=--=--=--=--=--=--=--=--=\n");
    printf("Digite seu id: \n");
    scanf("%d", &id_login);
    printf("Digite sua senha:\n");
    scanf("%d", &senha_login);
    Sleep(10);

for(int i = 0; i < totalusers; i++){
    if(senha_login == users[i].senha && id_login == users[i].id){//Aqui o if compara se a senha e id digitados conferem com a de algum usuario;
        printf("Login bem sucedido!! Bem vindo %s \n", users[i].nome);
        return i;//E retorna a posição dele
    }}
    printf("Id ou senha incorretos, tente novamente!\n");
    return -1;  
}


//Função de depósito;
void deposit(){
    float valor;
    printf("-=--=--=--=--=--=--=--=--=--=- Deposito -=--=--=--=--=--=--=--=--=--=\n");
   
    printf("Digite a quantidade que deseja depositar: \n");
    scanf("%f", &valor);
    Sleep(1000);
    users[loggedUser].saldo = users[loggedUser].saldo + valor;//Diferente de somente atribuir o valor depositado ao saldo, se não ia sobrescrever ao invés de somar;
    printf("Deposito realizado com sucesso, saldo total: %.2f R$ \n", users[loggedUser].saldo);
}
//Função de saque
void withdraw(){
    float amount;
    printf("-=--=--=--=--=--=--=--=--=--=- Menu de Saque -=--=--=--=--=--=--=--=--=--=\n");
  
            printf("Digite a quantidade que deseja sacar: \n");
            scanf("%f", &amount);
            Sleep(1000);
            if (users[loggedUser].saldo < amount){
                printf("Saldo insuficiente para realizar operacao.");
            } else {
                users[loggedUser].saldo = users[loggedUser].saldo - amount;//Mesma lógica do depósito, não faz sentido sobrescrever, tendo somente que diminuir;
                printf("Saque realizado com sucesso, valor restante %.2f", users[loggedUser].saldo);
            }
    
}
//Checa o saldo total do usuario logado;
void checkbalance(){
    printf("Saldo total disponivel:R$ %.2f \n",users[loggedUser].saldo);
}

//Menu de usuario para depois do login;
void usermenu(){
    int user_opcao;

    while(1){

        printf("\n *** Menu do usuario ***\n");
        printf("1. Deposito \n2. Sacar \n3. Saldo \n0. Logout \n");
        scanf("%d", &user_opcao);
        Sleep(1000);
        
        switch(user_opcao){
            case 1:
                deposit();
                Sleep(1000);
            break;

            case 2:
                withdraw();
                Sleep(1000);
            break;

            case 3:
                checkbalance();
                Sleep(1000);
            break;
            case 0:
                return;
            default:
            printf("Opcão inválida\n");
        }
    }
}

//Função main
int main(){
    while(!0){
        printf("\n === Banco === \n");
        printf("1. Cadastrar \n2. Login \n0. Sair \n");
        scanf("%d", &opcao);
        Sleep(1000);
        

        switch(opcao){
            case 1: 
                cadastro();
                Sleep(1000);
            break;

            case 2:
                loggedUser = login();
                if (loggedUser != -1){//Para checar se o logged user não é invalido
                usermenu();}
                Sleep(1000);
            break;

            case 0:
                return 0;
            break;

            default:
            printf("Opção inválida\n");


        }


    }
}
