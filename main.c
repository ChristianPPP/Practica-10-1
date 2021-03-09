#include <stdio.h>
#include <stdlib.h>

struct animales
{
  char nombre[30];
  float peso;
  char tipo[30];
};

void registrar_Animal (struct animales a[], int n);

int main(void) {
  int opc, nanimales;
  FILE *animales;
  animales=fopen("animales.txt","r");
  struct animales an[100];
  printf("***BIENVENIDO***\n");
  do 
  {
    printf("\nMenu\n");
    printf("1.- Registrar animal\n");
    printf("2.- Base de datos de animales del zoológico\n");
    printf("3.- Buscar animal\n");
    printf("4.- Salir\n");
    scanf("%d",&opc);
    switch (opc)
    {
      case 1:
      printf("Número de animales a ingresar: ");
      scanf("%d",&nanimales);
      registrar_Animal(an,nanimales);
      break;
      case 2:
      printf("Base de datos");
      printf("\nLista de animales registrados:");
      for(int i=0;i<nanimales;i++)
      {
        printf("\nIdentificador (ID): %d",i);
        printf("\nNombre: %s",an[i].nombre);
        printf("\nPeso: %f",an[i].peso);
        printf("\nTipo: %s",an[i].tipo);
        printf("\n");
      }
      break;
      case 3:
      break;
      case 4:
      printf("Saliendo...\n");
      break;
      default:
      printf("Opcion no valida.\n");
    }
  }while(opc!=4);
  return 0;
}

void registrar_Animal (struct animales a[], int n)
{
  FILE *animales, *bdd;
  animales=fopen("animales.txt","a");
  bdd=fopen("BDDanimales.txt","a");
  for (int i=0; i<n; i++)
  {
    printf("\nIngrese el nombre del animal n°%d: ",i+1);
    scanf("%s",a[i].nombre);
    printf("\nIngrese el peso del animal n°%d: ",i+1);
    scanf("%f",&a[i].peso);
    printf("\nIngrese el tipo de animal n°%d: ",i+1);
    scanf("%s",a[i].tipo);
    printf("\n\n");
    fprintf(animales,"%s ",a[i].nombre);
    fprintf(animales,"%s ",a[i].tipo);
    fprintf(animales,"%f ",a[i].peso);
    fprintf(bdd,"Lista de animales registrados:");
    fprintf(bdd,"\nNombre del animal n°%d: %s ",i+1,a[i].nombre);
    fprintf(bdd,"\nPeso del animal n°%d: %s ",i+1,a[i].tipo);
    fprintf(bdd,"\nTipo del animal n°%d: %.2f ",i+1,a[i].peso);
  }
  fclose(bdd);
  fclose(animales);
}