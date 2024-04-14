package com.Area.Service;
import org.springframework.stereotype.Service;
import java.time.LocalDateTime;

@Service
public class MinutesMultipleOfFive {

    public boolean IsMinutesMultipleOfFive() {
        LocalDateTime now = LocalDateTime.now();
        int minutes = now.getMinute();
        if ((minutes % 5) == 0)
            return true;
        else
            return false;
    }
}