//
// Created by Mj on 11/18/2016.
//

#include <iostream>

int main() {
    std::string str = "+1";
    // From here
    if(((str[0]-'0'<0)||(str[0]-'9'>0))&&(str[0]!='+')&&(str[0]!='-')&&(str[0]!=' '))
    {
        return 0;
    }
    int flag=1,index=0;
    double answer=0;
    while(str[index]==' ') {
        index++;
    }
    if(str[index]=='+')
    {
        flag=1;
        index++;
    }
    else if(str[index]=='-')
    {
        flag=-1;
        index++;
    }
    for(int i=index,s=str.length();i<s;i++)
    {
        if((str[i]>='0')&&(str[i]<='9'))
        {
            answer=(str[i]-'0')+answer*10;
        }
        else
        {
            break;
        }
    }
    answer=answer*flag;
    if(answer>2147483647)
    {
        std::cout << "2147483647";
        return 2147483647;
    }
    else if(answer<-2147483648)
    {
        std::cout << "-2147483648";
        return -2147483648;
    }
    else
    {
        std::cout << answer;
        return answer;
    }
    std::cout << answer;
}