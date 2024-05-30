// Clase abstracta CarFactory
abstract class CarFactory {
    // Método abstracto para crear un carro
    public abstract Car createCar();
}

// Clase concreta BlueCarFactory que extiende CarFactory
class  BlueCarFactory extends CarFactory {
    // Implementación del método abstracto createCar que crea un BlueCar
    @Override
    public Car createCar() {
        return new BlueCar();
    }
}

// Clase concreta WhiteCarFactory que extiende CarFactory
class WhiteCarFactory extends CarFactory {
    // Implementación del método abstracto createCar que crea un WhiteCar
    @Override
    public Car createCar() {
        return new WhiteCar();
    }
}

// Clase concreta PurpleCarFactory que extiende CarFactory
class PurpleCarFactory extends CarFactory {
    // Implementación del método abstracto createCar que crea un PurpleCar
    @Override
    public Car createCar() {
        return new PurpleCar();
    }
}

// Clase concreta RedCarFactory que extiende CarFactory
class RedCarFactory extends CarFactory {
    // Implementación del método abstracto createCar que crea un RedCar
    @Override
    public Car createCar() {
        return new RedCar();
    }
}

// Clase CarFactoryProducer para obtener la fábrica adecuada basada en el color
class CarFactoryProducer {
    // Método estático para obtener la fábrica correspondiente al color especificado
    public static CarFactory getFactory(String color) {
        // Selecciona la fábrica adecuada basada en el color
        switch (color.toLowerCase()) {
            case "blue":
                return new BlueCarFactory();
            case "white":
                return new WhiteCarFactory();
            case "purple":
                return new PurpleCarFactory();
            case "red":
                return new RedCarFactory();
            // Lanza una excepción si el color no es reconocido
            default:
                throw new IllegalArgumentException("Carro desconocido loca: " + color);
        }
    }
}
