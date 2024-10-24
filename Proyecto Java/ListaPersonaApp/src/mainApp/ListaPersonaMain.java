package mainApp;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

import persona.Persona;

public class ListaPersonaMain {
	static Scanner entradas = new Scanner(System.in);
	static PrintStream salida = new PrintStream(System.out);

	public static void main(String[] args) {

	}

	// Metodo menu
	static void menu() {
		salida.println("*** Listado Persona ***");
		salida.println("1. Agrgar");
		salida.println("2. Listar");
		salida.println("3. Salir");
	}

}
