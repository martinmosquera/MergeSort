#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int* v,int n);

void mergeSort_ordena(int* v,int esq,int dir);

void merge(int* v,int esq,int meio,int dir);

int* new_vetor(int tam){
    int* vet;
    vet = (int *)malloc(sizeof(int) * tam);
    return vet;
}

int main(){
    int i;
    int tam =0;
    int *vetor;
    printf("Digita o tamanho do vetor: ");
    scanf("%d",&tam);

    vetor = new_vetor(tam);
    srand(time(NULL));
    for(i=0;i<tam;i++){
        vetor[i] = rand() % 100;
    }

    for(i = 0; i<tam;i++){
        printf("- %d: %d \n",i+1,vetor[i]);
    }

    mergeSort(vetor,tam);

    for(i = 0; i<tam;i++){
        printf("- %d: %d\n",i+1,vetor[i]);
    }

}


void mergeSort(int* v,int n){
    mergeSort_ordena(v,0,n-1);
}

void mergeSort_ordena(int* v,int esq,int dir){
    if(esq == dir) return;

    int meio = (esq+dir)/2;
    mergeSort_ordena(v,esq,meio);
    mergeSort_ordena(v,meio+1,dir);
    merge(v,esq,meio,dir);
}

void merge(int* a,int l,int m,int r){
    int i,j,k, *aux;
    aux = (int *)malloc(sizeof(int) * r+1);

    for(i=m+1;i>l;i--) aux[i-1] = a[i-1];
    for(j=m;j<r;j++) aux[r+m-j] = a[j+1];

    for(k=l;k<=r;k++)
        if(aux[j] < aux[i]) a[k] = aux[j--];
        else a[k] = aux[i++];
}