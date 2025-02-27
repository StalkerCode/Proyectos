package calculadoraui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
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
	private String num1 = "";
	private String num2 = "";
	private Boolean hayOperacion = false;
	private Boolean hayIgual = false;
	private static final int MAXLEN = 16;
	private Operacion tipo;

	private void limpiar(JLabel pantalla) {
		if (hayIgual) {
			pantalla.setText("");
			hayIgual = false;
		}
	}

	private boolean hayPunto(String str) {
		return str.contains(".");
	}

	private String guionInicial(String str) {
		return str.startsWith("-") ? str.substring(1) : "-" + str;
	}

	private enum Operacion {
		SUMA, RESTA, MULTIPLICACION, DIVISION, PORCENTAJE
	}

	private void operacionSeleccionada(JLabel labelPantalla, Operacion operacion) {
		if (!hayOperacion && (labelPantalla.getText().length() > 0)) {
			num1 = labelPantalla.getText();
			hayOperacion = true;
			tipo = operacion;
			labelPantalla.setText("");
		}
	}

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

		String[] tipoStrings = { "%", "CE", "C", "÷", "1", "2", "3", "*", "4", "5", "6", "-", "7", "8", "9", "+", "+/-",
				"0", ".", "=" };
		Font tipFont = new Font("Tahoma", Font.PLAIN, 18);
		JButton[] botoneTecladoButton = new JButton[20];
		for (int i = 0; i < 20; i++) {
			botoneTecladoButton[i] = new JButton(tipoStrings[i]);
			botoneTecladoButton[i].setFont(tipFont);
			panelTaclado.add(botoneTecladoButton[i]);
		}

		ActionListener botonesNumeroEvento = new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				JButton boton = (JButton) e.getSource();
				if (LabelPantalla.getText().length() <= MAXLEN) {
					limpiar(LabelPantalla);
					LabelPantalla.setText(LabelPantalla.getText() + boton.getText());
				}
			}
		};

		for (int i = 4; i <= 14; i++) {
			if (i != 7 && i != 11 && i != 15) {
				botoneTecladoButton[i].addActionListener(botonesNumeroEvento);
			}
		}
		ActionListener operacion = new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				operacionSeleccionada(LabelPantalla, Operacion.PORCENTAJE);
			}
		};
		botoneTecladoButton[0].addActionListener(operacion);

		operacion = new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				operacionSeleccionada(LabelPantalla, Operacion.DIVISION);
			}
		};
		botoneTecladoButton[3].addActionListener(operacion);
		operacion = new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				operacionSeleccionada(LabelPantalla, Operacion.MULTIPLICACION);
			}
		};
		botoneTecladoButton[7].addActionListener(operacion);
		operacion = new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				operacionSeleccionada(LabelPantalla, Operacion.RESTA);
			}
		};
		botoneTecladoButton[11].addActionListener(operacion);
		operacion = new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				operacionSeleccionada(LabelPantalla, Operacion.SUMA);
			}
		};
		botoneTecladoButton[15].addActionListener(operacion);

		botoneTecladoButton[1].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				num1 = null;
				num2 = null;
				hayOperacion = false;
				LabelPantalla.setText("");
			}
		});

		botoneTecladoButton[2].addActionListener(new ActionListener() {
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

		botoneTecladoButton[16].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				limpiar(LabelPantalla);
				if (LabelPantalla.getText().length() > 0) {
					String str = guionInicial(LabelPantalla.getText());
					LabelPantalla.setText(str);
				}
			}
		});

		botoneTecladoButton[17].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String str = LabelPantalla.getText();
				if (str.length() > 0 && str.charAt(0) == '0' && str.length() <= 1) {
					return;
				}
				if (str.length() <= MAXLEN) {
					limpiar(LabelPantalla);
					LabelPantalla.setText(str + "0");
				}
			}
		});

		botoneTecladoButton[18].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (!hayPunto(LabelPantalla.getText()) && LabelPantalla.getText().length() >= 1) {
					LabelPantalla.setText(LabelPantalla.getText() + ".");
				}
			}
		});

		botoneTecladoButton[19].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (hayOperacion && (LabelPantalla.getText().length() > 0)) {
					num2 = LabelPantalla.getText();
					hayOperacion = false;
					hayIgual = true;
					switch (tipo) {
					case SUMA:
						LabelPantalla.setText(Calculadora.suma(num1, num2));
						break;
					case RESTA:
						LabelPantalla.setText(Calculadora.resta(num1, num2));
						break;
					case MULTIPLICACION:
						LabelPantalla.setText(Calculadora.multiplicacion(num1, num2));
						break;
					case DIVISION:
						LabelPantalla.setText(Calculadora.divicion(num1, num2));
						break;
					case PORCENTAJE:
						LabelPantalla.setText(Calculadora.porsentaje(num1, num2));
						break;

					}

				}
			}
		});

	}

}