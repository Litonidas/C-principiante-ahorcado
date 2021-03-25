#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>



struct puntuacion{
    int puntaje;
    char nombre[15];
    char fecha[20];
};//estructura

struct puntuacion ingPunt;

main(){
    system("CLS");
    printf("\n\n    ####   ##  ##   ####   #####    #####   ####   #####    ####\n");
    printf("   ##  ##  ##  ##  ##  ##  ##  ##  ##      ##  ##  ##  ##  ##  ##\n");
    printf("   ######  ######  ##  ##  #####   ##      ######  ##  ##  ##  ##\n");
    printf("   ##  ##  ##  ##   ####   ##  ##   #####  ##  ##  #####    ####\n\n\n");
    printf("   B i e n v e n i d o   a l   j u e g o   d e l   a h o r c a d o\n\n");
    printf("         ######\n");
    printf("         #    |\n");
    printf("         #    0\n");
    printf("         #   /|\\\n");
    printf("         #    |\n");
    printf("         #   / \\\n");
    printf("         #\n");
    printf("         #\n");
    printf("        ###                   Escriba su Nombre >> ");


    scanf(" %s",&ingPunt.nombre);

    menu();

}//fin main

juego(){
    system("cls");
    /*
    se declaran variables para el array palabras, en este caso 10 de maximo 8 letras, el array palabra, donde almacenaremos
    la palabra miestras se esta jugando, la variable letra donde almecenaremos la letra ingresada por el jugador y el array
    respuesta donde iremos almacenando las letras ingresadas por el usuario para luego compararlas con la palabre de juego
    */
    char palabras[10][8],palabra[8],letra,respuestas[14],volver;

    int j,i,y,z, azar, vidas,longPalabra, puntaje,intentos,aciertos, fallos;//se definen variables enteras

    strcpy(palabras[0],"SANTIAGO");
    strcpy(palabras[1],"MADRID");
    strcpy(palabras[2],"PARIS");
    strcpy(palabras[3],"LIMA");
    strcpy(palabras[4],"MEXICO");
    strcpy(palabras[5],"LONDRES");
    strcpy(palabras[6],"ROMA");
    strcpy(palabras[7],"BERLIN");
    strcpy(palabras[8],"MOSCU");
    strcpy(palabras[9],"DUBLIN");

    vidas = 7;
    puntaje = 0;
    intentos = 0;
    aciertos = 0;
    fallos = 0;
    int longRespuestas = 0;

    srand(time(NULL));//se define srand para que los numero aleatorios no sean siempre los mismos
    azar = rand()%10;//se elige numero al azar entre 0 y 9

    strcpy(palabra, palabras[azar]);//se copia palabra elegida al azar a un nuevo array

    longPalabra = strlen(palabra);//se copia en la variable la longitud de la palabra

    char respuesta[longPalabra];

    do {//inicio del juego
        printf("\n\n");
        printf("       ");
        /******************************************************************
        *******************************************************************
        ******************************************************************/

        fallos = intentos-aciertos;

        switch (fallos) {
            case 1: vidas=6;break;
            case 2: vidas=5;break;
            case 3: vidas=4;break;
            case 4: vidas=3;break;
            case 5: vidas=2;break;
            case 6: vidas=1;break;
            case 7: vidas=0;break;
            default: vidas=7;break;
        }
        /******************************************************************
        *******************************************************************
        ******************************************************************/


        if(vidas==0){
        printf("\n############################################################\n");
        printf("############################################################\n");
        printf("##                                                        ##\n");
        printf("##        ########     ####     ###   ###  #########      ##\n");
        printf("##       ###         ###  ###   #### ####  ###            ##\n");
        printf("##      ###         ###    ###  #########  ###            ##\n");
        printf("##      ###  #####  ###    ###  #########  #########      ##\n");
        printf("##      ###    ###  ##########  ### # ###  ###            ##\n");
        printf("##       ###   ###  ###    ###  ###   ###  ###            ##\n");
        printf("##        ########  ###    ###  ###   ###  #########      ##\n");
        printf("##                                                        ##\n");
        printf("##                                                        ##\n");
        printf("##        #######   ###    ###  #########  ########       ##\n");
        printf("##       ###   ###  ###    ###  ###        ###   ###      ##\n");
        printf("##       ###   ###  ###    ###  ###        ###    ###     ##\n");
        printf("##       ###   ###  ####  ####  #########  ###   ###      ##\n");
        printf("##       ###   ###   ########   ###        #######        ##\n");
        printf("##       ###   ###    ######    ###        ###  ###       ##\n");
        printf("##        #######       ##      #########  ###   ####     ##\n");
        printf("##                                                        ##\n");
        printf("############################################################\n");
        printf("############################################################");
        printf("\n\nLo sentimos %s, Has Perdido!!!\n\nLa palabra que buscabas era %s\n\n",ingPunt.nombre,palabra);
        puntajes();
        system("PAUSE");
        menu();
        break;
    }


        //imprime las vidas
        for(i=1;i<=vidas;i++){
            printf("%c ",3);
        }
        printf("\n\n");
        //se imprime primeras 9 letras del abecedario
        printf("                                  ");

        for(i=0;i<=8;i++){
            printf("%c  ",65+i);
        }
        //se imprime siguientes 9 letras del abecedario
        printf("\n\n       ######                     ");
        for(i=9;i<=17;i++){
            printf("%c  ",65+i);
        }
        printf("\n       #");
        if(vidas<=6){
            printf("    |");
        }
        printf("\n       #    ");
        if(vidas<=5){
            printf("0                     ");
        }else {
            printf("                      ");
        }
        //se imprime ultimas letras del abecedario
        //printf("                         ");
        for(i=18;i<=25;i++){
            printf("%c  ",65+i);
        }
        printf("\n       #");

        switch (vidas){//dibujos, sin importancia
        case 1: printf("   /|\\");break;
        case 2: printf("   /|\\");break;
        case 3: printf("   /|");break;
        case 4: printf("    |");break;
        default:printf(" ");break;
        }
        printf("\n       #    ");
        if (vidas<=4){
            printf("|");
        }
        printf("\n       #   ");
        if (vidas<=1){
            printf("/");
        }
        printf("\n       #   ");

        printf("\n       #   ");
        printf("\n      ###                         ");

        //se imprime las letras acertadas
        for(i=0;i<=longPalabra-1;i++){
            if (isalpha(respuesta[i])&& respuesta[i]== palabra[i]){
                printf("%c",respuesta[i]);
                printf("  ");
            }else
            printf("   ");
        }





        printf("\n                                  ");
        for(i=1;i<=longPalabra;i++){//imprime los giones en pantalla
            printf("_  ");
        }
        ingPunt.puntaje = (aciertos*2)-(fallos);
        printf("\n\n\n");
        printf("      %d Pts                     ",ingPunt.puntaje);//imprime en puntaje en panalla






        //loop para imprimir letras usadas
        for(i=0;i<=intentos-1;i++){
            if (isalpha(respuestas[i])){
            printf("%c ",respuestas[i]);
        }}

/*                    impresiones en pantalla para comprobar funcionamiento           */



        printf("\n\n                                  Ingresa tu letra =>");//
        do {
            fflush(stdin);
            letra = toupper(getchar());//convierte la letra ingresada por el usuario a mayusculas
            respuestas[intentos]=letra;//copia la letra a un array
        }while (!isalpha(letra));//se repetira hasta que sea distinto de letra


        system("cls");
        intentos++;//se suma 1 a los intentos
        longRespuestas = strlen(respuestas);


        for(i=0;i<=longPalabra-1;i++){///////////////loop para comparar la letra ingresada por el jugador con la del array con la palabra
            if(letra==palabra[i] && letra !=respuesta[i]){                 //si la letra es igual a una de las letras del array

                respuesta[i]=letra;                //copia la letra en un nuevo array y
                aciertos++;

        /***********************************************************************************
        ***************                                                       **************
        ***********************************************************************************/


        if(aciertos == longPalabra){
            ingPunt.puntaje = 10+(aciertos*2)-(fallos);
        }

        if(aciertos == longPalabra){//si es correcta ha ganado
            system("cls");
            printf("############################################################\n");
            printf("############################################################\n");
            printf("##                                                        ##\n");
            printf("##      #########   ###  #########  ####     ###   ###    ##\n");
            printf("##      ###    ###       ###        ######   ###   ###    ##\n");
            printf("##      ###    ###  ###  ###        ### #### ###   ###    ##\n");
            printf("##      #########   ###  #########  ###  #######   ###    ##\n");
            printf("##      ###    ###  ###  ###        ###    #####   ###    ##\n");
            printf("##      ###    ###  ###  ###        ###     ####          ##\n");
            printf("##      #########   ###  #########  ###      ###   ###    ##\n");
            printf("##                                                        ##\n");
            printf("############################################################\n");
            printf("############################################################\n\n");

            printf("Felicidades %s \nAdivinaste la palabra %s +10puntos \nobtuviste un puntaje de %d\n\n",ingPunt.nombre,palabra,ingPunt.puntaje);
            puntajes();
            system("PAUSE");
            system("cls");
            menu();
        }
        /***********************************************************************************
        ************************************************************************************
        ***********************************************************************************/
            }
        }



    }while (vidas != 0);
}//fin funcion juego


