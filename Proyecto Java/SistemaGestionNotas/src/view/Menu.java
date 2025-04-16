package view;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import javax.swing.border.EmptyBorder;
import controller.GestorNotas;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;

public class Menu extends JFrame {

	private static final long serialVersionUID = 1L;
    private JPanel contentPane;
    private GestorNotas gestorNotas = new GestorNotas();
    private AddNote addNoteFrame; // Referencia a la ventana AddNote
    private BuscarNota buscarNota;
    private ListarNota listarNota;
    private EditarNota editarNota;
    private EliminarNota eliminarNota;

    public Menu() {
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
        lblNewLabel.setOpaque(true);
        lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
        contentPane.add(lblNewLabel);

        JButton btnAgregarNota = new JButton("Agregar Nota");
        btnAgregarNota.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                mostrarAddNote();
            }
        });
        contentPane.add(btnAgregarNota);

        JButton btnBuscarNota = new JButton("Buscar Nota");
        btnBuscarNota.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	mostraBuscarNota();
            }
        });
        contentPane.add(btnBuscarNota);

        JButton btnEditarNota = new JButton("Editar Nota");
        btnEditarNota.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                mostrarEditar();
            }
        });
        contentPane.add(btnEditarNota);

        JButton btnEliminarNota = new JButton("Eliminar Nota");
        btnEliminarNota.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	mostraEliminarNota();
            }
        });
        contentPane.add(btnEliminarNota);

        JButton btnListarNotas = new JButton("Listar Notas");
        btnListarNotas.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	mostraListarNota();
            }
        });
        contentPane.add(btnListarNotas);
    }

    // Método para mostrar la ventana AddNote
    private void mostrarAddNote() {
        if (addNoteFrame == null) {
            addNoteFrame = new AddNote(this, gestorNotas);
        }
        addNoteFrame.setVisible(true);
        setVisible(false);
    }
    
    private void mostraBuscarNota() {
        if (buscarNota == null) {
        	buscarNota = new BuscarNota(this, gestorNotas);
        }
        buscarNota.setVisible(true);
        setVisible(false);
    }
    private void mostraListarNota() {
        if (listarNota == null) {
        	listarNota = new ListarNota(this, gestorNotas);
        }
        listarNota.setVisible(true);
        setVisible(false);
    }
    
    private void mostrarEditar() {
    	if (editarNota == null) {
    		editarNota = new EditarNota(this, gestorNotas);
        }
    	editarNota.setVisible(true);
        setVisible(false);
	}
    private void mostraEliminarNota() {
    	if (eliminarNota == null) {
    		eliminarNota = new EliminarNota(this, gestorNotas);
        }
    	eliminarNota.setVisible(true);
        setVisible(false);
    }

    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    Menu frame = new Menu();
                    frame.setVisible(true);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }
}
