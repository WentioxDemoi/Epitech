package com.Area.Service;
import com.Area.entity.Object;
import com.Area.repository.ObjectRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;


@Service
public class ObjectService {
    @Autowired
    private ObjectRepository objectRepository;

    public Object checkActionAndTriggerReactions(Object object) {
        Object object2 = new Object();
        object2.setAction(object.getAction());
        object2.setReaction(object.getReaction());
        object2.setPerson(object.getPerson());
        objectRepository.save(object2);
        return (object2);
    }
}