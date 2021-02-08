typedef struct fila Fila;

Fila* criarFila();
int enfileirar(int num, Fila *fi);
int desenfileirar(Fila *fi);
void exibirFila(Fila *fi);
void excluirFila(Fila **fi);
int filaVazia(Fila *fi);