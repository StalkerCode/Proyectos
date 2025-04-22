package view;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import controller.GestorNotas;
import java.awt.BorderLayout;
import java.awt.Dimension;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import javax.swing.SwingConstants;
import java.awt.Color;

public class EliminarNota extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textId;
	private Menu menuFrame;
	private GestorNotas gestorNotas;

	// Función para validar la entrada
	private void validarEntrada(KeyEvent e) {
		char c = e.getKeyChar();
		// 1. Solo permitir dígitos
		if (!Character.isDigit(c)) {
			e.consume();
		}
	}

	public EliminarNota(Menu menuFrame, GestorNotas gestorNotas) {
		this.menuFrame = menuFrame;
		this.gestorNotas = gestorNotas;
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 300, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(new BorderLayout(0, 0));

		JPanel panelTitulo = new JPanel();
		contentPane.add(panelTitulo, BorderLayout.NORTH);
		panelTitulo.setLayout(new BorderLayout(0, 0));

		JLabel LabelEliminarNota = new JLabel("Eliminar Nota");
		LabelEliminarNota.setBackground(new Color(0, 255, 128));
		LabelEliminarNota.setOpaque(true);
		LabelEliminarNota.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		LabelEliminarNota.setHorizontalAlignment(SwingConstants.CENTER);
		LabelEliminarNota.setFont(new Font("Tahoma", Font.PLAIN, 20));
		panelTitulo.add(LabelEliminarNota, BorderLayout.CENTER);

		JPanel panelCuerpo = new JPanel();
		contentPane.add(panelCuerpo, BorderLayout.CENTER);
		panelCuerpo.setLayout(new BorderLayout(0, 0));

		JPanel panelCaveza = new JPanel();
		panelCuerpo.add(panelCaveza, BorderLayout.NORTH);
		panelCaveza.setLayout(new BorderLayout(0, 0));

		JLabel labelID = new JLabel("ID");
		labelID.setBackground(new Color(128, 255, 255));
		labelID.setOpaque(true);
		labelID.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		labelID.setFont(new Font("Tahoma", Font.PLAIN, 20));
		labelID.setHorizontalAlignment(SwingConstants.CENTER);
		labelID.setPreferredSize(new Dimension(40, 30));
		panelCaveza.add(labelID, BorderLayout.WEST);

		textId = new JTextField();
		textId.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		textId.addKeyListener(new KeyAdapter() {
			@Override
			public void keyTyped(KeyEvent e) {
				validarEntrada(e);
			}
		});

		panelCaveza.add(textId, BorderLayout.CENTER);
		textId.setColumns(10);

		JPanel panelMensage = new JPanel();
		panelMensage.setBackground(new Color(128, 255, 128));
		panelCuerpo.add(panelMensage, BorderLayout.CENTER);
		panelMensage.setLayout(new BorderLayout(0, 0));

		JLabel labelCenter = new JLabel("mensaje");
		labelCenter.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		labelCenter.setFont(new Font("Tahoma", Font.PLAIN, 20));
		labelCenter.setHorizontalAlignment(SwingConstants.CENTER);
		panelMensage.add(labelCenter, BorderLayout.CENTER);

		JButton ButtonBuscar = new JButton("Eliminar");
		ButtonBuscar.addActionListener(e -> {
			if (!textId.getText().isEmpty()) {
				int num = Integer.parseInt(textId.getText());
				labelCenter.setText(gestorNotas.eliminarNota(num));
			} else {
				labelCenter.setText("esta vacio");
			}
		});

		ButtonBuscar.setFont(new Font("Tahoma", Font.BOLD, 15));
		panelCaveza.add(ButtonBuscar, BorderLayout.SOUTH);

		JButton ButtonRegresar = new JButton("Regresar");
		ButtonRegresar.addActionListener(e -> {
			textId.setText("");
			menuFrame.setVisible(true);
			dispose();
		});
		ButtonRegresar.setFont(new Font("Tahoma", Font.BOLD, 15));
		panelCuerpo.add(ButtonRegresar, BorderLayout.SOUTH);
		setMinimumSize(new Dimension(400, 400));
	}

}
