package com.Area.Service;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

@JsonIgnoreProperties(ignoreUnknown = true)
public class OpenWeatherResponse {
    private Main main;
    
    public Main getMain() {
        return main;
    }

    public void setMain(Main main) {
        this.main = main;
    }

    @JsonIgnoreProperties(ignoreUnknown = true)
    public static class Main {
        private float temp;
        private float humidity;

        private float pressure;

        private float temp_min;

        private float temp_max;

        //action en plus

        private float feels_like;

        private float sea_level;

        private float grnd_level;

        public float getSea_level() {
            return sea_level;
        }

        public float getGrnd_level() {
            return grnd_level;
        }

        public float getFeels_like() {
            return feels_like;
        }

        public float getTemp_min() {
            return temp_min;
        }

        public float getTemp_max() {
            return temp_max;
        }

        public float getTemp() {
            return temp;
        }

        public float getHumidity() {
            return humidity;
        }

        public float getPressure() {
            return pressure;
        }

        public void setTemp(float temp) {
            this.temp = temp;
        }

        public void setHumidity(float humidity) {
            this.humidity = humidity;
        }

        public void setPressure(float pressure) {
            this.pressure = pressure;
        }

        public void setTemp_min(float temp_min) {
            this.temp_min = temp_min;
        }

        public void setTemp_max(float temp_max) {
            this.temp_max = temp_max;
        }

        public void setFeels_like(float feels_like) {
            this.feels_like = feels_like;
        }

        public void setGrnd_level(float grnd_level) {
            this.grnd_level = grnd_level;
        }

        public void setSea_level(float sea_level) {
            this.sea_level = sea_level;
        }
        
    }
}
