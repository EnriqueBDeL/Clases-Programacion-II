//---------------------------------------------------------------------------------------------------------------------
// En este código aprenderás a configurar la localización para que el programa pueda mostrar caracteres especiales.
//---------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // librería que maneja la configuración regional.

int main() {

    setlocale(LC_ALL, ""); // permite que tu programa utilice la configuración regional del sistema.

    printf("¡Hola!\n\nAquí están las letras con acentos: á, é, í, ó y ú\nAquí está la letra eñe: ñ\n\n");

    return 0;
}
