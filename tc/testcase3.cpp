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

    snetwork.addProfile("demiralp","gokcan", "gokcan.demiralp@metu.edu.tr");

    snetwork.addProfile("varli","yigit", "yigit.varli@metu.edu.tr");

    snetwork.addProfile("varli","yigithan", "yıgıthan@kahve.metu.edu.tr");//gökcan demiralpin fikri "<" operatörünü test ediyor

    snetwork.addProfile("ekinci","goktug", "goktug.ekinci@metu.edu.tr");

    snetwork.addProfile("BOLUMU","EE", "EE_BOLUMU_MAILI@EEEEEEEEEEEEEEE.COM");

    snetwork.addProfile("ucoluk", "gokturk", "gokturk.ucoluk@metu.edu.tr");
    
    snetwork.addProfile("arpali", "onur yigit","onuryigitarpalininmaili");
    
    snetwork.print();

    std::cout << '\n';

    snetwork.getMutualFriends("goktug.ekinci@metu.edu.tr", "gokcan.demiralp@metu.edu.tr").print(); //ortak arkadaşları yok ama istiyoruz

    snetwork.getListOfMostRecentPosts("gokcan.demiralp@metu.edu.tr", 1).print();// postu yok ama istiyoruz

    snetwork.addPost("all we can do is office hours","EE_BOLUMU_MAILI@EEEEEEEEEEEEEEE.COM");

    snetwork.addPost("I AGREE WITH ONLY DISCUSSION PART OF THE FEEDBACK!","onuryigitarpalininmaili");

    snetwork.addPost("cengden yigit varli hocam musaitseniz bi ara kahve icebilir miyiz","gokcan.demiralp@metu.edu.tr");

    snetwork.addPost("reload yapmam, shifte basmam","gokcan.demiralp@metu.edu.tr");

    snetwork.addPost("kac farkli okuma sekli biliyorsunuz da scanf disinda okuyacaksiniz","gokturk.ucoluk@metu.edu.tr");//söke fikri

    snetwork.addPost("6 da yattım 6:15 te kalktım","yigit.varli@metu.edu.tr");

    snetwork.print();

    std::cout << '\n';

    std::cout << snetwork.getListOfMostRecentPosts("gokcan.demiralp@metu.edu.tr", 3).getNumberOfNodes() << '\n'; //1 tane postu var ama 3 istiyoruz çünkü neden olmasın

    snetwork.likePost(5, "yigit.varli@metu.edu.tr");//kendine like attı
    
    snetwork.likePost(3, "yigit.varli@metu.edu.tr");

    snetwork.unlikePost(3, "goktug.ekinci@metu.edu.tr");

    snetwork.print();

    return 0;
}
