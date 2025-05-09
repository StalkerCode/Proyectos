package servicio;

import java.util.ArrayList;
import java.util.List;
import modelo.*;

public class BibliotecaService {
	private List<Libro> listaLibros;
	private List<Prestamos> listaPrestamos;
	private List<Usuario> listaUsuario;

	public BibliotecaService() {
		this.listaLibros = new ArrayList<>();
		this.listaPrestamos = new ArrayList<>();
		this.listaUsuario = new ArrayList<>();
	}

	public void agregarLibro(Libro libro) {
		this.listaLibros.add(libro);
	}

	public void agregarPrestamo(Prestamos prestamo) {
		this.listaPrestamos.add(prestamo);
	}

	public void agregarUsuario(Usuario usuario) {
		this.listaUsuario.add(usuario);
	}

	public List<Libro> listarLibros() {
		return this.listaLibros;
	}

	public List<Prestamos> listarPrestamos() {
		return this.listaPrestamos;
	}

	public List<Usuario> listarUsuarios() {
		return this.listaUsuario;
	}
	
	public void devolverLibro(Libro libro) {
		this.listaLibros.remove(libro);
	}
	
	public void devolverPrestamo(Prestamos prestamo) {
		this.listaPrestamos.remove(prestamo);
	}
	
	public void devolverUsuario(Usuario usuario) {
		this.listaUsuario.remove(usuario);
	}
	
	public Libro buscarLibro(String titulo) {
		for (Libro libro : this.listaLibros) {
			if (libro.getTitulo().equals(titulo.trim())) {
				return libro;
			}
		}
		return null;
	}
	
	public Prestamos buscarPrestamo(int idPrestamo) {
		for (Prestamos prestamo : this.listaPrestamos) {
			if (prestamo.getIdPrestamo() == idPrestamo) {
				return prestamo;
			}
		}
		return null;
	}
	
	public Usuario buscarUsuario(int idUsuario) {
		for (Usuario usuario : this.listaUsuario) {
			if (usuario.getIdUsuario() == idUsuario) {
				return usuario;
			}
		}
		return null;
	}
	
}
