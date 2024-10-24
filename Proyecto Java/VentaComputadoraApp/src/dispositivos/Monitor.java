package dispositivos;

public class Monitor {
	private static int contadorMonitores = 0;

	private int idMonitor;
	private String marca;
	private double tamanio;

	public Monitor() {
		this.idMonitor = ++Monitor.contadorMonitores;

	}

	public Monitor(String marca, double tamanio) {

		this.idMonitor = ++Monitor.contadorMonitores;
		this.marca = marca;
		this.tamanio = tamanio;

	}

	public int getIdMonitor() {
		return idMonitor;
	}

	public void setIdMonitor(int idMonitor) {
		this.idMonitor = idMonitor;
	}

	public String getMarca() {
		return marca;
	}

	public void setMarca(String marca) {
		this.marca = marca;
	}

	public double getTamanio() {
		return tamanio;
	}

	public void setTamanio(double tamanio) {
		this.tamanio = tamanio;
	}

	public static int getContadorMonitores() {
		return contadorMonitores;
	}

	@Override
	public String toString() {
		return "Monitor: idMonitor=" + idMonitor + ", marca=" + marca + ", tamanio=" + tamanio;
	}

}
