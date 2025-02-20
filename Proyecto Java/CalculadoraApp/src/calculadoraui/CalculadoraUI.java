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
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class CalculadoraUI extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private static String num1 = "", num2 = "";
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

	private void limpiar(JLabel pantalla) {
		if (hayIgual) {
			pantalla.setText("");
			hayIgual = false;
		}
	}

	private boolean hayPunto(String str) {
		if (str == null) {
			return false;
		}
		return str.contains(".");
	}

	private String toggleGuionInicial(String str) {
		if (str == null) {
			return null;
		}
		if (str.startsWith("-")) {
			return str.substring(1); // Quita el guion inicial
		} else {
			return "-" + str; // Agrega el guion inicial
		}
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
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (!hayOperacion && (LabelPantalla.getText().length() > 0)) {
					num1 = LabelPantalla.getText();
					hayOperacion = true;
					tipo = '5';
					LabelPantalla.setText("");
				}
			}
		});
		btnNewButton.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton);

		JButton btnNewButton_1 = new JButton("CE");
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				num1 = null;
				num2 = null;
				hayOperacion = false;
				LabelPantalla.setText("");
			}
		});
		btnNewButton_1.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_1);

		JButton btnNewButton_2 = new JButton("C");
		btnNewButton_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (!hayOperacion) {
					num1 = null;
					LabelPantalla.setText("");
				} else {
					num2 = null;
					LabelPantalla.setText("");
				}
			}
		});
		btnNewButton_2.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_2);

		JButton btnNewButton_3 = new JButton("÷");
		btnNewButton_3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (!hayOperacion && (LabelPantalla.getText().length() > 0)) {
					num1 = LabelPantalla.getText();
					hayOperacion = true;
					tipo = '4';
					LabelPantalla.setText("");
				}
			}
		});
		btnNewButton_3.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_3);

		JButton btnNewButton_4 = new JButton("1");
		btnNewButton_4.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent e) {
				if (LabelPantalla.getText().length() <= maxLen) {
					limpiar(LabelPantalla);
					LabelPantalla.setText(LabelPantalla.getText() + "1");
				}
			}
		});
		btnNewButton_4.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_4);

		JButton btnNewButton_5 = new JButton("2");
		btnNewButton_5.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (LabelPantalla.getText().length() <= maxLen) {
					limpiar(LabelPantalla);
					LabelPantalla.setText(LabelPantalla.getText() + "2");
				}
			}
		});
		btnNewButton_5.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_5);

		JButton btnNewButton_6 = new JButton("3");
		btnNewButton_6.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (LabelPantalla.getText().length() <= maxLen) {
					limpiar(LabelPantalla);
					LabelPantalla.setText(LabelPantalla.getText() + "3");
				}
			}
		});
		btnNewButton_6.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_6);

		JButton btnNewButton_7 = new JButton("*");
		btnNewButton_7.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (!hayOperacion && (LabelPantalla.getText().length() > 0)) {
					num1 = LabelPantalla.getText();
					hayOperacion = true;
					tipo = '3';
					LabelPantalla.setText("");
				}
			}
		});
		btnNewButton_7.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_7);

		JButton btnNewButton_8 = new JButton("4");
		btnNewButton_8.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (LabelPantalla.getText().length() <= maxLen) {
					limpiar(LabelPantalla);
					LabelPantalla.setText(LabelPantalla.getText() + "4");
				}
			}
		});
		btnNewButton_8.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_8);

		JButton btnNewButton_9 = new JButton("5");
		btnNewButton_9.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (LabelPantalla.getText().length() <= maxLen) {
					limpiar(LabelPantalla);
					LabelPantalla.setText(LabelPantalla.getText() + "5");
				}
			}
		});
		btnNewButton_9.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_9);

		JButton btnNewButton_10 = new JButton("6");
		btnNewButton_10.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (LabelPantalla.getText().length() <= maxLen) {
					limpiar(LabelPantalla);
					LabelPantalla.setText(LabelPantalla.getText() + "6");
				}
			}
		});
		btnNewButton_10.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_10);

		JButton btnNewButton_11 = new JButton("-");
		btnNewButton_11.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (!hayOperacion && (LabelPantalla.getText().length() > 0)) {
					num1 = LabelPantalla.getText();
					hayOperacion = true;
					tipo = '2';
					LabelPantalla.setText("");
				}
			}
		});
		btnNewButton_11.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_11);

		JButton btnNewButton_12 = new JButton("7");
		btnNewButton_12.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (LabelPantalla.getText().length() <= maxLen) {
					limpiar(LabelPantalla);
					LabelPantalla.setText(LabelPantalla.getText() + "7");
				}
			}
		});
		btnNewButton_12.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_12);

		JButton btnNewButton_13 = new JButton("8");
		btnNewButton_13.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (LabelPantalla.getText().length() <= maxLen) {
					limpiar(LabelPantalla);
					LabelPantalla.setText(LabelPantalla.getText() + "8");
				}
			}
		});
		btnNewButton_13.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_13);

		JButton btnNewButton_14 = new JButton("9");
		btnNewButton_14.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (LabelPantalla.getText().length() <= maxLen) {
					limpiar(LabelPantalla);
					LabelPantalla.setText(LabelPantalla.getText() + "9");
				}
			}
		});
		btnNewButton_14.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_14);

		JButton btnNewButton_15 = new JButton("+");
		btnNewButton_15.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (!hayOperacion && (LabelPantalla.getText().length() > 0)) {
					num1 = LabelPantalla.getText();
					hayOperacion = true;
					tipo = '1';
					LabelPantalla.setText("");
				}
			}
		});
		btnNewButton_15.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_15);

		JButton btnNewButton_16 = new JButton("+/-");
		btnNewButton_16.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				limpiar(LabelPantalla);
				if (LabelPantalla.getText().length() > 0) {
					String str = toggleGuionInicial(LabelPantalla.getText());
					LabelPantalla.setText(str);
				}
			}
		});
		btnNewButton_16.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_16);

		JButton btnNewButton_17 = new JButton("0");
		btnNewButton_17.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String str = LabelPantalla.getText();
				if(str.length()>0&&str.charAt(0) == '0'&&str.length()<=1) {return;}
				if (str.length() <= maxLen ) {
					limpiar(LabelPantalla);
					LabelPantalla.setText(str + "0");
				}
			}
		});
		btnNewButton_17.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_17);

		JButton btnNewButton_18 = new JButton(".");
		btnNewButton_18.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (!hayPunto(LabelPantalla.getText()) && LabelPantalla.getText().length() >= 1) {
					LabelPantalla.setText(LabelPantalla.getText() + ".");
				}
			}
		});
		btnNewButton_18.setFont(new Font("Tahoma", Font.PLAIN, 20));
		panelTaclado.add(btnNewButton_18);

		JButton btnNewButton_19 = new JButton("=");
		btnNewButton_19.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (hayOperacion && (LabelPantalla.getText().length() > 0)) {
					num2 = LabelPantalla.getText();
					hayOperacion = false;
					hayIgual = true;
					if (tipo == '1') {
						LabelPantalla.setText(Calculadora.suma(num1, num2));
					} else if (tipo == '2') {
						LabelPantalla.setText(Calculadora.resta(num1, num2));
					} else if (tipo == '3') {
						LabelPantalla.setText(Calculadora.multiplicacion(num1, num2));
					} else if (tipo == '4') {
						LabelPantalla.setText(Calculadora.divicion(num1, num2));
					} else if (tipo == '5') {
						LabelPantalla.setText(Calculadora.porsentaje(num1, num2));
					}
				}
			}
		});
		btnNewButton_19.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panelTaclado.add(btnNewButton_19);

	}

}
