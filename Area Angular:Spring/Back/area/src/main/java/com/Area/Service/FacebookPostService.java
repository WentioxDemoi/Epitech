package com.Area.Service;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import com.restfb.DefaultFacebookClient;
import com.restfb.FacebookClient;
import com.restfb.Parameter;
import com.restfb.Version;
import com.restfb.exception.FacebookException;
import com.restfb.types.FacebookType;

@Service
public class FacebookPostService {

    private final FacebookClient facebook;
    private final String pageId;
    
    public FacebookPostService(@Value("${facebook.app-id}") String appId, 
                               @Value("${facebook.app-secret}") String appSecret, 
                               @Value("${facebook.page-id}") String pageId) {
        
        this.pageId = pageId;
        
        String accessToken = new DefaultFacebookClient(Version.LATEST)
            .obtainAppAccessToken(appId, appSecret)
            .getAccessToken();
        
        this.facebook = new DefaultFacebookClient(accessToken, Version.LATEST);
    }

    public boolean postToFacebook(String message) {
        try {
            facebook.publish(pageId + "/feed", FacebookType.class, Parameter.with("message", message));
            return true;
        } catch (FacebookException e) {
            e.printStackTrace();
            return false;
        }
    }
}
