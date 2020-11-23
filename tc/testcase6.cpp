#include <iostream>

#include "../solutions/SocialNetwork.h"

int main() {
    SocialNetwork snetwork;

    snetwork.print();

    snetwork.addProfile("goktug", "ekinci", "goktug@ekinci.com");

    snetwork.print();

    snetwork.addProfile("ege", "b", "ege@b.com");

    snetwork.print();

    snetwork.addPost("Hello world! My name is goktug ekinci.", "goktug@ekinci.com");

    snetwork.addPost("Oldu mu?", "ege@b.com");

	snetwork.addPost("JOn ekinci", "goktug@ekinci.com");

	snetwork.addPost("Sıkıntı ne", "ege@b.com");

    snetwork.print();

    snetwork.addProfile("gurkan", "kanbur", "h@kanbur.com");

    snetwork.makeFriends("ege@b.com","h@kanbur.com");

    snetwork.makeFriends("ege@b.com","goktug@ekinci.com");

    snetwork.likePost(2,"goktug@ekinci.com");

    snetwork.likePost(1,"ege@b.com");

    snetwork.likePost(4,"goktug@ekinci.com");

    snetwork.likePost(4,"h@kanbur.com");
    snetwork.likePost(3,"h@kanbur.com");

    snetwork.likePost(3,"goktug@ekinci.com");

    snetwork.print();

    snetwork.unlikePost(3,"goktug@ekinci.com");

    snetwork.print();

    snetwork.addProfile("eren", "buyukbas", "erenbuyukbas@metu.com");

    snetwork.likePost(2,"erenbuyukbas@metu.com");

    snetwork.makeFriends("ege@b.com","erenbuyukbas@metu.com");

    snetwork.print();

    snetwork.makeFriends("erenbuyukbas@metu.com","goktug@ekinci.com");

    snetwork.makeFriends("erenbuyukbas@metu.com","h@kanbur.com");

    std::cout<<"İlk Ortak Arkadaş : " << snetwork.getMutualFriends("erenbuyukbas@metu.com","ege@b.com").getFirstNode()->data->getEmail()<<std::endl;;

    snetwork.print();

    snetwork.deleteProfile("goktug@ekinci.com");

    snetwork.print();

    return 0;
}
