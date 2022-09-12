package dev.test;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;

import java.lang.management.ManagementFactory;
import java.lang.management.ThreadMXBean;

@RestController
class DeadLockController {

    @PostMapping("/{id}")
    String test1(@PathVariable String id) {
        ThreadMXBean threadMXBean = ManagementFactory.getThreadMXBean();
        long[] threadIds = threadMXBean.findDeadlockedThreads();
        boolean deadLock = threadIds != null && threadIds.length > 0;
        System.out.println("Deadlocks found " + deadLock);
        System.out.println(threadMXBean.getThreadInfo(1));
        return String.valueOf(deadLock);
    }

}
