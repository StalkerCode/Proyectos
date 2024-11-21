package presentacion;

import java.io.PrintStream;
import java.util.Scanner;

import dominio.Pelicula;
import servicios.ServiciosPeliculasLista;

public class CatalogoPeliculaApp {

	public static Scanner entrada = new Scanner(System.in);
	public static PrintStream salida = new PrintStream(System.out);

	public static void main(String[] args) {
		boolean salir = false;
		ServiciosPeliculasLista sp = new ServiciosPeliculasLista();
		while(!salir) {
			mostratMenu();
			ingresarEntero();
		}
		
	}

	private static void mostratMenu() {
		salida.print("""
				*** Menu Peliculas ***
				1.) Agregar pelicula
				2.) Listar pelicula
				3.) Buscar pelicula
				4.) salir
				""");
	}

	private static int ingresarEntero() {

		while (true) {
			try {
				salida.print("opcion:");
				int num = entrada.nextInt();
				salida.println();
				return num;

			} catch (Exception e) {
				salida.println("Vuelve a intentarlo");
				entrada.nextLine();
			}
		}
	}
	
	private static Pelicula cearPelicula() {
		salida.print("nombre: ");
		return new Pelicula(entrada.nextLine());
	}
}
