package dev.gaudnik.javathreadlocal;

import java.util.UUID;

class UserRepository {

    String getUserNameForUserId(Integer userId) {
        return UUID.randomUUID().toString();
    }
}
