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
            System.out.println(pelicula + " esta en el puesto: "+ indise);
        }else {
            System.out.println("Pelicula no encontrada");
        }
		
	}

	@Override
	public void Ingresar_Pelicula(Pelicula pelicula) {
		listaPelicula.add(pelicula);
		System.out.println("Se agrego: "+pelicula);
		
	}
	
	/*public static void main(String[] args) {
		ServiciosPeliculasLista sp = new ServiciosPeliculasLista();
        sp.Ingresar_Pelicula(new Pelicula("El Padrino"));
        sp.Ingresar_Pelicula(new Pelicula("La Casa de Papel"));
        sp.Ingresar_Pelicula(new Pelicula("El Señor de los Anillos"));
        
        sp.Lista_Pelicula();
        sp.Busqueda_Pelicula(new Pelicula("El Padrino"));
	}*/

}
