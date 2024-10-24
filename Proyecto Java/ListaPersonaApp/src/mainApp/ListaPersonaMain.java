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

	// metodo para ingresar un entero y evitar errores
	static int leerEntero() {
		salida.print("\nIngrese la opcion: ");
		int numero = 0;
		while (!entradas.hasNextInt()) {
			entradas.next();
			salida.println("\nDebe ingresar un número entero.");
			salida.print(": ");
		}
		numero = entradas.nextInt();
		return numero;
	}

	// metodo Crear persona
	static Persona crearPersona() {
		salida.print("\nIngrese nombre: ");
		String nombre = entradas.next();

		salida.print("Ingrese telefono: ");
		String telefono = entradas.next();

		salida.print("Ingrese email: ");
		String email = entradas.next();

		return new Persona(nombre, telefono, email);
	}

	// metodo para Agregar persona
	static void agregarPersona(ArrayList<Persona> lista) {
		lista.add(crearPersona());
		salida.println("");
	}

	// metodo para Listar personas
	static void listarPersonas(ArrayList<Persona> lista) {
		salida.println("\n*** Listado Persona ***");
		for (Persona persona : lista) {
			salida.println(persona);
		}
		salida.println("Total de personas: " + lista.size());
		salida.println("--------------------------------\n");
	}

}
