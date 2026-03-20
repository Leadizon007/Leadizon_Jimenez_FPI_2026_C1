#include <stdio.h>
#define NUEVO 100
#define SALIR 0
#define SUMAR 1
#define DIVIDIR 2
#define MULTIPLICAR 3
#define RESTAR 4
#define ERR_DivByZero 100
#define ERR_OK 0
// concepto de funcion
//concepto de programa
//% el operador de dirrecion
//*el operador indireccion
//AMBITO DE UNA variable
//CICLO DE VIDA DE UNA VARIBLE
int sumar(float Num1,float Num2,float*r);//declaracion de funcion
//Pasar la referencia
int main()
{
	int menu = NUEVO;
	int cod_err=ERR_OK;

	float Num1 = 0.0;//variables locales del main()
	float Num2 = 0.0;
	float result = 0.0;

	
	
	

	do {
	    
	    printf("\n0-SALIR\n1-SUMAR\n2-DIVIDIR\n3-MULTIPLICAR\n4-RESTAR\n");
	    scanf("%i",&menu);
		if(menu == SUMAR)
		{

			printf("\nEscriba el primer numero a sumar:");
			scanf("%f",&Num1);
			printf("\nEscriba el segundo numero a sumar:");
			scanf("%f",&Num2);
		 cod_err=sumar(Num1,Num2,&result);
			if(cod_err!=ERR_OK)
			{
		       
		    printf("\nERR EN SUMA");
		     
			} else
			
			{
		       
			printf("\n1-SUMAR de %f + %f es:%f\n",Num1,Num2,result);
		}

	} while(menu !=SALIR);
	
	return 0;

}

int sumar(float Num1,float Num2,float *r)

//pasando los valores de las variables

{
    *r = Num1 + Num2 ;
    
	return ERR_OK;
}
}








