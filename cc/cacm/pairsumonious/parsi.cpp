#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>

using namespace std;

#define DEBUG
#define Max_N 9
#define Max_S 36
#define MAX_ARG 3

void print_vector(vector<int>& lista){
	vector<int>::iterator it;
	//~ cout << lista.size() << ": [" ;
	for(it=lista.begin();it!=lista.end();++it){
		if((it+1)!=lista.end()){
			cout << *it << " " ;
		}else{
			cout << *it ;
		}
	}
	cout << endl;
}

void print_array(int* array,int size,bool flag){
	cout << "[" ;
	for(int i=0;i<size;++i){
		cout << array[i] << ' ';
	}
	cout << "] "; 
	if(flag){
		cout << endl;
	}
}

void print_set(set<int>& lista){
	set<int>::iterator it;
	cout << lista.size() << ": [" ;
	for(it=lista.begin();it!=lista.end();++it){
		//~ if((it+1)!=lista.end()){
			//~ cout << *it << "," ;
		//~ }else{
			cout << *it << " ";
		//~ }
	}
	cout << "]" << endl;
}

bool sistema_ecu(int* b, int* a){
	bool found=false;
	int aux=(b[0]+b[1]-b[2]);
		if(aux%2==0){
			a[0]=aux/2;
			a[1]=b[0]-a[0];
			a[2]=b[1]-a[0];
			found=true;
		}
	return found;
}

bool calcula_soluciones(int* b, vector<int>& solucion){
	int a[MAX_ARG];
	bool resultado = sistema_ecu(b,a);
	if(resultado)
		for(int i = 0; i < MAX_ARG; ++i)
			solucion.push_back(a[i]);	
	return resultado;
}

bool check_new_solution(vector<int>& soluciones,vector<int>& entrada,int solucion){
	for(int k=1;k<soluciones.size();++k){
		int aux=soluciones[k]+solucion;
		for(int j=0
	}
}


int barrier_pos(int b){
	return b*(b-1)/2;
}

int main(){
	int num_res,num_n,cont,num_aux;
	int b[MAX_ARG];
	vector<int> entrada;
	vector<int> solucion;	
	bitset<Max_S> checked;
#ifdef DEBUG
	ifstream input;
	 input.open("input");
#endif
	
	while(cin){
		//LECTURA DE DATOS
		num_res = -1;
#ifdef DEBUG
		input >>  num_res;
#else
		cin >> num_res;
#endif		
		if(num_res<=1){
			return 0;
		}
		num_n=barrier_pos(num_res);
		
		entrada.clear();
		solucion.clear();
		
		
		while(entrada.size()<num_n){
#ifdef DEBUG
		input >>  num_aux;
#else
		cin >> num_aux;
#endif
		entrada.push_back(num_aux);
		}
		int javi_aqui=0;
		//ALGORITMO QUE RESUELVE EL PROBLEMA
		//~ b1=a1+a2
		//~ b2=a1+a3
		//~ b3=a2+a3
		
		sort(entrada.begin(),entrada.end());
		
		for(int z=0;z<2;++z){
			b[i]=entrada[i];
			checked.set(i);
		}
		
		int pos_3=-1;
		for(int i=2;i<entrada.size();++i){
			b[2]=entrada[i];
			if(calcula_soluciones(b,solucion)){
				pos_3=i;
				checked.set(i);
				break;
			}
		}
		
		
		int barrier=3;
		int i=2;
		
		if(solucion.size()==0){
			cout << "Impossible\n";
		}else{
			while(i<entrada.size()){
				if(!checked.test(i)){
					solucion.push_back(entrada[i]-solucion[0]);
					i=barrier_pos(++barrier);
				}else{
					++i;
				}
			}			
			print_vector(solucion);
		}
		
		
		
	}
#ifdef DEBUG
	input.close();
#endif
	return 0;
}
