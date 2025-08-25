#include <stdio.h>
#include <glib.h>   // necesario para usar GList

int main(void) {
    GList *lista = NULL;  // lista vacía

    // Agregar elementos a la lista (al final)
    lista = g_list_append(lista, "Hola");
    lista = g_list_append(lista, "Mundo");
    lista = g_list_append(lista, "GLib");

    // Recorrer e imprimir
    printf("Elementos en la lista:\n");
    for (GList *l = lista; l != NULL; l = l->next) {
        printf(" - %s\n", (char *)l->data);
    }

    // Obtener tamaño de la lista
    printf("La lista tiene %d elementos.\n", g_list_length(lista));

    // Acceder por índice
    char *segundo = (char *)g_list_nth_data(lista, 1);
    printf("El segundo elemento es: %s\n", segundo);

    // Liberar la lista (OJO: no libera las cadenas si fueran malloc)
    g_list_free(lista);

    return 0;
}
