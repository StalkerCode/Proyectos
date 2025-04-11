package model;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Objects;

public class Nota {
	private int id;
	private String titulo;
	private String contenido;
	private LocalDateTime fechaCreacion;

	public Nota(int id) {
		this.id = id;
	}

	public Nota(int id, String titulo, String contenido) {
		this.id = id;
		this.titulo = titulo;
		this.contenido = contenido;
		this.fechaCreacion= LocalDateTime.now();
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");
        fechaCreacion.format(formatter);
	}

	public int getId() {
		return id;
	}

	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public String getContenido() {
		return contenido;
	}

	public void setContenido(String contenido) {
		this.contenido = contenido;
	}

	public LocalDateTime getFechaCreacion() {
		return fechaCreacion;
	}
	public String formatoFecha() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");
        return fechaCreacion.format(formatter);
    }

	@Override
	public String toString() {
		return "Nota [id=" + id + ", titulo=" + titulo + ", contenido=" + contenido + ", fechaCreacion=" + formatoFecha()
				+ "]";
	}

	@Override
	public int hashCode() {
		return Objects.hash(contenido, fechaCreacion, id, titulo);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Nota other = (Nota) obj;
		return Objects.equals(contenido, other.contenido) && Objects.equals(fechaCreacion, other.fechaCreacion)
				&& id == other.id && Objects.equals(titulo, other.titulo);
	}

}
