package com.learning.spring.CD;

import org.junit.Rule;
import org.junit.Test;
import org.junit.contrib.java.lang.system.SystemOutRule;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

//todo test
//import org.junit.contrib.java.lang.system.SystemOutRule;

//import org.junit.contrib.java.lang.system.SystemOutRule;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes = CDPlayerConfig.class)
public class CDPlayerTest {

	@Rule
	public final SystemOutRule log = new SystemOutRule();

//	@Bean(name = "compactDisc")
//	public CompactDisc getStgPeppers() {
//		return new StgPeppers();
//	}

	@Autowired(required = true)
	private CompactDisc compactDisc;

//	@Autowired
//	private void setCompactDisc(CompactDisc compactDisc) {
//		this.compactDisc = compactDisc;
//	}


	@Test
	public void cdShouldNotBeNull(){
		assertNotNull(compactDisc);
	}

	@Test
	public void play(){
		System.out.println();
		test((()))
		inti i = new
		log.enableLog();
		compactDisc.play();
		assertEquals("Play Stg. Pepper's Lonely Hearts Club Band artist The Beatles\n", log.getLog());
		log.clearLog();
	}
}
