# Reglas Estrictas C++ (Proyecto I - Programación I)

## LIBRERÍAS PERMITIDAS
- ÚNICAMENTE se permite `#include <iostream>` y `#include <string>`.
- Se permite la línea `using namespace std;`.
- **PROHIBIDO:** `#include <vector>`, `#include <list>`, `#include <memory>`, o cualquier otro encabezado STL o avanzado.

## MANEJO DE COLECCIONES Y MEMORIA
- NO usar `std::vector`. Las listas/colecciones deben ser arreglos unidimensionales dinámicos de punteros creados con `new[]` y liberados con `delete[]`.
- Ejemplo de arreglo para colecciones: `Cancha** canchas = new Cancha*[10];` o `Cliente* clientes[100];`.
- PROHIBIDO usar herencia, polimorfismo, metodos virtuales, plantillas (templates) o listas enlazadas.
- Toda la sintaxis debe ser C++ básico introductorio.

## ESTRUCTURA DE ARCHIVOS
- Modularizar cada clase en un archivo `.h` (declaración) y `.cpp` (implementación).
- La función `main()` dentro de `main.cpp` debe ser muy limpia y solo iniciar el menú principal.

## ESTRUCTURA DEL PROYECTO "ZONA ACTIVA"
- **Cancha:** Código, tipo deporte, precio por hora, y un arreglo estático de 12 `char` (`char franjas[12]`) con valores 'L' (Libre), 'O' (Ocupada), 'M' (Mantenimiento).
- **Cliente:** Cédula/ID, Nombre completo, Teléfono.
- **Reserva:** Consecutivo automático, `Cliente*` (puntero), `Cancha*` (puntero), hora inicio (0 a 11), cantidad de horas, monto total, estado (1=Activa, 0=Cancelada).
- **RegistroEspera:** Consecutivo, `Cliente*`, `Cancha*`, posición franja, estado (1=Esperando, 2=Atendido, 3=Cancelado). Tamaño máximo de 10.
- **Colecciones:** Clases contenedor (`ColeccionCanchas`, `ColeccionClientes`, `ColeccionReservas`, `ColeccionEspera`) que administren los arreglos de punteros y contadores enteros de elementos guardados.