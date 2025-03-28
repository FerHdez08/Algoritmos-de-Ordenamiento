#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>

#define TAM_MAXIMO 1000
#define TAM_MINIMO 10
#define INCREMENTO 10
#define VECES 1000
#define NUM_ALGORITMOS 7

using namespace std;

int aleatorio(int inicio, int fin);

void swap(int *a, int *b);

void copia(int generar_conjunto[], int copia_conjunto[], int TAM);

void insercion(int generar_conjunto[], int TAM);

void burbuja(int generar_conjunto[], int TAM);

void seleccion(int generar_conjunto[], int TAM);

void MEZCLA_SORT(int generar_conjunto[], int inicio, int fin);

void Mezcla(int generar_conjunto[], int inicio, int medio, int fin);

void QUICK_SORT(int generar_conjunto[], int inicio, int fin);

int PARTITION(int generar_conjunto[], int inicio, int fin);

void Monticulos(int generar_conjunto[], int TAM);

void BUILD_MAX(int generar_conjunto[], int TAM);

void MAX_HEAPIFY(int generar_conjunto[], int i,  int n);

void Shell(int generar_conjunto[], int n);

char nom_Arc_Met[NUM_ALGORITMOS][35] = {
    "1_Insercion_Ordenamiento.csv",
    "2_Burbuja_Ordenamiento.csv",
   "3_Seleccion_Ordenamiento.csv",
   "4_Mezcla_Sort_Ordenamiento.csv",
   "5_Quick_Sort_Ordenamiento.csv",
   "6_Monticulos_Ordenamiento.csv",
   "7_Shell_Ordenamiento.csv"
};

int main() {
    srand(time(NULL));
    int generar_conjunto[(TAM_MAXIMO - TAM_MINIMO) / INCREMENTO+1][TAM_MAXIMO];
    int copia_conjunto[TAM_MAXIMO];
    double suma[NUM_ALGORITMOS][(TAM_MAXIMO - TAM_MINIMO) / INCREMENTO+1] = {0},prom[NUM_ALGORITMOS][(TAM_MAXIMO - TAM_MINIMO) / INCREMENTO+1] ;
    double tiempo[(TAM_MAXIMO - TAM_MINIMO) / INCREMENTO+1];

    ofstream archivos[NUM_ALGORITMOS];
    for (int i = 0; i < NUM_ALGORITMOS; i++) {
        archivos[i].open(nom_Arc_Met[i]);
        for(int j=0;j<=(TAM_MAXIMO-TAM_MINIMO)/INCREMENTO;j++ ){
        	archivos[i] << "Tamano "<< (j+1)*10<< ",";
		}
		archivos[i] << endl;
    }
    //Procedimiento que se repetirá mil veces, donde posteriormente se representa graficamente en cada renglon de los archivos csv
    for (int i = 0; i < VECES; i++) {
        if(i==0)cout << "Conjuntos " << i+1 << endl;
        if((i+1)%5 == 0)cout << "Conjuntos " << i + 1 << endl;     
        // Genera conjuntos de números aleatorios de tamaño 10, en 10 hasta mil
        for(int j=0;j<(TAM_MAXIMO - TAM_MINIMO) / INCREMENTO+1;j++){
            for (int k = 0; k < (j+1)*INCREMENTO; ++k) {
        		generar_conjunto[j][k] = aleatorio(1, TAM_MAXIMO);	
			}
        }       
        //Se aplicarán cada uno de los algoritmos a los 100 conjuntos
        for (int m = 0; m < NUM_ALGORITMOS; ++m) {
            if((i+1)%5 == 0)cout << nom_Arc_Met[m] << " ";
            for (int j = 0; j <= (TAM_MAXIMO - TAM_MINIMO) / INCREMENTO; ++j) {
                int K = (j + 1) * 10;
                // Realiza una copia del conjunto para cada uno de los métodos, la cual es la que se va a ordenar
                copia(generar_conjunto[j], copia_conjunto, K);

                auto start = chrono::high_resolution_clock::now();
                switch (m) {
                    case 0: insercion(copia_conjunto, K); break;
                    case 1: burbuja(copia_conjunto, K); break;
                    case 2: seleccion(copia_conjunto, K); break;
                    case 3: MEZCLA_SORT(copia_conjunto, 0, K - 1); break;
                    case 4: QUICK_SORT(copia_conjunto, 0, K - 1); break;
                    case 5: Monticulos(copia_conjunto, K); break;
                    case 6: Shell(copia_conjunto, K); break;
                }
                auto end = chrono::high_resolution_clock::now();
                //Cálculo del tiempo de ordenación de conjuntos de cada tamaño y de cada método
                chrono::duration<double, nano> duration = end - start;
                tiempo[j] = duration.count();
                //Acumulación de los tiempos para después utilizarlo en el cálculo de los promedios
                suma[m][j] += tiempo[j];
                archivos[m] <<  tiempo[j] << " , " ;
            }
            if((i+1)%5 == 0)cout << (TAM_MAXIMO - TAM_MINIMO) / INCREMENTO + 1 << " pruebas realizadas"<<endl;
            archivos[m] <<  endl ;
        }
        if((i+1)%5 == 0)cout << endl;
    }
    for (int i = 0; i < NUM_ALGORITMOS; i++) {
        archivos[i] << "Promedios" << endl;
        for(int j=0;j<=(TAM_MAXIMO - TAM_MINIMO) / INCREMENTO;j++){
            prom[i][j]=suma[i][j]/VECES;
            archivos[i] << prom[i][j] << " , " ;
        }
        archivos[i].close();
    }
    return 0;
}

