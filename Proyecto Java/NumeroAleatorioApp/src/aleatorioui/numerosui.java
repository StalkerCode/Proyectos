package aleatorioui;

import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.BorderLayout;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.GridBagLayout;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.Random;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.JButton;
import java.awt.Color;
import javax.swing.border.BevelBorder;

public class numerosui extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textField;
	private JLabel mensageDentro;
	private JPanel panelDentro;
	private Boolean ganaste = false;
	private static final Random random = new Random();
	private static int num;

	private static final Color[] COLORS = { Color.GREEN, Color.RED, Color.PINK, Color.CYAN, Color.GRAY, Color.BLUE,
			Color.BLACK };
	private static final String[] MESSAGES = { "ganaste", "muy caliente", "caliente", "tibio", "frio", "muy frio",
			"muy muy frio" };
	private static final Color[] TEXT_COLORS = { Color.BLACK, Color.WHITE, Color.BLACK, Color.BLACK, Color.BLACK,
			Color.WHITE, Color.WHITE };

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		num = obtenerNumero();
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					numerosui frame = new numerosui();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	private static int obtenerNumero() {
		return random.nextInt(100) + 1;
	}

	private void mostrarMensaje(int indice) {
		mensageDentro.setText(MESSAGES[indice]);
		mensageDentro.setForeground(TEXT_COLORS[indice]);
		panelDentro.setBackground(COLORS[indice]);
	}


	private void verificarCercania(int numero) {
		int distancia = Math.abs(numero - num);
		// hace lo mismo que un if-else if -else
		// o un switch
		int indiceMensaje = (distancia == 0) ? 0
							: (distancia < 3) ? 1
							: (distancia < 5) ? 2 
							: (distancia < 10) ? 3
							: (distancia < 15) ? 4 
							: (distancia < 20) ? 5 : 6;

		mostrarMensaje(indiceMensaje);

		if (distancia == 0) {
			ganaste = true;
		}
	}
	
	// Función para validar la entrada
    private void validarEntrada(KeyEvent e) {
        char c = e.getKeyChar();
        String textoActual = textField.getText();

        // 1. Solo permitir dígitos
        if (!Character.isDigit(c)) {
            e.consume();
            return;
        }

        // 2. Limitar a 3 dígitos
        if (textoActual.length() >= 3) {
            e.consume();
            return;
        }

        // 3. Validar que no supere 100
        String nuevoTexto = textoActual + c; // Simulamos el texto resultante
        try {
            int valor = Integer.parseInt(nuevoTexto);
            if (valor > 100) {
                e.consume();
            }
        } catch (NumberFormatException ex) {
            // Esto no debería ocurrir porque ya validamos que son dígitos
            e.consume();
        }
    }

	/**
	 * Create the frame.
	 */
	public numerosui() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 300, 400);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(8, 8, 8, 8));

		setContentPane(contentPane);
		contentPane.setLayout(new BorderLayout(0, 0));

		JPanel tituloPanel = new JPanel();
		tituloPanel.setBorder(new BevelBorder(BevelBorder.LOWERED, Color.BLACK, Color.BLACK, Color.BLACK, Color.BLACK));
		tituloPanel.setBackground(new Color(86, 252, 82));
		contentPane.add(tituloPanel, BorderLayout.NORTH);
		tituloPanel.setLayout(new BorderLayout(0, 0));

		JLabel titulo = new JLabel("Adivina el Numero");
		titulo.setFont(new Font("Tahoma", Font.PLAIN, 20));
		tituloPanel.add(titulo, BorderLayout.CENTER);

		JPanel cuerpoPanel = new JPanel();
		contentPane.add(cuerpoPanel, BorderLayout.CENTER);
		cuerpoPanel.setLayout(new BorderLayout(0, 0));

		JPanel datos = new JPanel();
		cuerpoPanel.add(datos, BorderLayout.NORTH);
		datos.setLayout(new BorderLayout(0, 0));

		JPanel texto = new JPanel();
		texto.setBorder(new BevelBorder(BevelBorder.LOWERED, Color.BLACK, Color.BLACK, Color.BLACK, Color.BLACK));
		datos.add(texto, BorderLayout.CENTER);
		texto.setLayout(new BorderLayout(0, 0));

		textField = new JTextField();
		textField.addKeyListener(new KeyAdapter() {
			@Override
            public void keyTyped(KeyEvent e) {
                validarEntrada(e);
            }
		});
		
		texto.add(textField, BorderLayout.CENTER);
		textField.setColumns(10);

		JPanel boton = new JPanel();
		datos.add(boton, BorderLayout.EAST);
		boton.setLayout(new BorderLayout(0, 0));

		JPanel mensaje = new JPanel();
		datos.add(mensaje, BorderLayout.NORTH);
		mensaje.setLayout(new BorderLayout(0, 0));

		JLabel informacion = new JLabel("Selecciona un numero de 1 a 100");
		informacion.setFont(new Font("Tahoma", Font.PLAIN, 15));
		mensaje.add(informacion, BorderLayout.CENTER);

		JPanel mensajeFinal = new JPanel();
		cuerpoPanel.add(mensajeFinal, BorderLayout.CENTER);
		mensajeFinal.setLayout(new BorderLayout(0, 0));

		JPanel reinicio = new JPanel();
		mensajeFinal.add(reinicio, BorderLayout.SOUTH);

		JButton reinicioBoton = new JButton("Reiniciar");
		/*
		 * es un lambda que significa
		 * 
		 * verifica.addActionListener(new ActionListener() { public void
		 * actionPerformed(ActionEvent e) { cuepor de la funcion } });
		 * 
		 */
		reinicioBoton.addActionListener(e -> {
			num = obtenerNumero();
			mensageDentro.setText("Inicia");
			panelDentro.setBackground(Color.WHITE);
			mensageDentro.setForeground(Color.BLACK);
			ganaste = false;
			textField.setText("");
		});
		reinicio.add(reinicioBoton);

		panelDentro = new JPanel();
		panelDentro.setLayout(new GridBagLayout());
		mensajeFinal.add(panelDentro, BorderLayout.CENTER);

		mensageDentro = new JLabel("Inicia");
		mensageDentro.setHorizontalAlignment(SwingConstants.CENTER);
		panelDentro.add(mensageDentro);

		JButton verifica = new JButton("Verifica el numero");
		verifica.addActionListener(e -> {
			String textString=textField.getText();
			if (!ganaste && textString.length()>0) {
				int numero = Integer.parseInt(textString);
				verificarCercania(numero);
			}
		});
		boton.add(verifica, BorderLayout.CENTER);
	}
	
	

}
