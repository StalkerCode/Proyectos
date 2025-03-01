package numero;

import java.util.Random;

public class Numero {
	private static int numero;
	private static Random random = new Random();

	public static void generarNumero() {
		numero = random.nextInt(100 - 1 + 1) + 1;
	}

	public static String sercania(int num) {
		int diferencia = Math.abs(numero - num);
		if (diferencia < 5) {
			return "Muy Caliente";
		} else if (diferencia < 8) {
			return "Caliente";
		} else if (diferencia < 11) {
			return "Tibio";
		} else if (diferencia < 15) {
			return "Normal";
		} else if (diferencia < 18) {
			return "Frio";
		} else {
			return "Muy Frio";
		}
	}
}
