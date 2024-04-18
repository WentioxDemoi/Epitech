package com.Area.Service;

import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

@Service
public class ChuckNorrisJokeService {
    
    private static final String API_URL = "https://api.chucknorris.io/jokes/random";
    
    public String getRandomJoke() {
        RestTemplate restTemplate = new RestTemplate();
        ChuckNorrisJoke joke = restTemplate.getForObject(API_URL, ChuckNorrisJoke.class);
        if (joke == null)
            return "Chuck Norris doesn't need jokes.";
        return joke.getValue();
    }
    
    private static class ChuckNorrisJoke {
        private String value;
        public String getValue() {
            return value;
        }
    }
}
