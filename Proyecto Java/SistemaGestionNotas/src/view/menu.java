package view;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import javax.swing.border.EmptyBorder;
import java.awt.GridLayout;
import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.Color;
import java.awt.Font;

public class menu extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					menu frame = new menu();
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
	public menu() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 300, 450);
		contentPane = new JPanel();
		contentPane.setBackground(new Color(0, 255, 64));
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(new GridLayout(6, 1, 0, 10));
		
		JLabel lblNewLabel = new JLabel("Menu");
		lblNewLabel.setFont(new Font("Tahoma", Font.BOLD, 20));
        lblNewLabel.setBackground(new Color(105, 141, 197));
        lblNewLabel.setOpaque(true); // Hace que el JLabel sea opaco y muestre el color de fondo
        lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
        contentPane.add(lblNewLabel);
		
		JButton btnNewButton = new JButton("Agregar Nota");
		contentPane.add(btnNewButton);
		
		JButton btnNewButton_1 = new JButton("Buscar Nota");
		contentPane.add(btnNewButton_1);
		
		JButton btnNewButton_2 = new JButton("Editar Nota");
		contentPane.add(btnNewButton_2);
		
		JButton btnNewButton_3 = new JButton("Eliminar Nota");
		contentPane.add(btnNewButton_3);
		
		JButton btnNewButton_4 = new JButton("Listar Notas");
		contentPane.add(btnNewButton_4);
		
	}

}
