package mainApp;

import java.io.PrintStream;
import java.util.Scanner;

import calculadora.Calculadora;

public class CalculadoraMain {
	static Scanner Entrada = new Scanner(System.in);
	static PrintStream Salida = new PrintStream(System.out);

	public static void main(String[] args) {
		int op;
		Calculadora cal = new Calculadora();
		do {
			cal.menu();
			switch (op = cal.pedirNumeroEntero()) {
			case 1:
				cal.operarSuma();
				Salida.println("");
				break;

			case 2:
				cal.operarResta();
				Salida.println("");
				break;

			case 3:
				cal.operarMultiplicacion();
				Salida.println("");
				break;

			case 4:
				cal.operarDivision();
				Salida.println("");
				break;

			case 5:
				cal.salir();
				break;

			default:
				Salida.println("Opción incorrecta. Intente nuevamente.");
				Salida.println("");
				break;
			}
		} while (op != 5);
		
		Salida.println("\n**** Fin del Programa ****");

	}

}
