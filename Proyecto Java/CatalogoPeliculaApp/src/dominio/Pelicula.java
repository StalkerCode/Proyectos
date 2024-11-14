package dominio;

import java.util.Objects;

public class Pelicula {
	private String Nombre;

	public Pelicula() {
	}

	public Pelicula(String nombre) {
		super();
		Nombre = nombre;
	}

	public String getNombre() {
		return Nombre;
	}

	public void setNombre(String nombre) {
		Nombre = nombre;
	}

	@Override
	public String toString() {
		return "Pelicula [Nombre=" + Nombre + "]";
	}

	@Override
	public int hashCode() {
		return Objects.hash(Nombre);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Pelicula other = (Pelicula) obj;
		return Objects.equals(Nombre, other.Nombre);
	}

}
