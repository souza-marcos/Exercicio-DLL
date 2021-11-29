#include <iostream>
#include <string.h>
#include "doubly_linkedlist.cpp"
using namespace std;

struct TrabalhoAca
{
    int cod;
    string titulo;
    string descricao;
    string dataEntrega;
};

void menu();
void inserirTrabalho();
void removerTrabalho();
void navegarTrabalhos();
void pesquisarTrabalho();
void imprimirTrabalho();

bool compareCodigo(TrabalhoAca t, int cod)
{
    return (t.cod == cod);
}
bool compareTitulo(TrabalhoAca t, string titulo)
{
    return (strcmpi(t.titulo.data(), titulo.data()) == 0);
}
void printTrabalho(TrabalhoAca t)
{
    cout << "\n______________";
    cout << "\nCODIGO: " << t.cod;
    cout << "\nTITULO: " << t.titulo;
    cout << "\nDESCRICAO: " << t.descricao;
    cout << "\nDATA ENTREGA: " << t.dataEntrega;
    cout << "\n______________";
}

DoublyLinkedList<TrabalhoAca> *list;

int main()
{

    list = create<TrabalhoAca>();
    menu();
    return 0;
}

void menu()
{
    int option;
    do
    {
        system("cls");
        cout << "MENU PRINCIPAL\n";
        cout << "(1) - Inserir novo trabalho.\n";
        cout << "(2) - Remover trabalho.\n";
        cout << "(3) - Navegar pelos trabalhos.\n";
        cout << "(4) - Pesquisar um trabalho.\n";
        cout << "(5) - Imprimir todos os trabalhos.\n";
        cout << "(0) - Sair. \n";
        cout << "Sua Opcao: ";
        cin >> option;
        system("cls");

        switch (option)
        {
        case 1:
            inserirTrabalho();
            break;

        case 2:
            removerTrabalho();
            break;

        case 3:
            navegarTrabalhos();
            break;

        case 4:
            pesquisarTrabalho();
            break;

        case 5:
            imprimirTrabalho();
            break;
        default:
            break;
        }
        cout << endl;
        system("pause");
    } while (option != 0);
}

void inserirTrabalho()
{
    system("cls");
    TrabalhoAca t;
    cout << "Digite o codigo: ";
    cin >> t.cod;
    cout << "Digite o titulo: ";
    cin.ignore();
    getline(cin, t.titulo);
    cout << "Digite a descricao: ";
    getline(cin, t.descricao);
    cout << "Digite a data de entrega: ";
    getline(cin, t.dataEntrega);
    insertBack(t, list);
}

void removerTrabalho()
{
    system("cls");
    cout << "\n(1) - Remover o primeiro\n";
    cout << "(2) - Remover o ultimo\n";
    cout << "(3) - Remover por codigo\n";
    cout << "(0) - Voltar ao menu principal\n";
    int option;
    cin >> option;
    NodeDLL<TrabalhoAca> *node;
    switch (option)
    {
    case 1:
        node = list->head;
        break;
    case 2:
        node = list->last;
        break;
    case 3:
        cout << "Digite o codigo do trabalho a ser excluido: ";
        int cod;
        cin >> cod;
        node = searchItem(list, cod, compareCodigo);
        break;
    default:
        return;
    }
    deleteItem(list, node);
}

void navegarTrabalhos()
{
    int option = 1;
    NodeDLL<TrabalhoAca> *node = list->head;
    if(node == NULL){
        cout << "Nenhum trabalho cadastrado!\n";
        return;
    }
    while (option != 0)
    {
        system("cls");
        printTrabalho(node->data);
        cout << endl;
        if (node->prev != NULL)
        {
            cout << "<-- (1)            ";
        }
        cout << "(0)SAIR        ";
        if (node->next != NULL)
        {
            cout << "(2) -->";
        }
        cout << "\n Sua opcao: ";
        cin >> option;
        if (option == 1 && node->prev != NULL)
        {
            node = node->prev;
        }
        else if (option == 2 && node->next != NULL)
        {
            node = node->next;
        }
    }
}

void pesquisarTrabalho()
{
    system("cls");
    cout << "\n(1) - Pesquisar por codigo\n";
    cout << "(2) - Pesquisar por nome\n";
    cout << "(0) - Voltar ao menu principal\n";
    int option;
    cin >> option;
    NodeDLL<TrabalhoAca> *node;
    if (option == 1)
    {
        cout << "Digite o codigo: ";
        int cod;
        cin >> cod;
        node = searchItem(list, cod, compareCodigo);
    }
    else if (option == 2)
    {
        cout << "Digite o nome: ";
        string nome;
        cin.ignore();
        getline(cin, nome);
        node = searchItem(list, nome, compareTitulo);
    }
    else
    {
        return;
    }
    if(node == NULL){
       cout << "\nNao encontrado!\n";
       return; 
    }
    printTrabalho(node->data);
}

void imprimirTrabalho()
{
    printList(list, printTrabalho);
}