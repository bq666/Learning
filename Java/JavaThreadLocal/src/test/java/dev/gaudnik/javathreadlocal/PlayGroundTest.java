package dev.gaudnik.javathreadlocal;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class PlayGroundTest {

    @Test
    void runIt() {
        var firstUser = new SharedMapWithUserContext(1);
        var secondUser = new SharedMapWithUserContext(2);
        new Thread(firstUser).start();
        new Thread(secondUser).start();
        assertEquals(2, 2 );
        System.out.println(firstUser);
        System.out.println(secondUser);
    }
}