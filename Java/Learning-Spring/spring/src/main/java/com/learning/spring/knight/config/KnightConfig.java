package com.learning.spring.knight.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.learning.spring.knight.BraveKnight;
import com.learning.spring.knight.Knight;
import com.learning.spring.knight.Quest;
import com.learning.spring.knight.SlayDragonQuest;

@Configuration
public class KnightConfig {

  @Bean
  public Knight knight() {
    return new BraveKnight(quest());
  }
  
  @Bean
  public Quest quest() {
    return new SlayDragonQuest(System.out);
  }

}
