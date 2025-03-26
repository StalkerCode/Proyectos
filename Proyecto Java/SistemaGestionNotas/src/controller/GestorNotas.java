package controller;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import model.Nota;

public class GestorNotas {
	private List<Nota> notas = new ArrayList<Nota>();
	private int id=0;
	
	
	public void agregarNota(String titulo, String contenido) {
		Nota n= new Nota(++id, titulo, contenido) ;
		notas.add(n);
	}

	public void eliminarNota(int id){
		Iterator<Nota> iterator = notas.iterator();
        while (iterator.hasNext()) {
        	Nota nota = iterator.next();
            if (nota.getId() == id) {
                iterator.remove();
                break;
            }
        }
	}

	public void editarNota(int id, String nuevoContenido) {
		
	}

	public void listarNotas() {
		notas.forEach(System.out::println);

	}

	public void buscarNota(String titulo){
		
	}
	public static void main(String[] args) {
		GestorNotas notas = new GestorNotas();
		notas.agregarNota("sapo", "leer el sapo");
		notas.agregarNota("leo", "leer el leon");
		notas.agregarNota("tuyo", "leer la rata");
		notas.listarNotas();
		System.out.println();
		notas.eliminarNota(2);
		notas.listarNotas();
	}
}
