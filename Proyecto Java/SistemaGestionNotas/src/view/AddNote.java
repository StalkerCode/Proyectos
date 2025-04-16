package view;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import controller.GestorNotas;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.Color;
import javax.swing.SwingConstants;

import javax.swing.JEditorPane;

public class AddNote extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textTitulo;
	private JEditorPane textContenido;
	private Menu menuFrame;
	private GestorNotas gestorNotas;

	public AddNote(Menu menuFrame, GestorNotas gestorNotas) {
		this.menuFrame = menuFrame;
		this.gestorNotas = gestorNotas;

		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 400, 330);
		contentPane = new JPanel();
		contentPane.setBackground(new Color(128, 128, 192));
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(new GridLayout(3, 0, 0, 5));

		JPanel panelTitulo = new JPanel();
		panelTitulo.setBackground(new Color(0, 255, 128));
		contentPane.add(panelTitulo);
		panelTitulo.setLayout(new GridLayout(0, 2, 0, 0));

		JLabel labeltitulo = new JLabel("Titulo:");
		labeltitulo.setHorizontalAlignment(SwingConstants.CENTER);
		labeltitulo.setFont(new Font("Tahoma", Font.PLAIN, 30));
		labeltitulo.setBorder(BorderFactory.createLineBorder(Color.BLACK,2));
		panelTitulo.add(labeltitulo);

		textTitulo = new JTextField();
		textTitulo.setFont(new Font("Tahoma", Font.PLAIN, 20));
		textTitulo.setBorder(BorderFactory.createLineBorder(Color.BLACK,2));
		panelTitulo.add(textTitulo);
		textTitulo.setColumns(10);

		JPanel panelContenido = new JPanel();
		panelContenido.setBackground(new Color(128, 255, 255));
		contentPane.add(panelContenido);
		panelContenido.setLayout(new GridLayout(1, 0, 0, 0));

		JLabel labelContenido = new JLabel("Contenido:");
		labelContenido.setHorizontalAlignment(SwingConstants.CENTER);
		labelContenido.setFont(new Font("Tahoma", Font.PLAIN, 30));
		labelContenido.setBorder(BorderFactory.createLineBorder(Color.BLACK,2));
		panelContenido.add(labelContenido);

		textContenido = new JEditorPane();
		textContenido.setBorder(BorderFactory.createLineBorder(Color.BLACK,2));
		panelContenido.add(textContenido);

		JPanel panelBotones = new JPanel();
		contentPane.add(panelBotones);
		panelBotones.setLayout(new GridLayout(1, 0, 0, 0));

		JButton regresar = new JButton("Regresar");
		regresar.setFont(new Font("Tahoma", Font.PLAIN, 20));
		regresar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textTitulo.setText("");
				textContenido.setText("");
				// Regresar al menú principal
				menuFrame.setVisible(true);
				dispose();
			}
		});
		panelBotones.add(regresar);

		JButton guardar = new JButton("Guardar");
		guardar.setFont(new Font("Tahoma", Font.PLAIN, 20));
		guardar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// Guardar la nota y regresar al menú principal
				String titulo = textTitulo.getText();
				String contenido = textContenido.getText();
				if (titulo.length() > 1 && contenido.length() > 1) {
					gestorNotas.agregarNota(titulo, contenido);
				}
				textTitulo.setText("");
				textContenido.setText("");
				menuFrame.setVisible(true);
				dispose();
			}
		});
		panelBotones.add(guardar);
	}
}
