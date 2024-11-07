package dispositivos;

public class Teclado extends DispositivosEntrada {
	private static int contadorTeclado = 0;

	private int idTeclado;

	public Teclado() {
		super();
		this.idTeclado = ++Teclado.contadorTeclado;
	}

	public Teclado(String tipoEntrada, String marca) {
		super(tipoEntrada, marca);
		this.idTeclado = ++Teclado.contadorTeclado;

	}

	public int getIdTeclado() {
		return idTeclado;
	}

	public void setIdTeclado(int idTeclado) {
		this.idTeclado = idTeclado;
	}

	public static int getContadorTeclado() {
		return contadorTeclado;
	}

	@Override
	public String toString() {
		return "Teclado: idTeclado=" + idTeclado + ", " + super.toString();
	}

}
