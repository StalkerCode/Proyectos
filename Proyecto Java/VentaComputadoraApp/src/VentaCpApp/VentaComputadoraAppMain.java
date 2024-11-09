package VentaCpApp;

import java.io.PrintStream;
import java.util.Scanner;

import computadora.*;
import dispositivos.*;
import orden.Orden;

public class VentaComputadoraAppMain {
	static Scanner in = new Scanner(System.in);
	static PrintStream out = new PrintStream(System.out);
	static Orden orden;

	public static void main(String[] args) {
		int op;
		out.println("Bienvenido, listo para crear tu orden");
		do {
			menu();
			op = ingresarEntero();
			switch (op) {
			case 1:
				orden = new Orden();
				funcionesOrden();
				orden = null;
				System.gc();
				break;
			case 2:
				out.println("\nAdios\n");
				break;
			default:
				out.println("\nopcion incorrecta\n");
				break;
			}
			out.println("");

		} while (op != 2);

	}

	static Teclado crearTeclado() {
		out.println("Creardo Teclado:");
		out.print("Marca: ");
		String marca = in.next();
		out.print("Tipo de entrada: ");
		String tipo = in.next();
		return new Teclado(tipo, marca);
	}

	static Raton crearRaton() {
		out.println("Creardo Raton:");
		out.print("Marca: ");
		String marca = in.next();
		out.print("Tipo de entrada: ");
		String tipo = in.next();
		return new Raton(tipo, marca);
	}

	static Monitor crearMonitor() {
		out.println("Creardo Monitor:");
		out.print("Marca: ");
		String marca = in.next();
		out.print("Tamanio en pulg^2: ");
		Double tamanio = ingresarReal();
		return new Monitor(marca, tamanio);
	}

	static Computadora crearComputadora() {
		out.println("Creardo Computdor:");
		out.print("Nombre: ");
		String nombre = in.next();
		return new Computadora(nombre, crearMonitor(), crearTeclado(), crearRaton());
	}

	static void menuOrden() {
		out.println("Menu");
		out.println("1. agregar compuatora");
		out.println("2. mostrar orden");
		out.println("3. Salir");
	}

	static void menu() {
		out.println("Menu");
		out.println("1. Crear orden");
		out.println("2. salir");
	}

	static void imprimirOrden() {
		out.println("\nOrden #" + orden.getIdOrden());
		for (Computadora cp : orden.getComputadoras()) {
			out.println(cp);
		}
		out.println("----------------\n");
	}

	static int ingresarEntero() {
		int op;
		while (true) {
			try {
				out.print("ingrese opcion: ");
				op = in.nextInt();
				out.println("");
				break;
			} catch (Exception e) {
				out.println("\ndato erroneo\n");
				in.nextLine();
			}
		}
		return op;
	}

	static double ingresarReal() {
		double op;
		while (true) {
			try {
				out.print("dato: ");
				op = in.nextDouble();
				break;
			} catch (Exception e) {
				out.println("\ndato erroneo\n");
				in.nextLine();
			}
		}
		return op;
	}

	static void funcionesOrden() {
		int op;
		do {
			menuOrden();
			op = ingresarEntero();
			opcionesOrden(op);
			out.println("");

		} while (op != 3);
	}

	static void opcionesOrden(int op) {
		switch (op) {
		case 1:
			orden.agregarComputadora(crearComputadora());
			break;
		case 2:
			imprimirOrden();
			break;
		case 3:
			out.println("\nHasta luego\n");
			break;
		default:
			out.println("\nopcion incorrecta\n");
			break;

		}
	}

}
