cmake_minimum_required(VERSION 3.25)
project(ClienteCliente C)

set(CMAKE_C_STANDARD 11)

#busqueda de csfml
find_package(SFML COMPONENTS graphics REQUIRED)

#incluye directorio del csfml
include_directories(${SFML_INCLUDE_DIR})

# Agrega la ruta de inclusión de Winsock
include_directories(C:/Program Files/JetBrains/CLion 2023.1.3/bin/mingw/x86_64-w64-mingw32/include)

# Añade tu ejecutable
add_executable(ClienteCliente model/main.c model/client.c headers/client.h
        headers/ventanaprueba.h
        model/Ventanaprueba.c
        headers/Ventanaprueba.h
        model/Ventanaprueba.c
        model/Ventana_inicio.c
        headers/Ventana_inicio.h
        headers/Ventana_inicio.h
        headers/Ventana_Juego.h
        model/Ventana_Juego.c
        headers/Jugador_1.h
        model/Jugador_1.c
        model/Jugador_2.c
        headers/Jugador_2.h
        model/Jugador_3.c
        headers/Jugador_3.h
        model/Mapa_1.c
        headers/Mapa_1.h
        model/Mapa_2.c
        headers/Mapa_2.h
        model/Mapa_3.c
        headers/Mapa_3.h
)

# Link against the ws2_32 library
target_link_libraries(ClienteCliente ws2_32)

#linkea las librerias delcsfml
target_link_libraries(ClienteCliente -lcsfml-graphics -lcsfml-system -lcsfml-window)



