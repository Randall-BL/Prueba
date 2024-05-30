// Clase abstracta Car
abstract class Car {
    // Atributo protegido para almacenar el color del carro
    protected String color;

    // Método público para obtener el color del carro
    public String getColor() {return color;
    }

    // Método abstracto que será implementado por las clases concretas
    public abstract void displayCar();
}

// Clase concreta BlueCar que extiende la clase abstracta Car
class BlueCar extends Car {
    // Constructor que establece el color del carro
    public BlueCar() {
        this.color = "Blue";
    }

    // Implementación del método abstracto displayCar
    @Override
    public void displayCar() {
        System.out.println("This is a Blue Car.");
    }
}

// Clase concreta WhiteCar que extiende la clase abstracta Car
class WhiteCar extends Car {
    // Constructor que establece el color del carro
    public WhiteCar() {
        this.color = "White";
    }

    // Implementación del método abstracto displayCar
    @Override
    public void displayCar() {
        System.out.println("This is a White Car.");
    }
}

// Clase concreta PurpleCar que extiende la clase abstracta Car
class PurpleCar extends Car {
    // Constructor que establece el color del carro
    public PurpleCar() {
        this.color = "Purple";
    }

    // Implementación del método abstracto displayCar
    @Override
    public void displayCar() {
        System.out.println("This is a Purple Car.");
    }
}

// Clase concreta RedCar que extiende la clase abstracta Car
class RedCar extends Car {
    // Constructor que establece el color del carro
    public RedCar() {
        this.color = "Red";
    }

    // Implementación del método abstracto displayCar
    @Override
    public void displayCar() {
        System.out.println("This is a Red Car.");
        // Agrega una línea de debug después de imprimir el mensaje para verificar que el flujo continúa
        System.out.println("Displayed the car information.");
    }    
}
