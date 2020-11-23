#include <iostream>

#include "../solutions/SocialNetwork.h"

int main() {
    SocialNetwork snetwork;

    snetwork.print();

    snetwork.addProfile("john", "doe", "john@doe.com");

    snetwork.print();

    snetwork.addPost("Hello world! My name is John Doe.", "john@doe.com");

    snetwork.print();

    return 0;
}
