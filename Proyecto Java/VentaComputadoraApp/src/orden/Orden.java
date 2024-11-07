package orden;

import java.util.ArrayList;

import computadora.Computadora;

public class Orden {
	private int idOrden;
	private ArrayList<Computadora> computadoras;
	private static int contadorOrden = 0;

	public Orden() {
		this.idOrden = ++Orden.contadorOrden;
		this.computadoras = new ArrayList<Computadora>();
	}

	public void agregarComputadora(Computadora computadora) {
		this.computadoras.add(computadora);
	}

	public void mostrarOrden() {
		System.out.println("\nOrden: " + this.idOrden);
		for (Computadora cp : computadoras) {
			System.out.println(cp.toString());
		}
	}

	// metodo toString
	@Override
	public String toString() {
		return "Orden:\nidOrden=" + idOrden + "\ncomputadoras:\n" + computadoras;
	}

	public static int getContadorOrden() {
		return contadorOrden;
	}

	public int getIdOrden() {
		return idOrden;
	}

	public ArrayList<Computadora> getComputadoras() {
		return computadoras;
	}

	public void setComputadoras(ArrayList<Computadora> computadoras) {
		this.computadoras = computadoras;
	}

}
