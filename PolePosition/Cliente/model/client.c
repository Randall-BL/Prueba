#include "../headers/client.h"
#include "../headers/Ventana_inicio.h"
#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
#include <process.h>  // Para _beginthreadex

#include "../headers/Ventana_Juego.h"

int sockfd;

// Función que se ejecutará en un hilo separado para leer mensajes del servidor
unsigned __stdcall LeerMensajesServer(void* arg) {
    char buffer[1024];
    int bytesReceived;

    while ((bytesReceived = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytesReceived] = '\0'; // Asegurarse de que el string es NULL-terminated
        printf("Mensaje recibido del servidor: %s\n", buffer);
    }

    if (bytesReceived == 0) {
        printf("El servidor cerró la conexión\n");
    } else {
        printf("Error al recibir datos: %d\n", WSAGetLastError());
    }

    return 0;
}

void connectAndSetupWindow() {
    WSADATA wsaData;
    struct sockaddr_in serverAddr;

    // Inicializamos Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Winsock initialization failed.\n");
        return;
    }

    // Creación del socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET) {
        printf("Failed to create socket: %d\n", WSAGetLastError());
        WSACleanup();
        return;
    }

    // Configuración del servidor
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Conexión al servidor
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("Connection failed.\n");
        closesocket(sockfd);
        WSACleanup();
        return;
    }
    printf("Connected to server successfully.\n");

    // Crear un hilo para leer mensajes del servidor
    HANDLE hThread;
    hThread = (HANDLE)_beginthreadex(NULL, 0, LeerMensajesServer, NULL, 0, NULL);
    if (hThread == NULL) {
        printf("Failed to create thread for reading messages.\n");
        closesocket(sockfd);
        WSACleanup();
        return;
    }

    // Crear y manejar la ventana con el mapa
    Ventana_inicio* ventana_inicio = crearVentanaInicio();

    // Limpieza después de cerrar la ventana
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);
    closesocket(sockfd);
    WSACleanup();
}