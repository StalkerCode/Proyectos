package calculadoraui;

import java.awt.Dimension;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import calculadora.*;

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
		
	}
	

}
