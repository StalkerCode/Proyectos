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

}
