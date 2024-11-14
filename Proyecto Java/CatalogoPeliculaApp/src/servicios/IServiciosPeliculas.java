package servicios;

import dominio.Pelicula;

public interface IServiciosPeliculas {
	public void Lista_Pelicula();

	public void Busqueda_Pelicula(Pelicula pelicula);

	public void Ingresar_Pelicula(Pelicula pelicula);
}
