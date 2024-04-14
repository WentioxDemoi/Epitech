package com.Area.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import com.Area.entity.User;

public interface UserRepository extends JpaRepository<User, Integer> {
    User findByUsername(String username);
    User findByUsernameAndPassword(String username, String password);
    User findById(long id);
}