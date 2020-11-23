#include <iostream>

#include "../solutions/SocialNetwork.h"

int main() {
    SocialNetwork snetwork;

    snetwork.print();

    std::cout << '\n';

    snetwork.addProfile("keles", "alperen", "alperen.keles@metu.edu.tr");

    snetwork.deleteProfile("alperen.keles@metu.edu.tr");

    snetwork.print();

    std::cout << '\n';

    snetwork.addProfile("keles", "alperen", "alperen.keles@metu.edu.tr");

    snetwork.addProfile("demiralp","gokcan", "gokcan.demiralp@metu.edu.tr");

    snetwork.addProfile("varli","yigit", "yigit.varli@metu.edu.tr");

    snetwork.addProfile("ekinci","goktug", "goktug.ekinci@metu.edu.tr");
    
    snetwork.print();

    std::cout << '\n';

    snetwork.makeFriends("goktug.ekinci@metu.edu.tr", "yigit.varli@metu.edu.tr");

    snetwork.makeFriends("goktug.ekinci@metu.edu.tr", "gokcan.demiralp@metu.edu.tr");

    snetwork.makeFriends("goktug.ekinci@metu.edu.tr", "alperen.keles@metu.edu.tr");

    snetwork.makeFriends("alperen.keles@metu.edu.tr", "yigit.varli@metu.edu.tr");

    snetwork.makeFriends("alperen.keles@metu.edu.tr",  "gokcan.demiralp@metu.edu.tr");

    std::cout << snetwork.getMutualFriends("alperen.keles@metu.edu.tr", "goktug.ekinci@metu.edu.tr" ).getNumberOfNodes() << '\n';

    snetwork.print();

    return 0;
}
