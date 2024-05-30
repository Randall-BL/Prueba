import java.net.*;
import java.io.*;
import java.util.Scanner;

public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(12345);
            System.out.println("Esperando clientes...");
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Cliente conectado");
                new ClientHandler(clientSocket).start();
            }
        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}

class ClientHandler extends Thread {
    private Socket clientSocket;
    private PrintWriter out;
    private BufferedReader in;

    public ClientHandler(Socket socket) {
        this.clientSocket = socket;
    }

    public void run() {
        try {
            out = new PrintWriter(clientSocket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            String mensaje;
            while ((mensaje = in.readLine()) != null) {
                System.out.println("Cliente dice: " + mensaje);

                // Procesar el mensaje para crear carro, etc.
                try {
                    CarFactory carFactory = CarFactoryProducer.getFactory(mensaje);
                    Car car = carFactory.createCar();
                    String response = car.getColor();  // Envia el color del carro escogido al cliente 
                    out.println(response);
                    out.println(response);
                    car.displayCar();
                    System.out.println("Hola");

                    // Después de "Hola", interactuar con la terminal del servidor para mostrar menú
                    presentMenu();
                } catch (IllegalArgumentException e) {
                    out.println("Error: " + e.getMessage());
                }
            }
        } catch (IOException e) {
            System.err.println("Error en la comunicación con el cliente: " + e.getMessage());
        } finally {
            try {
                in.close();
                out.close();
                clientSocket.close();
            } catch (IOException e) {
                System.err.println("Failed to close resources: " + e.getMessage());
            }
        }
    }

    private void presentMenu() {      
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Donde quiere colocar el objeto?");
            System.out.println("1- Km1");
            System.out.println("2- Km2");
            System.out.println("3- Km3");
            String locationChoice = scanner.nextLine();
    
            System.out.println("Cual objeto desea colocar?");
            System.out.println("1- Vida");
            System.out.println("2- Boost");
            System.out.println("3- Obstaculo");
            String objectChoice = scanner.nextLine();
    
            String combinedChoice = locationChoice + objectChoice;
            System.out.println("Opción seleccionada: " + combinedChoice);
    
            // Envía la respuesta combinada al cliente
            out.println(combinedChoice);
        }
    }    
}