package sample;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.Modality;
import javafx.stage.Stage;


//public class ConfirmBox extends Application {
//
//	Stage window;
//	Button button;
//	StackPane layout;
//	Scene scene;
//
//
//
//	public static void main(String[] args) {
//		launch(args);
//
//	}
//
//	@Override
//	public void start(Stage primaryStage) throws Exception {
//		window = primaryStage;
//		window.setTitle("My title");
//
//		button = new Button("Click me");
//		button.setOnAction(e -> ConfirmBox.display("MyTitle", "MyMessage"));
//
//		layout = new StackPane();
//		layout.getChildren().add(button);
//		scene = new Scene(layout, 300, 250);
//		window.setScene(scene);
//		window.show();
//	}
//}


class ConfirmBox {

	static boolean answer;


	public static boolean display(String title, String message){
		Stage window = new Stage();
		window.initModality(Modality.APPLICATION_MODAL);
		window.setTitle(title);
		window.setMinWidth(250);

		Label label = new Label();
		label.setText(message);

		Button closeButton = new Button("Close the window");
		closeButton.setOnAction(event -> window.close());

		Button yesButton = new Button("Yes");
		Button noButton = new Button("No");
		yesButton.setOnAction(e -> {
			answer = true;
			window.close();
		});
		noButton.setOnAction(e -> {
			answer = false;
			window.close();
		});


		VBox layout = new VBox(10);
		layout.getChildren().addAll(label, yesButton, noButton);
		label.setAlignment(Pos.CENTER);

		Scene scene = new Scene(layout);
		window.setScene(scene);
		window.showAndWait();

		return answer;
	}
}