package calculadora;

public class Calculadora {

	private Calculadora() {
	}

	public static String suma(String num1, String sum2) {
		return Double.toString(Double.parseDouble(num1) + Double.parseDouble(sum2));
	}

	public static String resta(String num1, String sum2) {
		return Double.toString(Double.parseDouble(num1) - Double.parseDouble(sum2));
	}

	public static String multiplicacion(String num1, String sum2) {
		return Double.toString(Double.parseDouble(num1) * Double.parseDouble(sum2));
	}

	public static String divicion(String num1, String sum2) {
		return Double.toString(Double.parseDouble(num1) / Double.parseDouble(sum2));
	}

	public static String modulo(String num1, String sum2) {
		return Integer.toString((int) ((Double.parseDouble(num1) % Double.parseDouble(sum2))));
	}

	public static String exponente(String num1, String sum2) {
		return Double.toString(Math.pow(Double.parseDouble(num1), Double.parseDouble(sum2)));
	}

}
