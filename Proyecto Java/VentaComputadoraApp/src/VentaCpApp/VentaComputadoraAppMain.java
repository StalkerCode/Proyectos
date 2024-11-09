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
			op = opcionesOrden();
			switch (op) {
			case 1:
				orden = new Orden();
				funcionaminetoOrden();
				break;
			case 2:
				out.println("\nAdios\n");
				break;
			default:
				out.println("\nopcion erronea\n");
			}
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
		Double tamanio = in.nextDouble();
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

	static void funcionaminetoOrden() {
		int op;
		do {
			menuOrden();
			out.print("Elige la opcion: ");
			op = in.nextInt();
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
				out.println("\nopcion erronea\n");

			}
		}while(op!=3);
	}

	static int opcionesOrden() {
		int op;
		menu();
		out.print("Elige la opcion: ");
		op = in.nextInt();
		return op;
	}

}
