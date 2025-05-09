package modelo;

import java.util.Objects;

public class Libro {
	private int idLibro;
	private String titulo;
	private String autor;
	private String anoPublicacion;
	private int totalEjemplares ;
	private int ejemplaresRestantes;
	private static int id=0;
	
	public Libro(String titulo, String autor, String anoPublicacion, int totalEjemplares) {
		this.idLibro = ++id;
		this.titulo = titulo;
		this.autor = autor;
		this.anoPublicacion = anoPublicacion;
		this.totalEjemplares = totalEjemplares;
		this.ejemplaresRestantes = totalEjemplares;
	}

	public int getIdLibro() {
		return idLibro;
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

	public String getAnoPublicacion() {
		return anoPublicacion;
	}

	public void setAnoPublicacion(String anoPublicacion) {
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
