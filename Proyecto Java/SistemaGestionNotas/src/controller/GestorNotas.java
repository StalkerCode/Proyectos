package controller;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import model.Nota;

public class GestorNotas {
	private List<Nota> notas = new ArrayList<Nota>();
	private int id = 0;

	public void agregarNota(String titulo, String contenido) {

		// Verificar si ya existe una nota con el mismo título
		for (Nota nota : notas) {
			if (nota.getTitulo().equalsIgnoreCase(titulo)) {
				System.out.println("Ya existe una nota con el título: " + titulo);
				return; // Salir del método sin agregar la nota
			}
		}
		Nota n = new Nota(++id, titulo, contenido);
		notas.add(n);
	}

	public void eliminarNota(int id) {
		Iterator<Nota> iterator = notas.iterator();
		while (iterator.hasNext()) {
			Nota nota = iterator.next();
			if (nota.getId() == id) {
				iterator.remove();
				break;
			}
		}
	}

	public String editarNota(int id, String nuevoContenido) {
		
		for (Nota nota : notas) {
			if (nota.getId() == id) {
				nota.setContenido(nuevoContenido);
				return "se edito perfectamente la tarea: "+ id;
			}
		}
		return"no se encontro el id=" + id;

	}

	public List<Nota> listarNotas() {
		return notas;

	}

	public Nota buscarNota(String titulo) {
		for (Nota nota : notas) {
			if (nota.getTitulo().equalsIgnoreCase(titulo)) {
				return nota;
			}
		}
		return null;
	}

}
