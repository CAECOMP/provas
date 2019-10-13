package janelaso;
/**
 *
 * @author Alessandra
 */
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javax.swing.JOptionPane;

public class HospedeCanalPainel {

    
    private Label infoLabel; // test
    private Label numCanalTitle;
    private Label numHospedeTitle;
    private TextField numCanalTextField;
    private TextField numHospedeTextField;
    private Scene scene;
    private HBox hBoxPanel;
    private HBox hBoxPanelTwo;
    private HBox buttonHBox;
    private VBox vBoxPainel;
    private Button okButton;
    private Button cancelButton;

    public Label getInfoLabel() {
        if (infoLabel == null) {
            infoLabel = new Label();
            infoLabel.setText("INFORMAÇÕES DE ENTRADA");
            infoLabel.setFont(Font.font("Arial", FontWeight.BOLD, 14));
            infoLabel.setUnderline(true);
        }
        return infoLabel;
    }

    public Scene getScene() {
        if (scene == null) {
            scene = new Scene(getVBoxPainel(), 270, 180);
         //   scene.getStylesheets().add("/stylepainel.css");
            scene
                    .setFill(Color.WHITE);  //cinza 234-234-238
        }
        return scene;
    }

    public VBox getVBoxPainel() {
        if (vBoxPainel == null) {
            vBoxPainel = new VBox();
            vBoxPainel.getChildren().add(getInfoLabel());
            vBoxPainel.getChildren().add(getHBoxPanel());
            vBoxPainel.getChildren().add(getHBoxPanelTwo());
            vBoxPainel.getChildren().add(getButtonHBox());
            vBoxPainel.setSpacing(15);
            vBoxPainel.setPadding(new Insets(30));
        }
        return vBoxPainel;
    }

    public HBox getHBoxPanel() {
        if (hBoxPanel == null) {
            hBoxPanel = new HBox(10);
            hBoxPanel.setTranslateX(10);
            hBoxPanel.setTranslateY(10);
            hBoxPanel.getChildren().add(getNumCanalTitle());
            hBoxPanel.getChildren().add(getNumCanalTextField());
        }
        return hBoxPanel;
    }

    public HBox getHBoxPanelTwo() {
        if (hBoxPanelTwo == null) {
            hBoxPanelTwo = new HBox(10);
            hBoxPanelTwo.setTranslateX(10);
            hBoxPanelTwo.setTranslateY(10);
            hBoxPanelTwo.getChildren().add(getNumHospedeTitle());
            hBoxPanelTwo.getChildren().add(getNumHospedeTextField());
        }
        return hBoxPanelTwo;
    }

    public Label getNumCanalTitle() {
        if (numCanalTitle == null) {
            numCanalTitle = new Label("--> NUM. CANAIS     ");
            numCanalTitle.setFont(new javafx.scene.text.Font(14));
            numCanalTitle.setMaxWidth(Double.MAX_VALUE);
        }
        return numCanalTitle;
    }

    public TextField getNumCanalTextField() {
        if (numCanalTextField == null) {
            numCanalTextField = new TextField();
            // numHospedeTextField.setMaxSize(50, 23);
            numCanalTextField.setPrefWidth(50);
            numCanalTextField.setAlignment(Pos.CENTER);
        }
        return numCanalTextField;
    }

    public Label getNumHospedeTitle() {
        if (numHospedeTitle == null) {
            numHospedeTitle = new Label("--> NUM. HOSPEDES");
            numHospedeTitle.setFont(new javafx.scene.text.Font(14));
            numHospedeTitle.setMaxWidth(Double.MAX_VALUE);
        }
        return numHospedeTitle;
    }

    public TextField getNumHospedeTextField() {
        if (numHospedeTextField == null) {
            numHospedeTextField = new TextField();
            // numHospedeTextField.setMaxSize(50, 23);
            numHospedeTextField.setPrefWidth(50);
            numHospedeTextField.setAlignment(Pos.CENTER);
        }
        return numHospedeTextField;
    }

    public Button getOkButton() {
        if (okButton == null) {
            okButton = new Button("Ok");
        }
        return okButton;
    }

    public Button getCancelButton() {
        if (cancelButton == null) {
            cancelButton = new Button("Cancel");
            cancelButton.setPrefHeight(200);
            cancelButton.setPrefWidth(70);
        }
        return cancelButton;
    }

    public HBox getButtonHBox() {
        if (buttonHBox == null) {
            buttonHBox = new HBox();
            buttonHBox.getChildren().add(getOkButton());
            buttonHBox.getChildren().add(getCancelButton());
            buttonHBox.setSpacing(10);
            buttonHBox.setPadding(new Insets(15));
            buttonHBox.setAlignment(Pos.BOTTOM_CENTER);

        }
        return buttonHBox;
    }
    
    
    public int validateData(HospedeCanalPainel host){
        int validadeC, validadeH;
        try {
            validadeC = Integer.parseInt(host.getNumCanalTextField().getText());
            validadeH = Integer.parseInt(host.getNumHospedeTextField().getText());
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Entrada inválida!");
            return -1;
        }
        return 0;
    }
    
    public int getCanais(HospedeCanalPainel host){
        int canais = Integer.parseInt(host.getNumCanalTextField().getText());
        return canais;
    }
    
    public int getHospedes(HospedeCanalPainel host){
        int hospede = Integer.parseInt(host.getNumHospedeTextField().getText());
        return hospede;
    }
    
}