package calculadoraui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.GridLayout;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import javax.swing.border.EmptyBorder;
import calculadora.*;
import javax.swing.JButton;

public class CalculadoraUI extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private static String num1 = "", num2 = "";
	private static Boolean hayPunto = false;
	private static Boolean hayOperacion = false;
	private static Boolean hayIgual = false;
	private static final int maxLen = 16;
	private static Character tipo;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					CalculadoraUI frame = new CalculadoraUI();
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
	public CalculadoraUI() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 400, 500);
		setMinimumSize(new Dimension(400, 500));
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));


		setContentPane(contentPane);
		contentPane.setLayout(new BorderLayout(0, 0));

		JPanel panelPantalla = new JPanel();
		panelPantalla.setPreferredSize(new Dimension(0, 60));
		panelPantalla.setBackground(new Color(0, 255, 64));
		contentPane.add(panelPantalla, BorderLayout.NORTH);
		panelPantalla.setLayout(new BorderLayout(0, 0));

		JLabel LabelPantalla = new JLabel("");
		LabelPantalla.setFont(new Font("Arial", Font.PLAIN, 20));
		LabelPantalla.setHorizontalAlignment(SwingConstants.RIGHT);
		panelPantalla.add(LabelPantalla, BorderLayout.CENTER);

		JPanel panelTaclado = new JPanel();
		panelTaclado.setBackground(new Color(128, 0, 255));
		contentPane.add(panelTaclado, BorderLayout.CENTER);
		panelTaclado.setLayout(new GridLayout(5, 4, 5, 5));
		
		JButton btnNewButton = new JButton("%");
		btnNewButton.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton);
		
		JButton btnNewButton_1 = new JButton("CE");
		btnNewButton_1.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_1);
		
		JButton btnNewButton_2 = new JButton("C");
		btnNewButton_2.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_2);
		
		JButton btnNewButton_3 = new JButton("÷");
		btnNewButton_3.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_3);
		
		JButton btnNewButton_4 = new JButton("1");
		btnNewButton_4.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_4);
		
		JButton btnNewButton_5 = new JButton("2");
		btnNewButton_5.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_5);
		
		JButton btnNewButton_6 = new JButton("3");
		btnNewButton_6.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_6);
		
		JButton btnNewButton_7 = new JButton("*");
		btnNewButton_7.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_7);
		
		JButton btnNewButton_8 = new JButton("4");
		btnNewButton_8.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_8);
		
		JButton btnNewButton_9 = new JButton("5");
		btnNewButton_9.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_9);
		
		JButton btnNewButton_10 = new JButton("6");
		btnNewButton_10.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_10);
		
		JButton btnNewButton_11 = new JButton("-");
		btnNewButton_11.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_11);
		
		JButton btnNewButton_12 = new JButton("7");
		btnNewButton_12.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_12);
		
		JButton btnNewButton_13 = new JButton("8");
		btnNewButton_13.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_13);
		
		JButton btnNewButton_14 = new JButton("9");
		btnNewButton_14.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_14);
		
		JButton btnNewButton_15 = new JButton("+");
		btnNewButton_15.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_15);
		
		JButton btnNewButton_16 = new JButton("+/-");
		btnNewButton_16.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_16);
		
		JButton btnNewButton_17 = new JButton("0");
		btnNewButton_17.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_17);
		
		JButton btnNewButton_18 = new JButton(".");
		btnNewButton_18.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_18);
		
		JButton btnNewButton_19 = new JButton("=");
		btnNewButton_19.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_19);
		
	}
	

}
