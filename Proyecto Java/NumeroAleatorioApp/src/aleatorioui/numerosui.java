package aleatorioui;

import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.BorderLayout;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
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
	private Color color;
	private static final Random random = new Random();
	private static int num;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		num = obteenrNumero();
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

	private static int obteenrNumero() {
		return random.nextInt(100 - 1 + 1) + 1;
	}

	private void mensage(Color color, String mgs,Color cl) {
		mensageDentro.setText(mgs);
		mensageDentro.setForeground(cl);
		panelDentro.setBackground(color);
	}

	private void cercania(int numero) {
		int distancia = Math.abs(numero - num);
		if (distancia == 0) {
			
			mensage(new Color(30, 249, 22), "ganaste",Color.BLACK);
			
		} else if (distancia < 3) {
			
			mensage(new Color(245, 19, 19), "muy caliente",Color.WHITE);
			
		} else if (distancia < 5) {
			
			mensage(new Color(238, 80, 80), "caliente",Color.BLACK);
			
		} else if (distancia < 10) {
			
			mensage(new Color(211, 118, 240), "tibio",Color.BLACK);
			
		} else if (distancia < 15) {
			
			mensage(new Color(156, 143, 239), "frio",Color.BLACK);
			
		} else if (distancia < 20) {
			
			mensage(new Color(89, 65, 243), "muy frio",Color.WHITE);

		} else {

			mensage(new Color(28, 0, 208), "muy muy frio",Color.WHITE);
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
		tituloPanel.setBorder(new BevelBorder(BevelBorder.LOWERED, new Color(0, 0, 0), new Color(0, 0, 0),
				new Color(0, 0, 0), new Color(0, 0, 0)));
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
		texto.setBorder(new BevelBorder(BevelBorder.LOWERED, new Color(0, 0, 0), new Color(0, 0, 0), new Color(0, 0, 0),
				new Color(0, 0, 0)));
		datos.add(texto, BorderLayout.CENTER);
		texto.setLayout(new BorderLayout(0, 0));

		textField = new JTextField();
		textField.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                char c = e.getKeyChar();
                if (!Character.isDigit(c) || textField.getText().length() >= 3) {
                    e.consume(); // Ignora el evento si no es un dígito o si ya hay 3 caracteres
                }
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

		JLabel informacion = new JLabel("Seleciona un numero de 1 a 100");
		informacion.setFont(new Font("Tahoma", Font.PLAIN, 15));
		mensaje.add(informacion, BorderLayout.CENTER);

		JPanel mensajeFinal = new JPanel();
		cuerpoPanel.add(mensajeFinal, BorderLayout.CENTER);
		mensajeFinal.setLayout(new BorderLayout(0, 0));

		JPanel reinicio = new JPanel();
		mensajeFinal.add(reinicio, BorderLayout.SOUTH);

		JButton reinicioBoton = new JButton("Reiniciar");
		reinicio.add(reinicioBoton);

		panelDentro = new JPanel();
		panelDentro.setLayout(new GridBagLayout()); // Usamos GridBagLayout para centrar
		mensajeFinal.add(panelDentro, BorderLayout.CENTER);

		mensageDentro = new JLabel("Inicia");
		mensageDentro.setHorizontalAlignment(SwingConstants.CENTER); // Centra el texto dentro del JLabel
		panelDentro.add(mensageDentro); // Se añade al centro gracias a GridBagLayout

		JButton verifica = new JButton("Verifica el numero");
		verifica.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int numero = Integer.parseInt(textField.getText());
				cercania(numero);
			}
		});
		boton.add(verifica, BorderLayout.CENTER);

	}

}
