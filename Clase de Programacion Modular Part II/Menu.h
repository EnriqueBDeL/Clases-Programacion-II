#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
//-----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//|||||||||||||||||||||||||||||||||||
int Menu();
void Saludar (char nombre[100]);
void Definicion ();
//|||||||||||||||||||||||||||||||||||

/* (COMENTARIO)

    Es una buena práctica definir las funciones en un archivo de encabezado (.h) utilizando prototipos de función.

    Esto ayuda a proporcionar una interfaz clara y pública para las funciones,permitiendo que otros módulos
    conozcan cómo usarlas correctamente sin necesidad de conocer los detalles de implementación.

    Además, incluir las declaraciones de funciones en un archivo de encabezado puede
    ayudar a evitar warnings y errores de compilación relacionados con el enlace de funciones.

    Si las funciones se utilizan en varios archivos de código fuente, definirlas en un archivo de encabezado
    promueve la coherencia y facilita el mantenimiento del código

*/

//-----------------------------------------
#endif // MENU_H_INCLUDED
