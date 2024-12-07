package servicios;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

import dominio.Pelicula;

public class ServiciosPeliculaArchivo implements IServiciosPeliculas {
	private final String NOMBRE_AR = "peliculas.txt";

	public ServiciosPeliculaArchivo() {
		File archivo = new File(NOMBRE_AR);
		try {
			if (!archivo.exists()) {
				archivo.createNewFile();
				System.out.println("El archivo '" + archivo.getAbsolutePath() + "' ha sido creado.");
			}
			// Si el archivo ya existe, abrirlo para lectura y escritura
			//PrintWriter Control_ar= new PrintWriter(new FileWriter(archivo));
			//Control_ar.close();
			
		} catch (IOException e) {
			System.err.println("Error al crear/abrir el archivo: " + archivo.getAbsolutePath());
			;
		}
	}

	@Override
	public void Lista_Pelicula() {
		// TODO Auto-generated method stub

	}

	@Override
	public void Busqueda_Pelicula(Pelicula pelicula) {
		// TODO Auto-generated method stub

	}

	@Override
	public void Ingresar_Pelicula(Pelicula pelicula) {
		// TODO Auto-generated method stub

	}

}
