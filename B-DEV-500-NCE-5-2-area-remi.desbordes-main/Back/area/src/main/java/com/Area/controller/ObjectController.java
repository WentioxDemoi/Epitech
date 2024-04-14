package com.Area.controller;

import java.util.HashMap;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import com.Area.Service.ObjectService;
import com.Area.entity.Object;

@RestController
@CrossOrigin(origins = "*")
public class ObjectController {
    @Autowired
    private ObjectService service;

    @PostMapping("/addObject")
    public ResponseEntity<Map<String, String>> addSubject(@RequestBody Object object) {
        Object result = service.checkActionAndTriggerReactions(object);
        if (result != null) {
            Map<String, String> response = new HashMap<>();
            response.put("message", "Object added successfully");
            return ResponseEntity.ok().body(response);
        } else {
            Map<String, String> error = new HashMap<>();
            error.put("message", "error");
            return ResponseEntity.badRequest().body(error);
        }
    }
}
