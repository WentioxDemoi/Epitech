package com.Area.entity;
import javax.persistence.*;
import java.util.List;


@Entity
@Table(name = "objects")
public class Object {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id")
    private Long id;

    @Column(name = "person")
    private Long person;

    @Column(name = "action")
    private String action;

    @ElementCollection(fetch = FetchType.EAGER)
    @CollectionTable(name = "objects_reaction", joinColumns = @JoinColumn(name = "objects_id"))
    @Column(name = "reaction")
    private List<String> reaction;

    // Getters and setters
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getAction() {
        return action;
    }

    public void setAction(String action) {
        this.action = action;
    }

    public List<String> getReaction() {
        return reaction;
    }

    public void setReaction(List<String> reaction) {
        this.reaction = reaction;
    }

    public Long getPerson() {
        return person;
    }

    public void setPerson(Long person) {
        this.person = person;
    }
}