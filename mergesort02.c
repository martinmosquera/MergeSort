#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int* v,int* aux,int n);

void mergeSort_ordena(int* v,int* aux,int esq,int dir);

void merge(int* v,int*aux,int esq,int meio,int dir);

void insertion_sort(long int * v, long int n);

int* new_vetor(int tam);

int main(){
    int i;
    int tam =0;
    int *vetor,*aux;
    printf("Digita o tamanho do vetor: ");
    scanf("%d",&tam);

    vetor = new_vetor(tam);
    aux = new_vetor(tam);
    srand(time(NULL));
    for(i=0;i<tam;i++){
        vetor[i] = rand() % 100;
        aux[i] = vetor[i];
    }

    for(i = 0; i<tam;i++){
        printf("- %d: %d \n",i+1,vetor[i]);
    }

    mergeSort(vetor,aux,tam);
  
    for(i = 0; i<tam;i++){
        printf("- %d: %d\n",i+1,vetor[i]);
    }

}


void mergeSort(int* v,int* aux,int n){
    mergeSort_ordena(v,aux,0,n-1);
}

void mergeSort_ordena(int* v,int* aux,int esq,int dir){
    if(esq == dir) return;
    int meio = (esq+dir)/2;
    if(v[esq] <= v[esq+1] && dir-esq ==1){
         merge(v,aux,esq,meio,dir);
    }
    if(dir<10){
        insertion_sort(v,dir);
        merge(v,aux,esq,meio,dir);
    } 
    mergeSort_ordena(v,aux,esq,meio);
    mergeSort_ordena(v,aux,meio+1,dir);
    if(v[meio] <= v[meio+1]) return;
    merge(v,aux,esq,meio,dir);
}

void merge(int* a,int* aux,int l,int m,int r){
    int i,j,k;
    
    for(i=m+1;i>l;i--) aux[i-1] = a[i-1];
    for(j=m;j<r;j++) aux[r+m-j] = a[j+1];

    for(k=l;k<=r;k++)
        if(aux[j] <= aux[i]) a[k] = aux[j--];
        else a[k] = aux[i++];
}

void insertion_sort(long int * v, long int n){
  long int i, j, aux, x;
	
	for(i=+1; i<n; i++){
		x = v[i];
		j = i;
		while(x < v[j-1] && j > 0){
			v[j] = v[j-1];
			j--;
		}
		v[j] = x;
	}
}


int* new_vetor(int tam){
    int* vet;
    vet = (int *)malloc(sizeof(int) * tam);
    return vet;
}