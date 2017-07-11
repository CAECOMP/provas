package janelaso;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.stage.Stage;
import javax.swing.JOptionPane;

/**
 *
 * @author Alessandra
 */
public class JanelaSO extends Application {

    HospedeCanalPainel hospedeCanalPainel;
    DadosHospedes dadosHospedes;

    public static void main(String[] args) {
        launch();
    }

    @Override
    public void start(final Stage palco) throws Exception {
        palco.setScene(getHospedeCanalPainel().getScene());
        palco.setTitle("Hóspedes e Canais");
        palco.setResizable(false);
        hospedeCanalPainel.getOkButton().setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent t) {
                int validade = hospedeCanalPainel.validateData(hospedeCanalPainel);
                if (validade == 0) {
                    palco.close();
                    final Stage palcoDados = new Stage();
                    palcoDados.setTitle("Dados dos hóspedes");
                    palcoDados.setResizable(false);
                    palcoDados.setScene(getDadosHospedes().getScene());
                    dadosHospedes.getOkButton().setOnAction(new EventHandler<ActionEvent>() {
                        @Override
                        public void handle(ActionEvent t) {
                            
                        }
                    });

                    dadosHospedes.getCancelButton().setOnAction(new EventHandler<ActionEvent>() {
                        @Override
                        public void handle(ActionEvent t) {
                            int i = JOptionPane.showConfirmDialog(null, "Deseja fechar a aplicação?",
                                    "Atenção!", JOptionPane.YES_NO_OPTION);
                            if (i == JOptionPane.YES_OPTION) {
                                System.exit(0);
                            } else {
                                palcoDados.show();
                            }
                        }
                    });
                    palcoDados.show();
                }
            }
        });

        hospedeCanalPainel.getCancelButton().setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent t) {
                System.exit(0);
            }
        });

        palco.show();

    }

    public HospedeCanalPainel getHospedeCanalPainel() {
        if (hospedeCanalPainel == null) {
            hospedeCanalPainel = new HospedeCanalPainel();
        }
        return hospedeCanalPainel;
    }

    public DadosHospedes getDadosHospedes() {
        if (dadosHospedes == null) {
            dadosHospedes = new DadosHospedes(hospedeCanalPainel);
        }
        return dadosHospedes;
    }
}