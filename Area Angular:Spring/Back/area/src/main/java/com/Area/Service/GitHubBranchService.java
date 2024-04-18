package com.Area.Service;
import org.springframework.http.HttpEntity;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpMethod;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.util.LinkedMultiValueMap;
import org.springframework.util.MultiValueMap;
import org.springframework.web.client.HttpClientErrorException;
import org.springframework.web.client.RestTemplate;
import com.fasterxml.jackson.annotation.JsonProperty;


@Service
public class GitHubBranchService {
    @Autowired
    private RestTemplate restTemplate;
    private static final String GITHUB_API_BASE_URL = "https://api.github.com";
    private static final String CREATE_BRANCH_ENDPOINT = "/repos/areanice/okokokok/git/refs";

    
    public static class GitHubRepository {
        @JsonProperty("name")
        private String name;
        @JsonProperty("description")
        private String description;
    
        public GitHubRepository() {}
    
        public GitHubRepository(String name, String description) {
            this.name = name;
            this.description = description;
        }
    
        // getters and setters
    }

    public String createBranch(String owner, String repo, String branchName, String accessToken) {
        HttpHeaders headers = new HttpHeaders();
        headers.setBearerAuth(accessToken);
        headers.setContentType(MediaType.APPLICATION_JSON);
        String requestJson = "{\"ref\":\"refs/heads/" + branchName + "\",\"sha\":\"" + "d656fb5fa8992270a15ba5e97068b6bb5113fa8d" + "\"}";
        HttpEntity<String> request = new HttpEntity<>(requestJson, headers);

        ResponseEntity<String> response = restTemplate.postForEntity(GITHUB_API_BASE_URL + CREATE_BRANCH_ENDPOINT, request, String.class, owner, "d656fb5fa8992270a15ba5e97068b6bb5113fa8d");
        if (response.getStatusCode().is2xxSuccessful()) {
            System.out.println("Branch created successfully");
        } else {
            System.out.println("Failed to create branch: " + response.getBody());
        } return "héhééééé sheeeeeeeeeesh";
    }

    public String deleteBranch(String owner, String repo, String branchName, String accessToken) {
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_JSON);
        headers.set("Authorization", "Bearer " + accessToken);
        HttpEntity<String> entity = new HttpEntity<>(headers);
        String url = "https://api.github.com/repos/" + owner + "/" + repo + "/git/refs/heads/" + branchName;
    
        try {
            restTemplate.exchange(url, HttpMethod.DELETE, entity, String.class);
        } catch (HttpClientErrorException e) {
            System.out.println("Ehhhhhh 500/404 mais ça a peut être marché ! (Delete)");
        }
        
        return "héhééééé sheeeeeeeeeesh";
    }

    public void createGitHubRepository(String name, String description, String accessToken) {
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_JSON);
        headers.set("Authorization", "Bearer " + accessToken);

        MultiValueMap<String, Object> body = new LinkedMultiValueMap<>();
        body.add("name", name);
        body.add("description", description);

        System.out.println(body);

        HttpEntity<MultiValueMap<String, Object>> entity = new HttpEntity<>(body, headers);

        RestTemplate restTemplate = new RestTemplate();

        ResponseEntity<GitHubRepository> response = restTemplate.exchange(
                "https://api.github.com/user/repos",
                HttpMethod.POST,
                entity,
                GitHubRepository.class
        );

        if (response.getStatusCode().is2xxSuccessful()) {
            System.out.println("Repository created successfully: " + response.getBody().name);
        } else {
            System.out.println("Error creating repository: " + response.getStatusCode());
        }
    }

    public void deleteGitHubRepository(String name, String owner, String accessToken) {
        RestTemplate restTemplate = new RestTemplate();
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_JSON);
        headers.set("Authorization", "Bearer " + accessToken);
        HttpEntity<String> entity = new HttpEntity<>(headers);
        System.out.println("Name : " + name + "    " + "owner : " + owner);

        String url = "https://api.github.com/repos/" + owner + "/" + name;
        ResponseEntity<String> response = restTemplate.exchange(url, HttpMethod.DELETE, entity, String.class);

        if (response.getStatusCodeValue() == 204) {
            System.out.println("Repository deleted successfully");
        } else {
            System.out.println("Failed to delete repository");
        }
    }


}