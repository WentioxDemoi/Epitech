package com.Area.Service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.Area.entity.User;
import com.Area.repository.UserRepository;

@Service
public class UserService {
    @Autowired
    private UserRepository repository;

    public User register(User user) {
        User existingUser = repository.findByUsername(user.getUsername());
        if (existingUser != null) {
            return null;
        }
        return repository.save(user);
    }

    public User login(User user) {
        User existingUser = repository.findByUsernameAndPassword(user.getUsername(), user.getPassword());
        if (existingUser == null) {
            return null;
        }
        return existingUser;
    }
    
}
