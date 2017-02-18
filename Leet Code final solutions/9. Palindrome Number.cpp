//
// Created by Mj on 12/1/2016.
//

int main() {
    int x = 121;
    if (x < 0)
        return false;   // means it is not palindrome
    int div = 1;
    while (x / div >= 10) {
        div *= 10;
    }
    while (x != 0) {
        int l = x / div;
        int r = x % 10;
        if (l != r)
            return false;       // means it is not a palindrome.
        x = (x % div) / 10;
        div /= 100;
    }
    return true;        // It is a palindrome.
}