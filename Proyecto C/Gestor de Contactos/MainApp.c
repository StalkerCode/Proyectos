#include <stdio.h>
#include "listaContactos.c"

int main()
{
	ListaContactos *cabeza = NULL;
	insertarAlFinal(&cabeza);
	insertarAlFinal(&cabeza);
	insertarAlPrincipio(&cabeza);
	printf("\nse imrpime la lista de contactos\n");
	imprimirContactos(cabeza);
	printf("\nse elimina el contacto sapo\n");
	eliminarContactoPorNombre(&cabeza, "sapo");
	printf("\nse imrpime la lista de contactos\n");
	imprimirContactos(cabeza);
	printf("\nse modifica el contacto marlon\n");
	modificarContacto(cabeza, "marlon");
	printf("\nse imrpime la lista de contactos\n");
	imprimirContactos(cabeza);
	printf("\nse guardan los contactos en el archivo contactos.txt\n");
	guardarContactosEnArchivo(cabeza, "contactos.txt");
	printf("\nse cargan los contactos del archivo contactos.txt\n");
	ListaContactos *cabezaCargada = cargarContactosDeArchivo("contactos.txt");
	printf("\nse imrpime la lista de contactos cargados\n");
	imprimirContactos(cabezaCargada);
	eliminarLista(&cabeza);

	return 0;
}
