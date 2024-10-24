package dispositivos;

public class DispositivosEntrada {
	protected String tipoEntrada;
	protected String marca;

	public DispositivosEntrada() {
	}

	public DispositivosEntrada(String tipoEntrada, String marca) {
		this.tipoEntrada = tipoEntrada;
		this.marca = marca;
	}

	public String getTipoEntrada() {
		return tipoEntrada;
	}

	public void setTipoEntrada(String tipoEntrada) {
		this.tipoEntrada = tipoEntrada;
	}

	public String getMarca() {
		return marca;
	}

	public void setMarca(String marca) {
		this.marca = marca;
	}

	// metodo toString
	@Override
	public String toString() {
		return "Tipo de entrada: " + tipoEntrada + ", Marca: " + marca;
	}

}
