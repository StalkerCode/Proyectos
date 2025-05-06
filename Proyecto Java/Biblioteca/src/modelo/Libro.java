package modelo;

import java.util.Objects;

public class Libro {
	private int idLibro;
	private String titulo;
	private String autor;
	private int anoPublicacion;
	private int totalEjemplares ;
	private int ejemplaresRestantes;
	
	public Libro(int idLibro, String titulo, String autor, int anoPublicacion, int totalEjemplares) {
		this.idLibro = idLibro;
		this.titulo = titulo;
		this.autor = autor;
		this.anoPublicacion = anoPublicacion;
		this.totalEjemplares = totalEjemplares;
		this.ejemplaresRestantes = totalEjemplares;
	}

	public int getIdLibro() {
		return idLibro;
	}

	public void setIdLibro(int idLibro) {
		this.idLibro = idLibro;
	}

	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public String getAutor() {
		return autor;
	}

	public void setAutor(String autor) {
		this.autor = autor;
	}

	public int getAnoPublicacion() {
		return anoPublicacion;
	}

	public void setAnoPublicacion(int anoPublicacion) {
		this.anoPublicacion = anoPublicacion;
	}

	public int getTotalEjemplares() {
		return totalEjemplares;
	}

	public void setTotalEjemplares(int totalEjemplares) {
		this.totalEjemplares = totalEjemplares;
	}

	public int getEjemplaresRestantes() {
		return ejemplaresRestantes;
	}

	public void setEjemplaresRestantes(int ejemplaresRestantes) {
		this.ejemplaresRestantes = ejemplaresRestantes;
	}

	@Override
	public int hashCode() {
		return Objects.hash(anoPublicacion, autor, ejemplaresRestantes, idLibro, titulo, totalEjemplares);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Libro other = (Libro) obj;
		return anoPublicacion == other.anoPublicacion && Objects.equals(autor, other.autor)
				&& ejemplaresRestantes == other.ejemplaresRestantes && idLibro == other.idLibro
				&& Objects.equals(titulo, other.titulo) && totalEjemplares == other.totalEjemplares;
	}

	@Override
	public String toString() {
		return "\ndLibro=" + idLibro + 
				"\ntitulo=" + titulo + "\nautor=" + autor + 
				"\nanoPublicacion=" + anoPublicacion + 
				"\ntotalEjemplares=" + totalEjemplares + 
				"\nejemplaresRestantes="+ ejemplaresRestantes+"\n";
	}
	
}
