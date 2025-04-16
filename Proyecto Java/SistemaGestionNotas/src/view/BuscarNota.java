package view;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import controller.GestorNotas;
import model.Nota;
import java.awt.BorderLayout;
import java.awt.Dimension;
import javax.swing.JTextField;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import java.awt.Color;

public class BuscarNota extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textTirulo;
	private JPanel panelCuerpo;
	private JLabel id, titulo, contenido, fecha;
	private Menu menuFrame;
	private GestorNotas gestorNotas;

	private void crearpanel() {
		panelCuerpo.setBackground(new Color(128, 255, 128));
		GridBagLayout gbl_panelCuerpo = new GridBagLayout();
		gbl_panelCuerpo.columnWidths = new int[] { 326, 0 };
		gbl_panelCuerpo.rowHeights = new int[] { 50, 50, 182, 50 };
		gbl_panelCuerpo.columnWeights = new double[] { 1.0, Double.MIN_VALUE };
		gbl_panelCuerpo.rowWeights = new double[] { 0.0, 0.0, 0.0, 0.0 };
		panelCuerpo.setLayout(gbl_panelCuerpo);

		JPanel panelId = new JPanel();
		GridBagConstraints gbc_panelId = new GridBagConstraints();
		gbc_panelId.fill = GridBagConstraints.BOTH;
		gbc_panelId.insets = new Insets(0, 0, 5, 0);
		gbc_panelId.gridx = 0;
		gbc_panelId.gridy = 0;
		panelCuerpo.add(panelId, gbc_panelId);
		panelId.setLayout(new BorderLayout(0, 0));

		id = new JLabel("");
		id.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		panelId.add(id, BorderLayout.CENTER);

		JPanel panelTitulo = new JPanel();
		GridBagConstraints gbc_panelTitulo = new GridBagConstraints();
		gbc_panelTitulo.fill = GridBagConstraints.BOTH;
		gbc_panelTitulo.insets = new Insets(0, 0, 5, 0);
		gbc_panelTitulo.gridx = 0;
		gbc_panelTitulo.gridy = 1;
		panelCuerpo.add(panelTitulo, gbc_panelTitulo);
		panelTitulo.setLayout(new BorderLayout(0, 0));

		titulo = new JLabel("");
		titulo.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		panelTitulo.add(titulo, BorderLayout.CENTER);

		JPanel panelContenido = new JPanel();
		GridBagConstraints gbc_panelContenido = new GridBagConstraints();
		gbc_panelContenido.fill = GridBagConstraints.BOTH;
		gbc_panelContenido.insets = new Insets(0, 0, 5, 0);
		gbc_panelContenido.gridx = 0;
		gbc_panelContenido.gridy = 2;
		panelCuerpo.add(panelContenido, gbc_panelContenido);
		panelContenido.setLayout(new BorderLayout(0, 0));

		contenido = new JLabel("");
		contenido.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		panelContenido.add(contenido, BorderLayout.CENTER);

		JPanel panelFecha = new JPanel();
		GridBagConstraints gbc_panelFecha = new GridBagConstraints();
		gbc_panelFecha.fill = GridBagConstraints.BOTH;
		gbc_panelFecha.gridx = 0;
		gbc_panelFecha.gridy = 3;
		panelCuerpo.add(panelFecha, gbc_panelFecha);
		panelFecha.setLayout(new BorderLayout(0, 0));

		fecha = new JLabel("");
		fecha.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		panelFecha.add(fecha, BorderLayout.CENTER);
	}

	public BuscarNota(Menu menuFrame, GestorNotas gestorNotas) {
		this.menuFrame = menuFrame;
		this.gestorNotas = gestorNotas;
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 350, 450);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(new BorderLayout(0, 0));

		JPanel panelCabecera = new JPanel();
		panelCabecera.setBackground(new Color(128, 255, 255));
		contentPane.add(panelCabecera, BorderLayout.NORTH);
		panelCabecera.setLayout(new BorderLayout(0, 0));

		JPanel titulos = new JPanel();
		panelCabecera.add(titulos, BorderLayout.NORTH);
		titulos.setLayout(new BorderLayout(0, 0));

		JLabel labelTitulo = new JLabel("Titulo:");
		labelTitulo.setFont(new Font("Tahoma", Font.PLAIN, 20));
		labelTitulo.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		labelTitulo.setBackground(new Color(167, 245, 227));
		labelTitulo.setOpaque(true);
		titulos.add(labelTitulo, BorderLayout.WEST);

		textTirulo = new JTextField();
		textTirulo.setFont(new Font("Tahoma", Font.PLAIN, 20));
		textTirulo.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		titulos.add(textTirulo, BorderLayout.CENTER);
		textTirulo.setColumns(10);

		JButton botonBuscar = new JButton("Buscar");
		botonBuscar.addActionListener(e -> {
		    String tituloBuscado = textTirulo.getText();
		    if (!tituloBuscado.isEmpty()) {
		        Nota n1 = gestorNotas.buscarNota(tituloBuscado);
		        if (n1 != null) {
		            id.setText(String.valueOf(n1.getId()));
		            titulo.setText(n1.getTitulo());
		            contenido.setText(n1.getContenido());
		            fecha.setText(n1.formatoFecha());
		        } else {
		            id.setText("");
		            titulo.setText("");
		            contenido.setText("Título no encontrado");
		            fecha.setText("");
		        }
		    } else {
		        contenido.setText("Ingrese un título para buscar");
		    }
		});
		botonBuscar.setPreferredSize(new Dimension(0, 40));
		panelCabecera.add(botonBuscar, BorderLayout.SOUTH);

		panelCuerpo = new JPanel();
		crearpanel();
		contentPane.add(panelCuerpo, BorderLayout.CENTER);

		JPanel panel = new JPanel();
		contentPane.add(panel, BorderLayout.SOUTH);
		panel.setLayout(new BorderLayout(0, 0));

		JButton buttonRegresar = new JButton("Regresar");
		buttonRegresar.addActionListener(e -> {
			textTirulo.setText("");
			id.setText("");
			titulo.setText("");
			contenido.setText("");
			fecha.setText("");
			menuFrame.setVisible(true);
			dispose();

		});
		buttonRegresar.setFont(new Font("Tahoma", Font.PLAIN, 14));
		panel.add(buttonRegresar);
		setMinimumSize(new Dimension(450, 550));
	}
}
