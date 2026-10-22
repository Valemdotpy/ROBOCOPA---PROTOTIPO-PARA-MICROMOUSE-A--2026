#include <stdio.h>
#include <stdlib.h>
#define L__PLANCK 6.26e-34
typedef struct{
    float Hz;
    char nombre;
}Frecuencias;

void Ingresar_Datos_Promedio(Frecuencias* editar);
void impr_clasif(int frecuencia);
int clasificar_ondas(float frecuencia);
float Calc_Energia(float frecuencia);
float Calc_Promedio(float A, float B,float C, float D);

int main()
{
    Frecuencias A,B,C,D,Inicial;
    A.nombre='A'; B.nombre='B'; C.nombre='C'; D.nombre='D';
    printf("Ingresar frecuencia de Onda!\n");
    scanf("%e",&Inicial.Hz);
    impr_clasif(clasificar_ondas(Inicial.Hz));
    printf("La Energia que da resultado de esta frecuencia es de: %.2e",Calc_Energia(Inicial.Hz));

    Ingresar_Datos_Promedio(&A);
    Ingresar_Datos_Promedio(&B);
    Ingresar_Datos_Promedio(&C);
    Ingresar_Datos_Promedio(&D);

    printf("El promedio de las 4 mediciones es de %.2e",Calc_Promedio(A.Hz,B.Hz,C.Hz,D.Hz));



    return 0;
}


int clasificar_ondas(float frecuencia){
    if(frecuencia<30e3) return 1;//radio muy baja
    else if(frecuencia<650e3) return 2; //radio larga
    else if(frecuencia<1.7e6) return 3; //radio media
    else if(frecuencia<30e6) return 4; //radio corta
    else if(frecuencia<300e6) return 5; //radio muy alta
    else if(frecuencia<1e9) return 6; //radio ultra alta
    else if(frecuencia<300e9) return 7; //microondas
    else if(frecuencia<6e12) return 8; //infrarrojo lejano
    else if(frecuencia<120e12) return 9; //infrarrojo medio
    else if(frecuencia<384e12) return 10; //infrarrojo cercano
    else if(frecuencia<789e12) return 11; //luz visible
    else if(frecuencia<1.5e15) return 12; //Ultra violeta Cercano
    else if(frecuencia<30e15) return 13; //Ultra violeta extremo
    else if(frecuencia<30e18) return 14; //rayo X
    else if(frecuencia>30e18) return 15; //rayos gamma
    else return 16;
}


void impr_clasif(int frecuencia){
    switch(frecuencia){
    case 1:
        printf("Frecuencia de Radio Muy baja\n");
        break;
    case 2:
        printf("frecuencia de Radio larga\n");
        break;
    case 3:
        printf("Frecuencia de Radio Media\n");
        break;
    case 4:
        printf("Frecuencia de Radio Corta\n");
        break;
    case 5:
        printf("Frecuencia de radio Muy Alta\n");
        break;
    case 6:
        printf("Frecuencia de Radio Ultra Alta\n");
        break;
    case 7:
        printf("Frecuencia de Radio de Microondas\n");
        break;
    case 8:
        printf("Frecuencia de Infrarrojo Lejano\n");
        break;
    case 9:
        printf("Frecuencia de infrarrojo Medio\n");
        break;
    case 10:
        printf("Frecuencia de Infrarrojo Cercano\n");
        break;
    case 11:
        printf("Frecuencia de luz visible\n");
        break;
    case 12:
        printf("Frecuencia Ultravioleta Cercano\n");
        break;
    case 13:
        printf("Frecuencia Ultravioleta Extremov");
        break;
    case 14:
        printf("Frecuencia de Rayos X\n");
        break;
    case 15:
        printf("Frecuencia de Rayos Gamma\n");
        break;
    case 16:
        printf("Error, Numero Invalido");
        break;
    }
}

float Calc_Energia(float frecuencia){
    frecuencia = 'L_PLANCK'*frecuencia;
    return frecuencia;
}
void Ingresar_Datos_Promedio(Frecuencias* editar)
{
    printf("\nIngresar la medicion %c:",editar->nombre);
    scanf("%e",&editar->Hz);
}
float Calc_Promedio(float A, float B, float C, float D){
    float resultado = A+B+C+D;
    resultado = resultado/4;
    return resultado;
}

//Evaluacion, Tema: Radiotelescopio
//firma: Abalos Valentin 4II, 25/08/2025



