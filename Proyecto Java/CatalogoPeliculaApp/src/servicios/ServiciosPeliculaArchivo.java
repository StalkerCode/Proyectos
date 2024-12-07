package servicios;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

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

		} catch (IOException e) {
			System.err.println("Error al crear/abrir el archivo: " + archivo.getAbsolutePath());
		}
	}

	@Override
	public void Lista_Pelicula() {
		// mostrar las peliculas
		File archivo = new File(NOMBRE_AR);
		// leer cada linea y mostrar el nombre de la pelicula
		try {
			BufferedReader br = new BufferedReader(new FileReader(archivo));
            String line;
            line = br.readLine();
            while (line != null) {
                System.out.println(line);
                line = br.readLine();
            }
        } catch (IOException e) {
            System.err.println("Error al leer el archivo: " + archivo.getAbsolutePath());
        }

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
