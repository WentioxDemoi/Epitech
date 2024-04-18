package com.Area.controller;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import com.Area.Service.UserService;
import com.Area.entity.User;


@RestController
@CrossOrigin(origins = "*")
public class UserController {
    @Autowired
    private UserService service;

    @PostMapping("/registerUser")
    public ResponseEntity<Object>  registerUser(@RequestBody User user) {
        User result =  service.register(user);
        if (result != null) {
            long userId = result.getId();
            Map<String, Object> response = new HashMap<>();
            response.put("message", "User registered successfully");
            response.put("userId", userId);
            return ResponseEntity.ok().body(response);
        } else {
            Map<String, String> error = new HashMap<>();
            error.put("error", "User already exists");
            return ResponseEntity.badRequest().body(error);
        }
    }
    @GetMapping("/loginUser")
    public ResponseEntity<Object> loginUser(@RequestParam String username, @RequestParam String password) {
        User user = new User();
        user.setUsername(username);
        user.setPassword(password);
        User result = service.login(user);
        if (result != null) {
            long userId = result.getId();
            Map<String, Object> response = new HashMap<>();
            response.put("message", "User logged in successfully");
            response.put("userId", userId);
            return ResponseEntity.ok().body(response);
        } else {
            Map<String, String> error = new HashMap<>();
            error.put("error", "User or password is incorrect");
            return ResponseEntity.badRequest().body(error);
        }
    }
    @GetMapping("/about.json")
    public String about(@RequestParam String ipAdress) throws IOException {
        System.out.println(ipAdress);
        String currentPath = System.getProperty("user.dir");
        String json = new String(Files.readAllBytes(Paths.get(currentPath + "/Documentation/about.json")), StandardCharsets.UTF_8);
        String currentTime = String.valueOf(System.currentTimeMillis() / 1000L);
        json = json.replace("REPLACEBYID", ipAdress);
        json = json.replace("REPLACEBYTIME", currentTime);
        return json;
    }

    // @GetMapping("/about.json")
    // public String about(@RequestParam String ipAddress) throws IOException {
    //     // Charger le contenu du fichier about.json dans une chaîne de caractères
    //     String json = new String(Files.readAllBytes(Paths.get("about.json")), StandardCharsets.UTF_8);

    //     // Remplacer les chaînes de caractères "REPLACEBYID" et "REPLACEBYTIME" par les valeurs appropriées
    //     String currentTime = String.valueOf(System.currentTimeMillis() / 1000L);
    //     json = json.replace("REPLACEBYID", ipAddress);
    //     json = json.replace("REPLACEBYTIME", currentTime);

    //     // Retourner le contenu mis à jour sous forme de chaîne de caractères
    //     return json;
    // }
}