menu(){
    system("CLS");
    int opcion;
    printf("\n   Hola %s elige una opcion del menu",ingPunt.nombre);
    printf("\n\n      ######################################\n");
    printf("      ##                                  ##\n");
    printf("      ##                                  ##\n");
    printf("      ##        1.- JUGAR                 ##\n");
    printf("      ##                                  ##\n");
    printf("      ##                                  ##\n");
    printf("      ##        2.- CAMBIAR JUGADOR       ##\n");
    printf("      ##                                  ##\n");
    printf("      ##                                  ##\n");
    printf("      ##        3.- INSTRUCCIONES         ##\n");
    printf("      ##                                  ##\n");
    printf("      ##                                  ##\n");
    printf("      ##        4.- PUNTAJES              ##\n");
    printf("      ##                                  ##\n");
    printf("      ##                                  ##\n");
    printf("      ##        5.- ACERCA DE             ##\n");
    printf("      ##                                  ##\n");
    printf("      ##                                  ##\n");
    printf("      ##        6.- SALIR                 ##\n");
    printf("      ##                                  ##\n");
    printf("      ##                                  ##\n");
    printf("      ######################################\n\n");

    printf("      Opcion >> ");
    scanf("%d",&opcion);

    switch (opcion){
        case 1: juego(); break;
        case 2: cambiarJugador(); break;
        case 3: instrucciones(); break;
        case 4: mostrarPuntajes(); break;
        case 5: acerca(); break;
        case 6: getchar(); break;
        default: system("CLS"); printf("\nNo es una opcion valida\n\n"); system("PAUSE"); system("CLS"); main(); break;
    }
}//fin funcion menu


