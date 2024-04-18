package com.Area.controller;

import java.io.IOException;
import java.net.URLDecoder;
import java.nio.charset.StandardCharsets;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;

import com.Area.repository.ObjectRepository;
import com.Area.entity.Object;
import com.Area.configuration.*;

@RestController
@RequestMapping("/webhook")
public class WebhookController {

    @Autowired
    private ObjectRepository objectRepository;

    @Autowired
    private checkAction checkaction;
    
    @PostMapping
    public String Banches(@RequestBody String payload) {
        try {
            List<Object> objects = objectRepository.findAll();
            String decodedPayload = URLDecoder.decode(payload, StandardCharsets.UTF_8);
            ObjectMapper objectMapper = new ObjectMapper();
            JsonNode rootNode = objectMapper.readTree(decodedPayload);
            String Action = rootNode.get("action").asText();
            for (com.Area.entity.Object object : objects) {
                if (object.getAction().equals("A new repo is created") && Action.equals("created")) {
                    checkaction.reactionFuntion(object);
                }
                if (object.getAction().equals("A repo is deleted") && Action.equals("deleted")) {
                    checkaction.reactionFuntion(object);
                }
            }
        } catch (IOException e) {
            System.out.println("Invalid JSON payload: " + e.getMessage());
        }
        return (payload);
    }
}
