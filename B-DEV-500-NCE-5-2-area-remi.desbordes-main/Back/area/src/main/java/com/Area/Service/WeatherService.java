package com.Area.Service;

import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import java.util.Objects;

@Service
public class WeatherService {
    private final RestTemplate restTemplate = new RestTemplate();
    private final String apikey = "0e06f6ad6382ce88d90db8a6b05a7421";

    public int getTempWeather(String latitude, String longitude) {
        final String url = "https://api.openweathermap.org/data/2.5/weather?lat=" + latitude + "&lon=" + longitude + "&APPID=" + apikey + "&units=metric";
        ResponseEntity<OpenWeatherResponse> response = restTemplate.getForEntity(url, OpenWeatherResponse.class);
        final int temp = (int) Objects.requireNonNull(response.getBody()).getMain().getTemp();
        return temp;
    }
    public int getHumidityWeather(String latitude, String longitude) {
        final String url = "https://api.openweathermap.org/data/2.5/weather?lat=" + latitude + "&lon=" + longitude + "&APPID=" + apikey + "&units=metric";
        ResponseEntity<OpenWeatherResponse> response = restTemplate.getForEntity(url, OpenWeatherResponse.class);
        final int humidity = (int) Objects.requireNonNull(response.getBody()).getMain().getHumidity();
        return humidity;
    }
    public int getPressureWeather(String latitude, String longitude) {
        final String url = "https://api.openweathermap.org/data/2.5/weather?lat=" + latitude + "&lon=" + longitude + "&APPID=" + apikey + "&units=metric";
        ResponseEntity<OpenWeatherResponse> response = restTemplate.getForEntity(url, OpenWeatherResponse.class);
        final int pressure = (int) Objects.requireNonNull(response.getBody()).getMain().getPressure();
        return pressure;
    }
    public int getTempMinWeather(String latitude, String longitude) {
        final String url = "https://api.openweathermap.org/data/2.5/weather?lat=" + latitude + "&lon=" + longitude + "&APPID=" + apikey + "&units=metric";
        ResponseEntity<OpenWeatherResponse> response = restTemplate.getForEntity(url, OpenWeatherResponse.class);
        final int temp_min = (int) Objects.requireNonNull(response.getBody()).getMain().getTemp_min();
        return temp_min;
    }
    public int getTempMaxWeather(String latitude, String longitude) {
        final String url = "https://api.openweathermap.org/data/2.5/weather?lat=" + latitude + "&lon=" + longitude + "&APPID=" + apikey + "&units=metric";
        ResponseEntity<OpenWeatherResponse> response = restTemplate.getForEntity(url, OpenWeatherResponse.class);
        final int temp_max= (int) Objects.requireNonNull(response.getBody()).getMain().getTemp_max();
        return temp_max;
    }

    //action en plus
    public int getFeelsLikeWeather(String latitude, String longitude) {
        final String url = "https://api.openweathermap.org/data/2.5/weather?lat=" + latitude + "&lon=" + longitude + "&APPID=" + apikey + "&units=metric";
        ResponseEntity<OpenWeatherResponse> response = restTemplate.getForEntity(url, OpenWeatherResponse.class);
        final int feels_like = (int) Objects.requireNonNull(response.getBody()).getMain().getFeels_like();
        return feels_like;
    }
    public int getSeaLevelWeather(String latitude, String longitude) {
        final String url = "https://api.openweathermap.org/data/2.5/weather?lat=" + latitude + "&lon=" + longitude + "&APPID=" + apikey + "&units=metric";
        ResponseEntity<OpenWeatherResponse> response = restTemplate.getForEntity(url, OpenWeatherResponse.class);
        final int sea_level = (int) Objects.requireNonNull(response.getBody()).getMain().getSea_level();
        return sea_level;
    }
    public int getGrndLevelWeather(String latitude, String longitude) {
        final String url = "https://api.openweathermap.org/data/2.5/weather?lat=" + latitude + "&lon=" + longitude + "&APPID=" + apikey + "&units=metric";
        ResponseEntity<OpenWeatherResponse> response = restTemplate.getForEntity(url, OpenWeatherResponse.class);
        final int grnd_level = (int) Objects.requireNonNull(response.getBody()).getMain().getGrnd_level();
        return grnd_level;
    }
}