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

}
