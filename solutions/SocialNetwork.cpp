#include "SocialNetwork.h"

#include <iostream>

SocialNetwork::SocialNetwork() {

}

void SocialNetwork::addProfile(const std::string &firstname, const std::string &lastname, const std::string &email) {
    Profile newprof;

    newprof = Profile(firstname, lastname, email);
    this->profiles.insertSorted(newprof);

}

void SocialNetwork::addPost(const std::string &message, const std::string &email) {
    Post newpost;
    Node<Profile> *theProf;
    Node<Post> *thePost;


    newpost = Post(message);

    this->posts.insertAtTheTail(newpost);

    thePost = this->getPost(newpost.getPostId());
    theProf = this->getProfile(email);

    theProf->data.addPost(&thePost->data);

}

void SocialNetwork::deleteProfile(const std::string &email) {
    Node<Profile> *theProf;
    Node<Profile> *current;
    Node<Post*> *c2;
    
    theProf = this->getProfile(email);

    current = this->profiles.getFirstNode();
    
    
    while(current != NULL){
        if(current == theProf){ 
            current = current->next;
            continue;
        }
        
        current->data.dropFriend(&theProf->data);
        
        c2 = theProf->data.getPosts().getFirstNode();
        while(c2 != NULL){
        
            current->data.dropLike(c2->data);
        
            c2 = c2->next;
        }
        
        current = current->next;
    }
    
    c2 = theProf->data.getPosts().getFirstNode();
    
    while(c2 != NULL){
        
        this->posts.removeNode(*c2->data);
        
        c2 = c2->next;
    }
    

    this->profiles.removeNode(theProf);

}

void SocialNetwork::makeFriends(const std::string &email1, const std::string &email2) {
    Node<Profile> *person1, *person2;

    person1 = this->getProfile(email1);
    person2 = this->getProfile(email2);

    person1->data.addFriend(&person2->data);
    person2->data.addFriend(&person1->data);
}

void SocialNetwork::likePost(int postId, const std::string &email) {
    Node<Profile> *person;
    Node<Post> * thepost;

    thepost = this->getPost(postId);
    person = this->getProfile(email);

    person->data.addLike(&thepost->data);
}

void SocialNetwork::unlikePost(int postId, const std::string &email) {
    Node<Profile> *person;
    Node<Post> * thepost;

    thepost = this->getPost(postId);
    person = this->getProfile(email);

    person->data.dropLike(&thepost->data);
}

LinkedList<Profile *> SocialNetwork::getMutualFriends(const std::string &email1, const std::string &email2) {
    Node<Profile> *pers1, *pers2;
    Node<Profile*> *curr1,*curr2;
    LinkedList<Profile *> mutuals;
    std::string email;


    pers1 = this->getProfile(email1);
    pers2 = this->getProfile(email2);

    curr1 = pers1->data.getFriends().getFirstNode();


    for (; curr1 != NULL ; curr1 = curr1->next ) {
        curr2 = pers2->data.getFriends().getFirstNode();
        email = curr1->data->getEmail();
        for(;curr2 != NULL;curr2 = curr2->next){
            if (email == curr2->data->getEmail()){
                mutuals.insertAtTheTail(curr1->data);
            }         
        }

    }


    return mutuals;
}

LinkedList<Post *> SocialNetwork::getListOfMostRecentPosts(const std::string &email, int k) {
    Node<Profile> *pers1;
    Node<Post*> *curr;
    LinkedList<Post*> *thePosts;
    LinkedList<Post *> recents;



    pers1 = this->getProfile(email);
    thePosts = &pers1->data.getPosts();
    curr = thePosts->getFirstNode();


    for (int i = 0; i < k && curr != NULL ; ++i) {
        recents.insertAtTheHead(curr->data);
        curr = curr->next;
    }


    return recents;
}

void SocialNetwork::print() const {
    std::cout << "# Printing the social network ..." << std::endl;

    std::cout << "# Number of profiles is " << profiles.getNumberOfNodes() << ":" << std::endl;
    profiles.print();

    std::cout << "# Number of posts is " << posts.getNumberOfNodes() << ":" << std::endl;
    posts.print();

    std::cout << "# Printing is done." << std::endl;
}

Node<Profile>* SocialNetwork::getProfile(const std::string &email){
    Node<Profile>* current;

    current = this->profiles.getFirstNode();

    while (current != NULL){
        if (email == current->data.getEmail()) return current;
        current = current->next;
    }

    return NULL;
}

Node<Post>* SocialNetwork::getPost(const int postId){
    Node<Post>* current;

    current = this->posts.getFirstNode();

    while (current != NULL){
        if (postId == current->data.getPostId()) return current;
        current = current->next;
    }

    return NULL;
}