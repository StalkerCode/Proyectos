package modelo;

import java.util.Objects;

public class Prestamos {
	private int idPrestamo;
	private int idLibro;
	private int idUsuario;
	private String fechaPrestamo;
	private String fechaDevolucion;

	public Prestamos(int idPrestamo, int idLibro, int idUsuario, String fechaPrestamo) {
		this.idPrestamo = idPrestamo;
		this.idLibro = idLibro;
		this.idUsuario = idUsuario;
		this.fechaPrestamo = fechaPrestamo;
		this.fechaDevolucion = null;
	}

	public int getIdPrestamo() {
		return idPrestamo;
	}

	public int getIdLibro() {
		return idLibro;
	}

	public int getIdUsuario() {
		return idUsuario;
	}

	public String getFechaPrestamo() {
		return fechaPrestamo;
	}

	public String getFechaDevolucion() {
		return fechaDevolucion;
	}

	public void setFechaDevolucion(String fechaDevolucion) {
		this.fechaDevolucion = fechaDevolucion;
	}

	@Override
	public int hashCode() {
		return Objects.hash(fechaDevolucion, fechaPrestamo, idLibro, idPrestamo, idUsuario);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Prestamos other = (Prestamos) obj;
		return Objects.equals(fechaDevolucion, other.fechaDevolucion)
				&& Objects.equals(fechaPrestamo, other.fechaPrestamo) && idLibro == other.idLibro
				&& idPrestamo == other.idPrestamo && idUsuario == other.idUsuario;
	}

}
