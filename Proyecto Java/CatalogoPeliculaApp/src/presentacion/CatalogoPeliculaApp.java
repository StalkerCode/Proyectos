package presentacion;

import java.io.PrintStream;
import java.util.Scanner;

import dominio.Pelicula;
import servicios.*;

public class CatalogoPeliculaApp {

	public static Scanner entrada = new Scanner(System.in);
	public static PrintStream salida = new PrintStream(System.out);

	public static void main(String[] args) {
		
		boolean salir = false;
		ServiciosPeliculasLista sp = new ServiciosPeliculasLista();
		while (!salir) {
			mostratMenu();
			int op = ingresarEntero();
			switch (op) {
			case 1:
				sp.Ingresar_Pelicula(cearPelicula());
				break;

			case 2:
				listarPeliculas(sp);
				break;

			case 3:
				buscarPelicula(sp);
				break;

			case 4:
				salir = true;
				salida.println("¡Hasta luego!");
				break;

			default:
				salida.println("Opcion incorrecta");
				break;

			}

		}
		salida.println("Fin del servicios");

		// Cerrar el scanner y el PrintStream
		entrada.close();
		salida.close();

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
				entrada.nextLine();
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

	private static void listarPeliculas(ServiciosPeliculasLista peliculas) {
		peliculas.Lista_Pelicula();
	}

	private static void buscarPelicula(ServiciosPeliculasLista peliculas) {
		Pelicula pelicula = cearPelicula();
		peliculas.Busqueda_Pelicula(pelicula);
	}

}
