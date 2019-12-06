package com.learning.spring.CD;

import org.springframework.stereotype.Component;

@Component
public class StgPeppers implements CompactDisc {

	private String title = "Stg. Pepper's Lonely Hearts Club Band";
	private String artist = "The Beatles";

	@Override
	public void play() {
		int i = 100;
		System.out.println("Play " + title + " artist " + artist);
	}


}
