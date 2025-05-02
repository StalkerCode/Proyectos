package modelo;

import java.util.ArrayList;

public class Usuario {
	private int idUsuario;
	private String nombre;
	private  ArrayList<Integer> listaPrestamos;
	
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
	// metodo devolver libro
	// listar libros prestados

}
