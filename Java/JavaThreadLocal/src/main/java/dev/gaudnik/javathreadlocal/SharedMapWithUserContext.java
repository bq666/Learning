package dev.gaudnik.javathreadlocal;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

class SharedMapWithUserContext implements Runnable {

    private static ThreadLocal<Context> userContext = new ThreadLocal<>();
    private Integer userId;
    private UserRepository userRepository = new UserRepository();

    public SharedMapWithUserContext(Integer i) {
       this.userId = i;
    }

    @Override
    public void run() {
        var userName = userRepository.getUserNameForUserId(userId);
        userContext.set(new Context(userName));
        System.out.println("thread context for given userId: " + userId + " is: " + userContext.get());

    }
}
