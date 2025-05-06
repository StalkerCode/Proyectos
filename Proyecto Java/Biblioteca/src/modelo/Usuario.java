package modelo;

import java.util.ArrayList;
import java.util.Objects;

public class Usuario {
	private int idUsuario;
	private String nombre;
	private ArrayList<Integer> listaPrestamos;

	public Usuario(int idUsuario, String nombre) {
		this.idUsuario = idUsuario;
		this.nombre = nombre;
		this.listaPrestamos = new ArrayList<>();
	}

	public int getIdUsuario() {
		return idUsuario;
	}

	public void setIdUsuario(int idUsuario) {
		this.idUsuario = idUsuario;
	}

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	// metodo agregar libro
	public void agregarLibro(int idLibro) {
		listaPrestamos.add(idLibro);
	}

	// metodo devolver libro
	public boolean devolverLibro(int idLibro) {
		return listaPrestamos.remove((Integer) idLibro);
	}

	// listar libros prestados
	public ArrayList<Integer> listaLibros() {
		return new ArrayList<>(listaPrestamos);
	}

	@Override
	public int hashCode() {
		return Objects.hash(idUsuario, listaPrestamos, nombre);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Usuario other = (Usuario) obj;
		return idUsuario == other.idUsuario && Objects.equals(listaPrestamos, other.listaPrestamos)
				&& Objects.equals(nombre, other.nombre);
	}

	@Override
	public String toString() {
		return "idUsuario: " + idUsuario + "\nnombre: " + nombre + "\nlistaPrestamos: " + listaPrestamos + "\n";
	}
	
	

}
