package app;

import java.io.PrintStream;
import java.util.Scanner;
import modelo.*;
import servicio.*;

public class App {
	private PrintStream salida = new PrintStream(System.out);
	private Scanner entrada = new Scanner(System.in);

	private BibliotecaService bibliotecaService = new BibliotecaService();

	public static void main(String[] args) {
		System.out.println("Hello World!");
	}

	public int crearNumero() {
		int numero;
		while (true) {
			try {
				salida.print(": ");
				numero = entrada.nextInt();
				return numero;
			} catch (Exception e) {
				salida.println("Error: " + e.getMessage());
			}
		}
	}

	public void menuLibros() {
		int opcion;
		do {
			salida.println("1. Crear libro");
			salida.println("2. Buscar libro");
			salida.println("3. Devolver libro");
			salida.println("4. Listar libros");
			salida.println("5. Salir");
			salida.print("Opcion: ");
			opcion = crearNumero();
			switch (opcion) {
			case 1:
				crearLibro();
				break;
			case 2:
				buscarLibro();
				break;
			case 3:
				devolverLibro();
				break;
			case 4:
				listarLibros();
				break;
			case 5:
				salida.println("Saliendo...");
				break;
			default:
				salida.println("Opcion no valida");
			}
		} while (opcion != 5);

	}

	public void crearLibro() {
		String titulo, autor, anoPublicacion;
		int totalEjemplares;
		salida.print("Proporciona el titulo: ");
		titulo = entrada.nextLine();
		salida.print("Proporciona el autor: ");
		autor = entrada.nextLine();
		salida.print("Proporciona el autor: ");
		anoPublicacion = entrada.nextLine();
		salida.print("Numero de ejemplares: ");
		totalEjemplares = crearNumero();
		bibliotecaService.agregarLibro(new Libro(titulo, autor, anoPublicacion, totalEjemplares));

	}

	public void buscarLibro() {
		String titulo;
		salida.print("Proporciona el titulo: ");
		titulo = entrada.nextLine();
		Libro libro = bibliotecaService.buscarLibro(titulo);
		if (libro != null) {
			salida.println(libro);
		} else {
			salida.println("Libro no encontrado");
		}
	}

	public void devolverLibro() {
		String titulo;
		salida.print("Proporciona el titulo: ");
		titulo = entrada.nextLine();
		Libro libro = bibliotecaService.buscarLibro(titulo);
		if (libro != null) {
			bibliotecaService.devolverLibro(libro);
		} else {
			salida.println("Libro no encontrado");
		}
	}

	public void listarLibros() {
		for (Libro libro : bibliotecaService.listarLibros()) {
			salida.println(libro);
		}
	}

	public void crearUsuario() {
		String nombre;
		salida.print("Proporciona el nombre: ");
		nombre = entrada.nextLine();
		bibliotecaService.agregarUsuario(new Usuario(nombre));
	}

	public void listarUsuarios() {
		for (Usuario usuario : bibliotecaService.listarUsuarios()) {
			salida.println(usuario);
		}
	}

	public void buscarUsuario() {
		int id;
		salida.print("Proporciona el id: ");
		id = crearNumero();
		Usuario usuario = bibliotecaService.buscarUsuario(id);
		if (usuario != null) {
			salida.println(usuario);
		} else {
			salida.println("Usuario no encontrado");
		}
	}

	public void devolverUsuario() {
		int id;
		salida.print("Proporciona el id: ");
		id = crearNumero();
		Usuario usuario = bibliotecaService.buscarUsuario(id);
		if (usuario != null) {
			bibliotecaService.devolverUsuario(usuario);
		} else {
			salida.println("Usuario no encontrado");
		}
	}

	public void menuUsuarios() {
		int opcion;
		do {
			salida.println("1. Crear usuario");
			salida.println("2. Buscar usuario");
			salida.println("3. Devolver usuario");
			salida.println("4. Listar usuarios");
			salida.println("5. Salir");
			salida.print("Opcion: ");
			opcion = crearNumero();
			switch (opcion) {
			case 1:
				crearUsuario();
				break;
			case 2:
				buscarUsuario();
				break;
			case 3:
				devolverUsuario();
				break;
			case 4:
				listarUsuarios();
				break;
			case 5:
				salida.println("Saliendo...");
				break;
			default:
				salida.println("Opcion no valida");
			}
		} while (opcion != 5);
	}

}
