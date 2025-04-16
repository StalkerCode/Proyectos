package view;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.Font;
import javax.swing.SwingConstants;

public class EliminarNota extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textId;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					EliminarNota frame = new EliminarNota();
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
	public EliminarNota() {
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
		labelID.setFont(new Font("Tahoma", Font.PLAIN, 20));
		labelID.setHorizontalAlignment(SwingConstants.CENTER);
		labelID.setPreferredSize(new Dimension(40, 30));
		panelCaveza.add(labelID, BorderLayout.WEST);
		
		textId = new JTextField();
		panelCaveza.add(textId, BorderLayout.CENTER);
		textId.setColumns(10);
		
		JButton ButtonBuscar = new JButton("Buscar");
		ButtonBuscar.setFont(new Font("Tahoma", Font.PLAIN, 15));
		panelCaveza.add(ButtonBuscar, BorderLayout.SOUTH);
		
		JPanel panelMensage = new JPanel();
		panelCuerpo.add(panelMensage, BorderLayout.CENTER);
		
		JButton ButtonRegresar = new JButton("Regresar");
		ButtonRegresar.setFont(new Font("Tahoma", Font.PLAIN, 15));
		panelCuerpo.add(ButtonRegresar, BorderLayout.SOUTH);
	}

}
