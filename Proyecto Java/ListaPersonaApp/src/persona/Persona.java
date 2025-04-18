package persona;


public class Persona {
	private int id;
	private String nombre;
	private String telefono;
	private String email;
	static private int numeroPersona = 0;

	static int nPersonas() {
		return Persona.numeroPersona;
	}

	public Persona() {
		this.id = ++Persona.numeroPersona;
		this.nombre = "";
		this.telefono = "";
		this.email = "";
	}

	public Persona(String nombre, String telefono, String email) {
		this.id = ++Persona.numeroPersona;
		this.nombre = nombre;
		this.telefono = telefono;
		this.email = email;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public String getTelefono() {
		return telefono;
	}

	public void setTelefono(String telefono) {
		this.telefono = telefono;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String toString() {
		return "ID: " + id + "\tNombre: " + nombre + "\tTeléfono: " + telefono + "\tEmail: " + email;
	}

}
