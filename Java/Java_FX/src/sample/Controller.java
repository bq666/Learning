package sample;

import javafx.event.ActionEvent;

public class Controller {
//	public static void methodTest(){
//		System.out.println("test from controler");
//	}

	public static void methodTest(ActionEvent event) {
		System.out.println(event.getSource());
		System.out.println("test from controler");
	}
}
