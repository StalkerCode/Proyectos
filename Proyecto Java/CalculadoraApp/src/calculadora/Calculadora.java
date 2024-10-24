package calculadora;

import java.io.PrintStream;
import java.util.Scanner;

public class Calculadora {
	private static Scanner Entrada = new Scanner(System.in);
	private static PrintStream Salida = new PrintStream(System.out);

	public void menu() {
		Salida.println("**** Aplicacion de Calculadora ****");
		Salida.println("1. Suma");
		Salida.println("2. Resta");
		Salida.println("3. Multiplicacion");
		Salida.println("4. Division");
		Salida.println("5. Salir");
	}

	public Double NumeroReal() {

		Double numero;
		while (true) {
			Salida.print("Por favor, ingrese un número Real: ");
			if (Entrada.hasNextInt()) {
				numero = Entrada.nextDouble();
				break;
			} else {
				Salida.println("Entrada inválida. Asegúrese de ingresar un número entero.");
				Entrada.next(); // Limpiar el valor incorrecto ingresado
			}
		}

		return numero;

	}

	public int pedirNumeroEntero() {
		int numero;
		while (true) {
			Salida.print("Por favor, ingrese una opción: ");
			if (Entrada.hasNextInt()) {
				numero = Entrada.nextInt();
				break;
			} else {
				Salida.println("Entrada inválida. Asegúrese de ingresar un número entero.");
				Entrada.next(); // Limpiar el valor incorrecto ingresado
			}
		}

		return numero;
	}

	public Double sumar(Double num1, Double num2) {
		return num1 + num2;
	}

	public Double restar(Double num1, Double num2) {
		return num1 - num2;
	}

	public Double multiplicar(Double num1, Double num2) {
		return num1 * num2;
	}

	public Double dividir(Double num1, Double num2) {
		if (num2 == 0) {
			Salida.println("Error.\nNo se puede dividir entre 0.");
			return null;
		}
		return num1 / num2;
	}

	public void salir() {
		Salida.println("Gracias por usar la calculadora. Adiós!");
	}

	public void operarSuma() {
		Double num1 = NumeroReal();
		Double num2 = NumeroReal();
		Double resultado = sumar(num1, num2);
		Salida.println("\nEl resultado de la suma es: " + resultado);
	}

	public void operarResta() {
		Double num1 = NumeroReal();
		Double num2 = NumeroReal();
		Double resultado = restar(num1, num2);
		Salida.println("\nEl resultado de la resta es: " + resultado);
	}

	public void operarMultiplicacion() {
		Double num1 = NumeroReal();
		Double num2 = NumeroReal();
		Double resultado = multiplicar(num1, num2);
		Salida.println("\nEl resultado de la multiplicación es: " + resultado);
	}

	public void operarDivision() {
		Double num1 = NumeroReal();
		Double num2 = NumeroReal();
		Double resultado = dividir(num1, num2);
		if (resultado != null) {
			Salida.println("\nEl resultado de la division es: " + resultado);
		}
	}

}
