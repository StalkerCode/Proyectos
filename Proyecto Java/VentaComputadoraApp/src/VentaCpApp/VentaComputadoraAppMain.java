package VentaCpApp;

import java.io.PrintStream;
import java.util.Scanner;

import computadora.*;
import dispositivos.*;

public class VentaComputadoraAppMain {
	static Scanner in = new Scanner(System.in);
	static PrintStream out = new PrintStream(System.out);

	public static void main(String[] args) {

		out.println("Bienvenido, listo para crear tu orden");
		

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

}
