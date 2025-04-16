package view;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import controller.GestorNotas;
import java.awt.BorderLayout;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import javax.swing.JTextField;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JTextPane;
import javax.swing.SwingConstants;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.ActionEvent;

public class EditarNota extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textID;
	private Menu menuFrame;
	private GestorNotas gestorNotas;

	public EditarNota(Menu menuFrame, GestorNotas gestorNotas) {
		this.menuFrame = menuFrame;
		this.gestorNotas = gestorNotas;
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 300, 400);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(new BorderLayout(0, 0));

		JPanel panelTitulo = new JPanel();
		panelTitulo.setBackground(new Color(0, 255, 255));
		contentPane.add(panelTitulo, BorderLayout.NORTH);
		panelTitulo.setLayout(new BorderLayout(0, 0));

		JLabel Labeltitulo = new JLabel("Editar Nota");
		Labeltitulo.setHorizontalAlignment(SwingConstants.CENTER);
		Labeltitulo.setFont(new Font("Tahoma", Font.PLAIN, 20));
		Labeltitulo.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		panelTitulo.add(Labeltitulo, BorderLayout.CENTER);

		JPanel panelCuerpo = new JPanel();
		contentPane.add(panelCuerpo, BorderLayout.CENTER);
		GridBagLayout gbl_panelCuerpo = new GridBagLayout();
		gbl_panelCuerpo.columnWidths = new int[] { 0, 0 };
		gbl_panelCuerpo.rowHeights = new int[] { 0, 20, 20, 100, 20 };
		gbl_panelCuerpo.columnWeights = new double[] { 1.0, Double.MIN_VALUE };
		gbl_panelCuerpo.rowWeights = new double[] { 1.0, 1.0, 1.0, 1.0, 1.0 };
		panelCuerpo.setLayout(gbl_panelCuerpo);

		JPanel panelId = new JPanel();
		GridBagConstraints gbc_panelId = new GridBagConstraints();
		gbc_panelId.insets = new Insets(0, 0, 5, 0);
		gbc_panelId.fill = GridBagConstraints.BOTH;
		gbc_panelId.gridx = 0;
		gbc_panelId.gridy = 0;
		panelCuerpo.add(panelId, gbc_panelId);
		panelId.setLayout(new BorderLayout(0, 0));

		JLabel labelId = new JLabel("ID");
		labelId.setBackground(new Color(133, 250, 250));
		labelId.setOpaque(true);
		labelId.setHorizontalAlignment(SwingConstants.CENTER);
		labelId.setFont(new Font("Tahoma", Font.PLAIN, 14));
		labelId.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		labelId.setPreferredSize(new Dimension(40, 0));
		panelId.add(labelId, BorderLayout.WEST);

		textID = new JTextField();
		panelId.add(textID, BorderLayout.CENTER);
		textID.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		textID.addKeyListener(new KeyAdapter() {
			@Override
			public void keyTyped(KeyEvent e) {
				validarEntrada(e);
			}
		});
		textID.setColumns(10);

		JPanel panelContenido = new JPanel();
		GridBagConstraints gbc_panelContenido = new GridBagConstraints();
		gbc_panelContenido.insets = new Insets(0, 0, 5, 0);
		gbc_panelContenido.fill = GridBagConstraints.BOTH;
		gbc_panelContenido.gridx = 0;
		gbc_panelContenido.gridy = 1;
		panelCuerpo.add(panelContenido, gbc_panelContenido);
		panelContenido.setLayout(new BorderLayout(0, 0));

		JLabel labelContenido = new JLabel("Contenido");
		labelContenido.setBackground(new Color(133, 250, 250));
		labelContenido.setOpaque(true);
		labelContenido.setFont(new Font("Tahoma", Font.PLAIN, 15));
		labelContenido.setHorizontalAlignment(SwingConstants.CENTER);
		labelContenido.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		labelContenido.setPreferredSize(new Dimension(80, 0));
		panelContenido.add(labelContenido, BorderLayout.WEST);

		JTextPane textContenido = new JTextPane();
		textContenido.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		panelContenido.add(textContenido, BorderLayout.CENTER);

		JPanel panelGuaradr = new JPanel();
		GridBagConstraints gbc_panelGuaradr = new GridBagConstraints();
		gbc_panelGuaradr.insets = new Insets(0, 0, 5, 0);
		gbc_panelGuaradr.fill = GridBagConstraints.BOTH;
		gbc_panelGuaradr.gridx = 0;
		gbc_panelGuaradr.gridy = 2;
		panelCuerpo.add(panelGuaradr, gbc_panelGuaradr);
		panelGuaradr.setLayout(new BorderLayout(0, 0));

		JPanel panelMensage = new JPanel();
		GridBagConstraints gbc_panelMensage = new GridBagConstraints();
		gbc_panelMensage.insets = new Insets(0, 0, 5, 0);
		gbc_panelMensage.fill = GridBagConstraints.BOTH;
		gbc_panelMensage.gridx = 0;
		gbc_panelMensage.gridy = 3;
		panelCuerpo.add(panelMensage, gbc_panelMensage);
		panelMensage.setLayout(new BorderLayout(0, 0));

		JLabel labelMensaje = new JLabel("");
		labelMensaje.setBackground(new Color(128, 255, 255));
		labelMensaje.setHorizontalAlignment(SwingConstants.CENTER);
		labelMensaje.setOpaque(true);
		labelMensaje.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		panelMensage.add(labelMensaje, BorderLayout.CENTER);

		JButton buttonGuardar = new JButton("Guardar");
		buttonGuardar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String id = textID.getText();
				String contenido = textContenido.getText();
				if (!id.isEmpty() && !contenido.isEmpty()) {
					String mensage = gestorNotas.editarNota(Integer.parseInt(id), contenido);
					labelMensaje.setText(mensage);
					return;
				}
				labelMensaje.setText("esta vasio");
			}
		});
		panelGuaradr.add(buttonGuardar, BorderLayout.CENTER);

		JPanel panelRegresar = new JPanel();
		GridBagConstraints gbc_panelRegresar = new GridBagConstraints();
		gbc_panelRegresar.fill = GridBagConstraints.BOTH;
		gbc_panelRegresar.gridx = 0;
		gbc_panelRegresar.gridy = 4;
		panelCuerpo.add(panelRegresar, gbc_panelRegresar);
		panelRegresar.setLayout(new BorderLayout(0, 0));

		JButton buttonRegresar = new JButton("Regresar");
		buttonRegresar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				labelMensaje.setText("");
				textID.setText("");
				textContenido.setText("");
				// Regresar al menú principal
				menuFrame.setVisible(true);
				dispose();
			}
		});
		panelRegresar.add(buttonRegresar, BorderLayout.CENTER);
	}

	// Función para validar la entrada
	private void validarEntrada(KeyEvent e) {
		char c = e.getKeyChar();
		// 1. Solo permitir dígitos
		if (!Character.isDigit(c)) {
			e.consume();
			return;
		}
	}

}
