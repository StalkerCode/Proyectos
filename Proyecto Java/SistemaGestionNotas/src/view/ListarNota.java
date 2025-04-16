package view;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.border.EmptyBorder;
import controller.GestorNotas;
import model.Nota;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;

import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Font;
import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JButton;


public class ListarNota extends JFrame {

    private static final long serialVersionUID = 1L;
    private JPanel contentPane;
    private JPanel lista;
    private Menu menuFrame;
    private GestorNotas gestorNotas;
    private boolean revisoBoolean = false; // Cambiar a boolean
    private Color colorID = new Color(128, 255, 255);
    private Color colorTitulo = new Color(167, 200, 245);
    private Color colorContenido = new Color(167, 245, 227);
    private Color colorFecha = new Color(129, 235, 35);

    private void agregarPanelInformacion(String id, String titulo, String contenido, String fecha) {
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout(0, 0));
        JLabel lblId = new JLabel(id);
        lblId.setFont(new Font("Tahoma", Font.PLAIN, 17));
        lblId.setBackground(colorID);
        lblId.setOpaque(true);
        lblId.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createLineBorder(Color.BLACK, 2),
            BorderFactory.createEmptyBorder(5, 5, 5, 5) // Padding interior
        ));
        panel.add(lblId, BorderLayout.WEST);

        JPanel panelCentro = new JPanel();
        panelCentro.setLayout(new BorderLayout(0, 0));
        panel.add(panelCentro, BorderLayout.CENTER);

        JLabel lblTitulo = new JLabel(titulo);
        lblTitulo.setFont(new Font("Tahoma", Font.PLAIN, 17));
        lblTitulo.setBackground(colorTitulo);
        lblTitulo.setOpaque(true);
        lblTitulo.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createLineBorder(Color.BLACK, 2),
            BorderFactory.createEmptyBorder(5, 5, 5, 5)));
        panelCentro.add(lblTitulo, BorderLayout.WEST);

        JLabel lblContenido = new JLabel(contenido);
        lblContenido.setFont(new Font("Tahoma", Font.PLAIN, 17));
        lblContenido.setBackground(colorContenido);
        lblContenido.setOpaque(true);
        lblContenido.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createLineBorder(Color.BLACK, 2),
            BorderFactory.createEmptyBorder(5, 5, 5, 5)));
        panelCentro.add(lblContenido, BorderLayout.CENTER);

        JLabel lblFecha = new JLabel(fecha);
        lblFecha.setFont(new Font("Tahoma", Font.PLAIN, 17));
        lblFecha.setBackground(colorFecha);
        lblFecha.setOpaque(true);
        lblFecha.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createLineBorder(Color.BLACK, 2),
            BorderFactory.createEmptyBorder(5, 5, 5, 5)));
        panel.add(lblFecha, BorderLayout.EAST);

        // Agregar el panel de información al panel Lista
        lista.add(panel);

        // Agregar un borde o espacio entre paneles si es necesario
        panel.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
    }

    private void agregarItems() {
        if (!revisoBoolean) {
            revisoBoolean = true;
            if (gestorNotas.listarNotas().isEmpty()) {
                agregarPanelInformacion("", "no", " hay items", "");
                return;
            }
            for (Nota n : gestorNotas.listarNotas()) {
                agregarPanelInformacion(Integer.toString(n.getId()), n.getTitulo(), n.getContenido(), n.formatoFecha());
            }
        }
    }

    private void limpiarLista() {
        lista.removeAll();
        lista.revalidate();
        lista.repaint();
        System.gc();
    }

    public ListarNota(Menu menuFrame, GestorNotas gestorNotas) {
        this.menuFrame = menuFrame;
        this.gestorNotas = gestorNotas;

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 500, 450);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        setContentPane(contentPane);
        contentPane.setLayout(new BorderLayout(0, 0));

        JPanel panelTitulo = new JPanel();
        contentPane.add(panelTitulo, BorderLayout.NORTH);
        panelTitulo.setLayout(new BorderLayout(0, 0));

        JLabel labelTitulo = new JLabel("Listar Nota");
        labelTitulo.setBackground(new Color(128, 255, 255));
        labelTitulo.setOpaque(true);
        labelTitulo.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        labelTitulo.setFont(new Font("Tahoma", Font.PLAIN, 20));
        labelTitulo.setHorizontalAlignment(SwingConstants.CENTER);
        panelTitulo.add(labelTitulo, BorderLayout.NORTH);

        JPanel panelCurpo = new JPanel();
        panelCurpo.setBackground(new Color(128, 255, 128));
        contentPane.add(panelCurpo, BorderLayout.CENTER);
        panelCurpo.setLayout(new BorderLayout(0, 0));

        JPanel panelListar = new JPanel();
        panelCurpo.add(panelListar, BorderLayout.NORTH);
        panelListar.setLayout(new BorderLayout(0, 0));

        JButton buttonListar = new JButton("Listar Notas");
        buttonListar.addActionListener(e -> {
            agregarItems();
        });
        buttonListar.setFont(new Font("Tahoma", Font.PLAIN, 15));
        panelListar.add(buttonListar, BorderLayout.NORTH);

        // Crear el panel Lista con un BoxLayout vertical
        lista = new JPanel();
        lista.setBackground(new Color(128, 255, 128));
        lista.setLayout(new BoxLayout(lista, BoxLayout.Y_AXIS));

        // Envolver el panel Lista en un JScrollPane
        JScrollPane scrollPane = new JScrollPane(lista);
        panelCurpo.add(scrollPane, BorderLayout.CENTER);

        JPanel panelRegresar = new JPanel();
        panelCurpo.add(panelRegresar, BorderLayout.SOUTH);
        panelRegresar.setLayout(new BorderLayout(0, 0));

        JButton buttonRegresar = new JButton("Regresar");
        buttonRegresar.addActionListener(e -> {
            limpiarLista();
            revisoBoolean = false;
            // Regresar al menú principal
            menuFrame.setVisible(true);
            dispose();
        });
        buttonRegresar.setFont(new Font("Tahoma", Font.PLAIN, 15));
        panelRegresar.add(buttonRegresar, BorderLayout.NORTH);
        setMinimumSize(new Dimension(600, 550));
    }
}