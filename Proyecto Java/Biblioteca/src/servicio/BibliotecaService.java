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
}
