#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gera(int *, int);
void exibe(char* , int *, int);
void bubble(int *, int, int *, int *);
void insertion(int *, int, int *, int *);
void selection(int *, int, int *, int *);
int soma(int *, int);
float media(int *, int);
int main(){
    int *v, n;
    int trocas, comparacoes;
    long int ini, fim;
    //inicializando o gerador
    srand(time(0));
    printf("Escolha um tamanho para o vetor, 0 encerra:\n");
    scanf("%d", & n);
   
    //repetir tamanho maior que 0 
        while(n > 0){

        //alocar um vetor dinamicamente, do tamanho que o usuário quiser
        v = (int *) malloc (n * sizeof(int));
    
    
        // gerar randomicamente os valores para o vetor
        gera( v, n);
        trocas = 0;
        comparacoes =0;
        //exibir
        exibe("Vetor gerado",v, n);
        //bubble
            ini = time(0);
            bubble(v, n, &trocas, &comparacoes);
            fim = time(0);
        //insertion
            //ini = time(0);
            //insertion(v, n, & comparacoes, & trocas);
            //fim = time(0);
        //selection
            //ini = time(0);
            //selection(v, n, & comparacoes, & trocas);
            //fim = time(0);
        //exibir
        exibe("Vetor ordenado", v, n);
        printf("\nTempo para tamanho %d: %ld", n, fim-ini);
        printf("\nforam realizadas %d comparacoes e %d trocas", comparacoes, trocas);
        
        //somar
        printf("\na soma dos vetores é de: %d\n", soma(v, n));
        //media
        printf("\na media é de: %f\n", media(v, n));
        //Liberar memória
        free(v);
        //ler novo tamanho
        printf("\nEscolha um tamanho para o vetor, 0 encerra:\n");
        scanf("%d", &n);

    }

    return 0;
}
void gera(int *v, int n){
int i;
for ( i = 0; i < n; i++)
{
    v[i] = rand() % (n*10);
}

}
void exibe(char *msg,int *v, int n){
int i;
printf("\n%s\n", msg);
for (i = 0; i < n; i++)
{
    printf("%d ", v[i]);
}
printf("\n");
}

void bubble(int *v, int n, int * trocas, int *comparacoes){
int i, j, aux  = 0 ;
for ( i = 1; i < n; i++)
{
    for ( j = 0; j < (n - i); j++)
    {
        // contar comparações
        *comparacoes = *comparacoes + 1;
        if (v[j] > v[j + 1]) //troca
        {
            //contar trocas
            *trocas = *trocas + 1;
            aux = v[j];
            v[j] = v[j + 1];
            v[j + 1] = aux;
        }        
    }    
}
}
void insertion(int *v,int n, int *comparacoes, int * trocas){
int i, j, aux;
   
    for (i = 1; i < n; i++)
    { 
        *comparacoes = *comparacoes  + 1;
        aux = v[i];
        for(j = i -1; j >= 0 && v[j] > aux; j--){
            *trocas = *trocas + 1;
            v[ j + 1] = v[j];
        }          
    v[j + 1] = aux;
    }              
}
void selection(int *v,int n,int *comparacoes, int *trocas){
    int i, j, aux, i_min;
    for (i = 0; i < n - 1; i++)
    {
        *comparacoes = *comparacoes + 1;
        i_min = i;
        for (j = i + 1; j < n; j++)
        {
            *trocas = *trocas + 1;
            if(v[j] < v[i_min]){
                i_min = j;
            }  
        }
        aux = v[i];
        v[i] = v[i_min];
        v[i_min] = aux;
    }
}
int soma(int *v,int n){
    int i, s;
    for(i = 0, s = 0; i < n; s += v[i++]);
    return s;
}
float media(int *v, int n) {
    float s;
    s = (float) soma(v,n)/n;
    return s;
}