package sample;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.Modality;
import javafx.stage.Stage;


public class CreatingAlertBoxes extends Application {

	Stage window;
	StackPane layout;
	Scene scene;
	Button button;
	boolean answer;


	public static void main(String[] args) {
		launch(args);

	}

	@Override
	public void start(Stage primaryStage) throws Exception {
		window = primaryStage;
		window.setTitle("My title");

		button = new Button("Click me");
		button.setOnAction(e -> {
			answer = ConfirmBox.display("MyTitle", "MyMessage");
			System.out.println(answer + "<---- from lambda");
		});

		System.out.println(answer);

		layout = new StackPane();
		layout.getChildren().add(button);
		scene = new Scene(layout, 300, 250);
		window.setScene(scene);
		window.show();
	}
}


class AlertBox2{
	public static void display(String title, String message){
		Stage window = new Stage();

		window.initModality(Modality.APPLICATION_MODAL);
		window.setTitle(title);
		window.setMinWidth(250);

		Label label = new Label();
		label.setText(message);
		Button closeButton = new Button("Close the window");
		closeButton.setOnAction(event -> window.close());

		VBox layout = new VBox(10);
		layout.getChildren().addAll(label, closeButton);
		label.setAlignment(Pos.CENTER);

		Scene scene = new Scene(layout);
		window.setScene(scene);
		window.showAndWait();
	}
}