package servicios;

import java.util.ArrayList;

import dominio.Pelicula;

public class ServiciosPeliculasLista implements IServiciosPeliculas {

	private  final ArrayList<Pelicula> listaPelicula;
	
	public ServiciosPeliculasLista() {
		this.listaPelicula = new ArrayList<>();
	}
	
	
	
	public ServiciosPeliculasLista(ArrayList<Pelicula> listaPelicula) {
		super();
		this.listaPelicula = listaPelicula;
	}



	@Override
	public void Lista_Pelicula() {
		System.out.println("Lista de la Peliculas");
		listaPelicula.forEach(System.out::println);
		
	}

	@Override
	public void Busqueda_Pelicula(Pelicula pelicula) {
		int indise = listaPelicula.indexOf(pelicula);
		if(indise!= -1) {
            System.out.println("Pelicula encontrada: "+pelicula);
        }else {
            System.out.println("Pelicula no encontrada");
        }
		
	}

	@Override
	public void Ingresar_Pelicula(Pelicula pelicula) {
		listaPelicula.add(pelicula);
		System.out.println("Se agrego: "+pelicula);
		
	}

}
