# Zona Activa

Descripción
---------
Proyecto de consola en C++ para la gestión de canchas, clientes, reservas y registro de espera. Implementa entidades y colecciones simples sin uso de la STL, pensado para un curso introductorio de programación en C++.

Requisitos
---------
- Microsoft Visual Studio (se probó en Visual Studio Community 2026).
- Compilador C++ compatible con C++98/C++11 mínimo.
- Sólo se usan las cabeceras <iostream> y <string> (según las reglas del proyecto).

Estructura del proyecto
-----------------------
- Archivos de encabezado/: archivos .h (declaraciones de clases).
- Archivos de origen/: archivos .cpp (implementaciones).
- main.cpp: función main() limpia que instancia la clase Menu y arranca la aplicación.
- Los archivos que empiezan con el nombre "Zona Activa" independientemente de su extensión no cumplen ninguna función especifica en el proyecto, son un requisito para poder ejecutarlo y puede fallar tras su eliminación, se recomienda dejarlos como están e ignorarlos

Clases principales
------------------
- Cancha: código, deporte, precioPorHora y char franjas[12] ('L','O','M').
- Cliente: id, nombreCompleto, telefono.
- Reserva: consecutivo automático, Cliente*, Cancha*, franjaInicio, cantidadHoras, montoTotal, estado.
- RegistroEspera: consecutivo, Cliente*, Cancha*, posicionFranja, estado.
- Colección de cada entidad: ColeccionCanchas (máx 10), ColeccionClientes (máx 100), ColeccionReservas (capacidad configurable), ColeccionEspera (máx 10).
- Reportes: cálculos estadísticos (cancha más reservada, cliente más frecuente, ingresos, porcentaje ocupación, franjas más/menos demandadas).
- Menu: interfaz de consola con validación de entradas (cin.clear(), cin.ignore()).

Características y decisiones de diseño
------------------------------------
- No se utiliza std::vector ni otras colecciones de la STL; se usan arreglos dinámicos de punteros (new[] / delete[]).
- Las colecciones son responsables de liberar los objetos que contienen en su destructor (se eliminan los punteros almacenados y luego el arreglo), por lo que no debe eliminarse doblemente un objeto desde fuera si ya pertenece a una colección.
- Validaciones básicas: capacidades máximas, unicidad de códigos/IDs, franjas válidas (0..11).
- Entrada de usuario protegida: lectura robusta con cin.clear() y cin.ignore() para evitar bucles por entradas no numéricas.

Cómo compilar
--------------
1. Abrir la solución/proyecto en Visual Studio (abrir carpeta del repositorio o el archivo .sln si existe).
2. Añadir los archivos al proyecto si Visual Studio no los detecta automáticamente (Archivos de encabezado/ y Archivos de origen/).
3. Compilar (Build > Build Solution).

Cómo usar
---------
1. Ejecutar el binario desde Visual Studio (Start Debugging o Start Without Debugging) o desde la terminal apuntando al ejecutable generado.
2. El menú principal muestra las secciones: Gestión canchas, Gestión clientes, Reservas, Registro de espera, Reportes y Salir.
3. Seguir las instrucciones en pantalla. Todas las lecturas usan validación para evitar entradas erróneas.

Limitaciones y notas
--------------------
- No hay persistencia en disco: todos los datos viven en memoria durante la ejecución.
- Política de propiedad: las colecciones eliminan los objetos que contienen en su destructor. Evitar eliminar objetos manualmente si ya se añadieron a una colección.
- No hay control de concurrencia (apto solo para uso individual en consola).

Posibles mejoras
----------------
- Añadir persistencia (ficheros o base de datos).
- Mecanismo para promover automáticamente clientes desde la lista de espera al liberarse una franja.
- Tests unitarios y scripts de generación de datos de prueba.

Contacto
--------
Repositorio: https://github.com/Caasi-04/Zona-Activa

Licencia
--------
Contenido del proyecto: sin licencia explícita.

