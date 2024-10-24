package mainApp;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

import persona.Persona;

public class ListaPersonaMain {
	static Scanner entradas = new Scanner(System.in);
	static PrintStream salida = new PrintStream(System.out);

	public static void main(String[] args) {
		ArrayList<Persona> listaPersonas = new ArrayList<Persona>();
		int op;
		do {
			menu();
			op = leerEntero();
			switch (op) {
			case 1:
				agregarPersona(listaPersonas);
				break;
			case 2:
				listarPersonas(listaPersonas);
				break;
			case 3:
				salida.println("\nHasta luego");
				break;
			default:
				salida.println("\nOpcion no valida.\n");

			}

		} while (op != 3);
		salida.println("\n **** Fin del Programa ****");
		entradas.close();
		salida.close();
		System.gc();

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
