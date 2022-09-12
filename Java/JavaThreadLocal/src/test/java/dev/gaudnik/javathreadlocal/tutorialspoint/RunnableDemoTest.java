package dev.gaudnik.javathreadlocal.tutorialspoint;

import org.springframework.context.annotation.Bean;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.provisioning.InMemoryUserDetailsManager;

import static org.junit.jupiter.api.Assertions.*;

class RunnableDemoTest {

    @Bean
    public InMemoryUserDetailsManager getUserDetailsManager(){
        UserDetails user = User.withDefaultPasswordEncoder()
                .username("user")
                .password("password")
                .roles("USER")
                .build();

        UserDetails user2 = User.withDefaultPasswordEncoder()
                .username("user2")
                .password("password")
                .roles("ADMIN")
                .build();
        return null;
    }


    public static void main(String[] args) {
        System.out.println("hello");
        var loader = RunnableDemoTest.class.getClassLoader();
        System.out.println(loader);
        var r = Runtime.getRuntime();
        System.out.println(r.availableProcessors());
        System.out.println(r.maxMemory());
        System.out.println(r.totalMemory());
        System.out.println(r.freeMemory());

    }

}