instrucciones(){
    system("CLS");
    FILE *fichero;
    char mensaje[4050];

    if ((fichero = fopen("instrucciones.txt", "rt")) !=NULL){
        while(!feof(fichero)){
            fgets(mensaje,4050,fichero);
            if(feof(fichero)){

            }else
            fputs(mensaje,stdout);
        }
        //
        fclose(fichero);
    }
    system("PAUSE");
    system("cls");
    menu();
}//fin funcion instrucciones


acerca(){
    system("CLS");
    FILE *fichero;
    char mensaje[4050];

    if ((fichero = fopen("acerca.txt", "rt")) !=NULL){
        while(!feof(fichero)){
            fgets(mensaje,4050,fichero);
            if(feof(fichero)){

            }else
            fputs(mensaje,stdout);
        }
        //
        fclose(fichero);
    }else
    printf("Ha ocurrido un error al abrir el fichero");
    system("PAUSE");
    system("cls");
    menu();
}//fin funcion acerca

puntajes(){
    FILE *fichero;

    if ((fichero=fopen("puntajes.dat","ab"))==NULL)
        printf("error al abrir el fichero\n");
    else{

        /* estructura de fecha y tiempo*/
        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        strftime(ingPunt.fecha,20,"%d/%m/%y %H:%M:%S",tlocal);


        fwrite(&ingPunt,sizeof(struct puntuacion),1,fichero);

    }
    fclose(fichero);
}//fin funcion puntajes

mostrarPuntajes(){
    system("CLS");
    FILE *fichero;

    if ((fichero=fopen("puntajes.dat","rb"))==NULL)
        printf("error al abrir el fichero\n");
    else{


        fread(&ingPunt,sizeof(struct puntuacion),1,fichero);
        printf("\n\tPUNTAJE\t\tNOMBRE\t\tFECHA\n");
        while (!feof(fichero)){
            printf("\n\t%d\t\t%s\t\t%s\n",ingPunt.puntaje,ingPunt.nombre,ingPunt.fecha);
            fread(&ingPunt,sizeof(struct puntuacion),1,fichero);
        }

    }
    fclose(fichero);
    system("PAUSE");
    system("cls");
    menu();
}//fin funcion mostrarPuntajes

cambiarJugador(){
    main();
}//fin fincion cambiarJugador
