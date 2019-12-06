package com.learning.spring.CD;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
//@ComponentScan
public class CDPlayerConfig {
	@Bean(name = "compactDisc")
	public CompactDisc getStgPeppers() {
		return new StgPeppers();
	}
}
