package com.Area.configuration;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.scheduling.annotation.EnableScheduling;
import org.springframework.scheduling.annotation.Scheduled;

import com.Area.Service.ChuckNorrisJokeService;
import com.Area.Service.GitHubBranchService;
import com.Area.Service.MailSendService;
import com.Area.Service.MinutesMultipleOfFive;
import com.Area.Service.WeatherService;

import com.Area.repository.ObjectRepository;

import com.Area.entity.Object;
import com.Area.entity.User;

import com.Area.repository.UserRepository;

@Configuration
@EnableScheduling
public class checkAction {

    @Autowired
    private MailSendService mailSendService;
    @Autowired
    private WeatherService weatherService;
    @Autowired
    private ChuckNorrisJokeService chuckNorrisJokeService;
    @Autowired
    private ObjectRepository objectRepository;
    @Autowired
    private MinutesMultipleOfFive minutesMultipleOfFive;
    @Autowired
    private UserRepository repository;
    @Autowired
    private GitHubBranchService gitHubBranchService;

    public String repoOwner = "areanice"; //Ici, il faudra relier les infos du compte github de l'utilisateur
    public String repoName = "okokokok";
    public String ref = "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"; //"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"; //Ici, on a la clé personnel de l'utilisateur (à voir comment la récup);

    
    @Scheduled(fixedRate = 10000) // execute every 10 seconds
    public void ActionTest() {
        List<Object> objects = objectRepository.findAll();
        for (com.Area.entity.Object object : objects) {
            String[] tmp = object.getAction().split(" ");
            String latitude = tmp[0];
            String longitude = tmp[1];
        
            if (tmp[2].equals("actual")) {
                if (tmp[3].equals("temperature"))
                {
                    if (tmp[4].equals(">=")) {
                        if (weatherService.getTempWeather(latitude, longitude) >= Integer.parseInt(tmp[5]))
                            reactionFuntion(object);
                    }
                    if (tmp[4].equals("<=")) {
                        if (weatherService.getTempWeather(latitude, longitude) <= Integer.parseInt(tmp[5])) {
                            System.out.println("test");
                            reactionFuntion(object);
                        }
                    }
                }
                if (tmp[3].equals("humidity"))
                {
                    if (tmp[4].equals(">=")) {
                        if (weatherService.getHumidityWeather(latitude, longitude) >= Integer.parseInt(tmp[5]))
                            reactionFuntion(object);
                    }
                    if (tmp[4].equals("<=")) {
                        if (weatherService.getHumidityWeather(latitude, longitude) <= Integer.parseInt(tmp[5]))
                            reactionFuntion(object);
                    }
                }
                if (tmp[3].equals("pressure"))
                {
                    if (tmp[4].equals(">=")) {
                        if (weatherService.getPressureWeather(latitude, longitude) >= Integer.parseInt(tmp[5]))
                            reactionFuntion(object);
                    }
                    if (tmp[4].equals("<=")) {
                        if (weatherService.getPressureWeather(latitude, longitude) <= Integer.parseInt(tmp[5]))
                            reactionFuntion(object);
                    }
                }
                if (tmp[3].equals("sea"))
                {
                    if (tmp[5].equals(">=")) {
                        if (weatherService.getSeaLevelWeather(latitude, longitude) >= Integer.parseInt(tmp[6]))
                            reactionFuntion(object);
                    }
                    if (tmp[5].equals("<=")) {
                        if (weatherService.getSeaLevelWeather(latitude, longitude) <= Integer.parseInt(tmp[6]))
                            reactionFuntion(object);
                    }
                }
                if (tmp[3].equals("ground"))
                {
                    if (tmp[5].equals(">=")) {
                        if (weatherService.getGrndLevelWeather(latitude, longitude) >= Integer.parseInt(tmp[6]))
                            reactionFuntion(object);
                    }
                    if (tmp[5].equals("<=")) {
                        if (weatherService.getGrndLevelWeather(latitude, longitude) <= Integer.parseInt(tmp[6]))
                            reactionFuntion(object);
                    }
                }
            }
            if (tmp[2].equals("today"))
            {
                if (tmp[3].equals("max")) {
                    if (tmp[5].equals("<=")) {
                        if (weatherService.getTempMaxWeather(latitude, longitude) <= Integer.parseInt(tmp[6]))
                            reactionFuntion(object);
                    }
                    if (tmp[5].equals(">=")) {
                        if (weatherService.getTempMaxWeather(latitude, longitude) >= Integer.parseInt(tmp[6]))
                            reactionFuntion(object);
                    }
                }
                if (tmp[3].equals("min")) {
                    if (tmp[5].equals("<=")) {
                        if (weatherService.getTempMinWeather(latitude, longitude) <= Integer.parseInt(tmp[6]))
                            reactionFuntion(object);
                    }
                    if (tmp[5].equals(">=")) {
                        if (weatherService.getTempMinWeather(latitude, longitude) >= Integer.parseInt(tmp[6]))
                            reactionFuntion(object);
                    }
                }
            }
            if (tmp[2].equals("feels"))
            {
                if (tmp[6].equals("<=")) {
                    if (weatherService.getFeelsLikeWeather(latitude, longitude) <= Integer.parseInt(tmp[7]))
                        reactionFuntion(object);
                }
                if (tmp[6].equals(">=")) {
                    if (weatherService.getFeelsLikeWeather(latitude, longitude) >= Integer.parseInt(tmp[7]))
                        reactionFuntion(object);
                }
            }
            if (object.getAction().equals("The actual minute is a multiple of five"))
            {
                if (minutesMultipleOfFive.IsMinutesMultipleOfFive())
                    reactionFuntion(object);
            }
        }
    }

    public void reactionFuntion(Object object) {
        User user = repository.findById(object.getPerson());
        for (String reaction : object.getReaction()) {
            String[] tmp = reaction.split(" ");
            System.out.println(reaction);
            if (reaction.equals("Chuck Norris fact")) {
                System.out.println("Send a mail with a Chuck Norris fact (using Chuck Norris API)");
                mailSendService.sendMail(user.getEmail(), "Chuck Norris Fact", "Here's a cool fact about Chuck Norris:\n" + chuckNorrisJokeService.getRandomJoke());
            }
            if (tmp[0].equals("Create") && tmp[2].equals("branch")) {
                gitHubBranchService.createBranch(repoOwner, repoName, tmp[3], ref);
            }
            if (tmp[0].equals("Delete") && tmp[2].equals("branch")) {
                gitHubBranchService.deleteBranch(repoOwner, repoName, tmp[3], ref);
            }
            if (tmp[0].equals("Create") && tmp[2].equals("repo")) {
                gitHubBranchService.createGitHubRepository(tmp[3], "okokokok", ref);
            }
            if (tmp[0].equals("Delete") && tmp[2].equals("repo")) {
                gitHubBranchService.deleteGitHubRepository("-" + tmp[3] + "-", "areanice", ref);
            }
        }
        objectRepository.delete(object);
    }
}
