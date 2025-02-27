package aleatorioui;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.BorderLayout;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.Color;
import javax.swing.border.BevelBorder;
import java.awt.FlowLayout;

public class numerosui extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textField;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
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
		tituloPanel.setBorder(new BevelBorder(BevelBorder.LOWERED, new Color(0, 0, 0), new Color(0, 0, 0), new Color(0, 0, 0), new Color(0, 0, 0)));
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
		texto.setBorder(new BevelBorder(BevelBorder.LOWERED, new Color(0, 0, 0), new Color(0, 0, 0), new Color(0, 0, 0), new Color(0, 0, 0)));
		datos.add(texto, BorderLayout.CENTER);
		texto.setLayout(new BorderLayout(0, 0));
		
		textField = new JTextField();
		texto.add(textField, BorderLayout.CENTER);
		textField.setColumns(10);
		
		JPanel boton = new JPanel();
		datos.add(boton, BorderLayout.EAST);
		boton.setLayout(new BorderLayout(0, 0));
		
		JButton verifica = new JButton("Verifica el numero");
		boton.add(verifica, BorderLayout.CENTER);
		
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
	}

}
