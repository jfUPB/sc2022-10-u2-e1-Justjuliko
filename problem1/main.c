#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//prueba push

#ifdef DOLOG
#define LOG(...) fprintf(log, __VA_ARGS__);
#else
#define LOG(...)
#endif

struct array
{
    int *pdata; //direccion de un arreglo de enteros
    int size; //tamaño de los arreglos
};

void initArray(struct array *); 
void getArray(struct array *);
void arrayCommon(struct array *, struct array *, struct array *);
void printArray(struct array *);
void freeMemory(struct array *, struct array *, struct array *);

void initArray(struct array *arr){
    arr->pdata = NULL;
    arr->size = -1;
}

void printArray(struct array *parr) //impresion del arreglo 
{
    for (int i = 0; i < parr->size; i++) //eleccion del arreglo arrIn1,arrIn2,arrOut
    {
        printf("%d ", parr->pdata[i]);
    }
    printf("\n");
}

void getArray(struct array *parr) //creacion del arreglo
{
    //leer el tamaño
    //leer cada elemento ¬ ciclo controlado por el tamaño
    //ejercicio 7

    char num1[16]; //entrada numero size
    char num2[16]; //entrada numeros datos

    if (fgets(num1,5,stdin) != NULL) //orden del teclado size 
    {
        num1[strlen(num1) -1 ] = 0;
    }
    int chint1 = sscanf(num1, "%d", &parr->size); //cambio de caracter a integer
    
    parr->pdata = malloc(sizeof(int)*parr->size); //alocar en memoria dinamica

    for(int i = 0; i < parr -> size;i++) //loop entrada de datos arreglo
    {
        if (fgets(num2,5,stdin) != NULL) //orden del teclado datos arreglo
        {
            int chint2 = sscanf(num2, "%d", parr->pdata+i); //cambio de caracter a integer
        }
    }
}

void arrayCommon(struct array *arrIn1, struct array *arrIn2, struct array *arrOut) //comparacion de los arreglos
{
    //pasar direccion arrIn1 y direccion arrIn2 y pasarlo a la direccion de arrOut

    //encontrar elementos comunes de los dos arreglos
}

void freeMemory(struct array *arr1, struct array *arr2, struct array *arr3) //limpieza de la memoria dinamica
{
    free(arr1->pdata); //limpieza del arrIn1
    free(arr1);

    free(arr2->pdata); //limpieza del arrIn2
    free(arr2);

    free(arr3->pdata); //limpieza arr3? arrOut?
    free(arr3);
}

int main(void)
{

#ifdef DOLOG
    FILE *log = fopen("log", "w");
    if (log == NULL)
    {
        perror("log file creation fails: ");
        return EXIT_FAILURE;
    }
#endif

    char commandBuf[64];

    LOG("creating an object for each array\n");

    struct array *arr1 = malloc(sizeof(struct array) * 1); //ArrIn1 en memoria dinamica
    initArray(arr1);
    struct array *arr2 = malloc(sizeof(struct array) * 1); //ArrIn2 en memoria dinamica
    initArray(arr2);    
    struct array *arr3 = malloc(sizeof(struct array) * 1); //ArrOut en memoria dinamica?
    initArray(arr3);


    LOG("Init command loop\n");

    while (fgets(commandBuf, sizeof(commandBuf), stdin) != NULL) //comandos?
    {
        commandBuf[strlen(commandBuf) - 1] = 0;

        if (strncmp(commandBuf, "arr1", strlen("arr1")) == 0)
        {
            LOG("getting array1\n");
            getArray(arr1);
        }
        else if (strncmp(commandBuf, "arr2", strlen("arr2")) == 0)
        {
            LOG("getting array2\n");
            getArray(arr2);
        }
        else if (strncmp(commandBuf, "printArr1", strlen("printArr1")) == 0)
        {
            LOG("printing arr1\n");
            printArray(arr1);
        }
        else if (strncmp(commandBuf, "printArr2", strlen("printArr2")) == 0)
        {
            LOG("printing arr2\n");
            printArray(arr2);
        }
        else if (strncmp(commandBuf, "compare", strlen("compare")) == 0)
        {
            LOG("Compare arrays\n");
            arrayCommon(arr1, arr2, arr3);
        }
        else if (strncmp(commandBuf, "printResult", strlen("printResult")) == 0)
        {
            LOG("printing compare result\n");
            printf("%d\n", arr3->size);
            if (arr3->size != 0)
            {
                printArray(arr3);
            }
        }
        else if (strncmp(commandBuf, "exit", strlen("exit")) == 0)
        {
            LOG("running exit command\n");
            freeMemory(arr1,arr2,arr3);
            break;
        }
    }

    return EXIT_SUCCESS;
}
