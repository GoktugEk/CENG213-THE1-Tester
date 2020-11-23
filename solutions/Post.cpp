#include "Post.h"

Post::Post() {

}

Post::Post(const std::string &message) {
    static int postId = 1;

    this->message = message;
    this->postId = postId;

    postId += 1;
}

const std::string &Post::getMessage() const {
    return this->message;
}

int Post::getPostId() const {
    return this->postId;
}

void Post::setMessage(const std::string &message) {
    this->message = message;
}

void Post::setPostId(int postId) {
    this->postId = postId;
}

std::ostream &operator<<(std::ostream &os, const Post &post) {
    os << "message: " << post.message;
    os << " postId: " << post.postId;
    return os;
}

bool Post::operator==(const Post &rhs) const {
    if(rhs.postId == this->postId && rhs.message.length() == this->message.length()){
        for (int i = 0; i < rhs.message.length(); ++i) {
            if (rhs.message.at(i) != this->message.at(i)){
                return false;
            }
        }
        return true;
    }
    else return false;
}

bool Post::operator!=(const Post &rhs) const {
    return !(rhs == *this);
}

bool Post::operator<(const Post &rhs) const {
    return this->postId < rhs.postId;
}

bool Post::operator>(const Post &rhs) const {
    return rhs < *this;
}

bool Post::operator<=(const Post &rhs) const {
    return !(rhs < *this);
}

bool Post::operator>=(const Post &rhs) const {
    return !(*this < rhs);
}