//Funciones para cada uno de los métodos 
void insercion(int generar_conjunto[TAM_MAXIMO], int TAM){
    int valor;
    int j;
    for(int i = 1; i < TAM; ++i){
        valor = generar_conjunto[i];
        j = i - 1;
        while(j >= 0 && valor < generar_conjunto[j]){
            generar_conjunto[j+1] = generar_conjunto[j];
            j = j - 1;
        }
        generar_conjunto[j+1] = valor;
    }
}
//*****************************************************************************************************************
void burbuja(int generar_conjunto[TAM_MAXIMO], int TAM){
    int temporal;
	int intercambiado = 1;	
    for(int i = 0; i < TAM - 1 && intercambiado == 1 ; ++i){
    	intercambiado = 0;
        for(int j = 0 ; j < TAM - i - 1; ++j ) { 
            if(generar_conjunto[j] > generar_conjunto[j+1]){
                temporal = generar_conjunto[j];
                generar_conjunto[j] = generar_conjunto[j+1];
                generar_conjunto[j+1] = temporal;
                intercambiado = 1;
            }
        }
    }
}
//*****************************************************************************************************************
void seleccion(int generar_conjunto[TAM_MAXIMO], int TAM){
    int min_ind;
    int temporal;
        for(int i = 0; i < TAM - 1; ++i){
            min_ind = i;
            for(int j = i + 1; j < TAM ; ++j){
                if(generar_conjunto[j] < generar_conjunto[min_ind]){
                    min_ind = j;
                }
            }
            if(min_ind != i){
                temporal = generar_conjunto[i];
                generar_conjunto[i] = generar_conjunto[min_ind];
                generar_conjunto[min_ind] = temporal;
            }
        }
}
//*****************************************************************************************************************
void MEZCLA_SORT(int s[TAM_MAXIMO], int inicio, int fin){
    int medio;
    if(inicio < fin){
        medio =(inicio + fin)/2;
        MEZCLA_SORT(s, inicio, medio);
        MEZCLA_SORT(s, medio + 1, fin);
        Mezcla(s, inicio, medio, fin);
    }
}
//*****************************************************************************************************************
void Mezcla(int s[TAM_MAXIMO], int inicio, int medio, int fin){
    int n1, n2;

    n1= medio - inicio + 1;
    n2 = fin - medio;

    int L[n1], R[n2];

    for(int i = 0 ; i < n1; ++i){
        L[i] = s[inicio + i];
    }
    for(int j = 0; j < n2; ++j){
        R[j]= s[medio + j + 1];
    }

    int i = 0 ;
    int j = 0 ;
    int k = inicio;

    while(i < n1  && j < n2){
        if( L[i] <= R[j]){
            s[k] = L[i];
            i += 1;
        }else{
            s[k] = R[j];
            j += 1;
        }
        k += 1;
    }
    while(i < n1){
        s[k] = L[i];
        i += 1;
        k += 1;
    }
    while(j < n2){
        s[k] =  R[j];
        j += 1;
        k += 1;
    }
}
//*****************************************************************************************************************
void QUICK_SORT(int s[TAM_MAXIMO], int inicio, int fin){
    int pivote_ind;

    if(inicio < fin){
        pivote_ind = PARTITION(s, inicio, fin);
        QUICK_SORT(s, inicio, pivote_ind - 1);
        QUICK_SORT(s, pivote_ind + 1, fin);
    }
}
//*****************************************************************************************************************
int PARTITION(int s[TAM_MAXIMO], int inicio, int fin){
    int pivote = s[fin];
    int i = inicio - 1;
    for(int j = inicio; j < fin ; ++j){
        if(s[j] <= pivote){
            i += 1;
            swap(&s[i],&s[j]);
        }
    }
    swap(&s[i + 1], &s[fin]);
    return i + 1;
}
//*****************************************************************************************************************
void Monticulos(int s[TAM_MAXIMO], int TAM){
    BUILD_MAX(s,TAM);
    for(int i = TAM - 1; i >= 1; --i){
        swap(&s[0], &s[i]);
        MAX_HEAPIFY(s,0,i);
    }
}
//*****************************************************************************************************************
void BUILD_MAX(int s[TAM_MAXIMO], int TAM){
    for(int i = TAM/2 - 1; i >=0; --i){
        MAX_HEAPIFY(s,i,TAM);
    }
}
//*****************************************************************************************************************
void MAX_HEAPIFY(int s[TAM_MAXIMO], int i, int n){
    int izq, der, mayor;
    izq = 2*i + 1;
    der = 2*i + 2;
    mayor = i;
    if(izq < n && s[izq] > s[mayor]){
        mayor = izq;
    }
    if(der < n && s[der] > s[mayor]){
        mayor = der;
    }
    if(mayor != i){
        swap(&s[i], &s[mayor]);
        MAX_HEAPIFY(s,mayor,n);
    }
}
//*****************************************************************************************************************
void Shell(int s[TAM_MAXIMO], int n){
int temporal, j;

    for(int gap = n/2; gap > 0; gap /=2){
        for(int i = gap; i < n; ++i){
            temporal = s[i];
            j = i;
            while(j >= gap && s[j - gap] > temporal){
                s[j] = s[j-gap];
                j -= gap; 
            }
            s[j] = temporal;
        }
    }
}
//*****************************************************************************************************************
int aleatorio(int inicio, int fin)
{
    return inicio + rand()% (fin-inicio+1);
}
//*****************************************************************************************************************
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
//*****************************************************************************************************************
void copia(int generar_conjunto[TAM_MAXIMO], int copia_conjunto[TAM_MAXIMO], int TAM) {
    for (int j = 0; j < TAM; ++j) {
        copia_conjunto[j] = generar_conjunto[j];
    }
}