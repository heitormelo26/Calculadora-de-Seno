#include<stdio.h>
#include<math.h>

int fatorial(int n,int valor){ // Fun��o recursiva para calcular o fatorial de um n�mero
	if(n == 1) return valor;
	n--;
	valor = valor* n;
	fatorial(n,valor);
}

float serieTaylor(float n){ 
	int i = 0, x =0;
	unsigned long int fat;
	float total = 0;
	for(i;i<6;i++){ // o i, na f�rmula seria o K, varia somente at� 5, pois com i=6, tem-se que 2*i+1 = 13, e o computador nao consegue fazer corretamente o calculo de 13!.
					// ent�o para nao influenciar no resultado, limitei o i para chegar somente at� o 5
		x = (2*i)+1;
		fat = fatorial(2*i+1,2*i+1);
//		printf("%d ! = %d\n",x,fat);
		total = total + ( pow(-1,i)*( pow(n,(2*i+1))/(fatorial(2*i+1,2*i+1)) ));
//		printf("%f || ",total);
	}
	return total;
}


int main(){
	int y;
	float n,x;
	printf("Digite o numero para calcular seu seno: ");
	scanf("%f",&n);
	
	x = serieTaylor(n);
	
	printf("\nO seno de %.2f e: %.2f",n,x);
}
