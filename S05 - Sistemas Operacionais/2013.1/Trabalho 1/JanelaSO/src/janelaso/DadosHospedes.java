/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package janelaso;

import java.util.Random;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;

/**
 *
 * @author Alessandra
 */
public class DadosHospedes {

    private Label hospedeLabel;
    private Label descansoLabel;
    private Label assistirLabel;
    Text[] AssistirArrayText;
    Text[] DescasarArrayText;
    private Scene scene;
    private HBox hBoxPanel;
    private HBox hBoxPanelTwo;
    private Button okButton;
    private Button cancelButton;
    private GridPane grid;
    private int nHospedes;

    public DadosHospedes(HospedeCanalPainel host) {
        nHospedes = host.getHospedes(host);
    }

    public int getnHospedes() {
        return nHospedes;
    }

    public Label getHospedeLabel() {
        if (hospedeLabel == null) {
            hospedeLabel = new Label();
            hospedeLabel.setText("Hóspedes");
            hospedeLabel.setFont(Font.font("Arial", FontWeight.NORMAL, 20));
            getGrid().add(hospedeLabel, 1, 1);
            hospedeLabel.setTranslateX(70);
        }
        return hospedeLabel;
    }

    public Label getDescansoLabel() {
        if (descansoLabel == null) {
            descansoLabel = new Label();
            descansoLabel.setText("Descanso");
            descansoLabel.setFont(Font.font("Arial", FontWeight.NORMAL, 20));
            getGrid().add(descansoLabel, 4, 1);
            descansoLabel.setTranslateX(70);
        }
        return descansoLabel;
    }

    public Label getAssistirLabel() {
        if (assistirLabel == null) {
            assistirLabel = new Label();
            assistirLabel.setText("Assistir");
            assistirLabel.setFont(Font.font("Arial", FontWeight.NORMAL, 20));
            getGrid().add(assistirLabel, 6, 1);
            assistirLabel.setTranslateX(70);
        }
        return assistirLabel;
    }

    public GridPane getGrid() {
        if (grid == null) {
            grid = new GridPane();
            grid.setAlignment(Pos.TOP_LEFT);
            grid.setHgap(10);
            grid.setVgap(10);
            grid.setPadding(new Insets(0, 0, 0, 0));
            getAssistirLabel();
            getHospedeLabel();
            getDescansoLabel();
            gethBoxPanel();
            adcionaLabels();
            geraIntervaloAssistindo();
            geraIntervaloDescansando();
            gethBoxPanelTwo();
        }
        return grid;
    }

    public void changeSizeWidth(TextField Tx) {
        Tx.setMinWidth(40);
        Tx.setPrefWidth(50);
        Tx.setMaxWidth(50);
    }

    public void adcionaLabels() {
        int row;
        int s = 0;
        for (int i = 0; i < getnHospedes(); i++) {
            s = i + 1;
            row = i + 3;
            Text lbList = new Text("Hóspede " + s);
            lbList.setFont(Font.font("Tahoma", FontWeight.NORMAL, 18));
            getGrid().add(lbList, 1, row);
            lbList.setTranslateX(65);
        }
    }

    public String[] geraIntervaloAssistindo() {
        int row;
        String [] tempoAssistindo = new String[getnHospedes()];
        Random gerador = new Random();
        for (int i = 0; i < getnHospedes(); i++) {
            row = i + 3;
            int j = gerador.nextInt(100);
            String tp = Integer.toString(j);
            tempoAssistindo[i] = tp;
            Text lbList = new Text(tp + " s");
            lbList.setFont(Font.font("Tahoma", FontWeight.NORMAL, 18));
            getGrid().add(lbList, 7, row);
            lbList.setTranslateX(15);
        }
        
        return tempoAssistindo;
    }
    
    public String[] geraIntervaloDescansando() {
        int row;
        String [] tempoDescando = new String[getnHospedes()];
        Random gerador = new Random();
        for (int i = 0; i < getnHospedes(); i++) {
            row = i + 3;
            int j = gerador.nextInt(100);
            String tp = Integer.toString(j);
            tempoDescando[i] = tp;
            Text lbList = new Text(tp + " s");
            lbList.setFont(Font.font("Tahoma", FontWeight.NORMAL, 18));
            getGrid().add(lbList, 6, row);
            lbList.setTranslateX(-20);
        }
        
        return tempoDescando;
    }

    public Scene getScene() {
        int altura = 120;
        if (scene == null) {
            for (int i = 0; i < getnHospedes(); i++) {
                altura = altura + 25;
            }
            scene = new Scene(getGrid(), 500, altura);
        }
        return scene;
    }

    public HBox gethBoxPanel() {
        if (hBoxPanel == null) {
            hBoxPanel = new HBox(4);
            hBoxPanel.setAlignment(Pos.BASELINE_RIGHT);
            hBoxPanel.getChildren().add(getOkButton());
            grid.add(hBoxPanel, 6, nHospedes + 3);
            getOkButton().setTranslateX(8);
        }
        return hBoxPanel;
    }

    public Button getOkButton() {
        if (okButton == null) {
            okButton = new Button("Ok");
        }
        return okButton;
    }

    public HBox gethBoxPanelTwo() {
        if (hBoxPanelTwo == null) {
            hBoxPanelTwo = new HBox(4);
            hBoxPanelTwo.setAlignment(Pos.BASELINE_RIGHT);
            hBoxPanelTwo.getChildren().add(getCancelButton());
            grid.add(hBoxPanelTwo, 7, nHospedes + 3);
        }
        return hBoxPanelTwo;
    }

    public Button getCancelButton() {
        if (cancelButton == null) {
            cancelButton = new Button("Cancel");
        }
        return cancelButton;
    }

    public Text[] getDescasarIniArrayText() {
        if (DescasarArrayText == null) {
            DescasarArrayText = new Text[getnHospedes()];
        }
        return DescasarArrayText;
    }

    public Text[] getAssistirArrayText() {
        if (AssistirArrayText == null) {
            AssistirArrayText = new Text[getnHospedes()];
        }
        return AssistirArrayText;
    }
}
