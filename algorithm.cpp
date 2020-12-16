#include <iostream>
#include <string>
#include <stack>

std::string algorithm (char str_in[]){
    bool num_flag=0;
    std::string str, str_out;
    str=str_in;
    if (str[0]=='-') str.insert (str.begin(), '0');
    if (str[0]=='('){
        int count=0;
        for (; str[count]=='('; count++){}
        str[count-1]='0';
        str.insert (str.begin(), '(');
    }
    std::stack <char> stack_char_1;
    stack_char_1.push(0);
    for (int i=0; str[i]!=0; i++){
        switch(str[i]){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            if (num_flag==0) str_out.push_back(' ');
            str_out.push_back(str[i]);
            num_flag=1;
            break;

            case '(':
            stack_char_1.push('(');
            num_flag=0;
            break;
            
            case ')':
            char a;
            a=stack_char_1.top();
            stack_char_1.pop();
            while (a!='('){
                str_out.push_back(' ');
                str_out.push_back(a);
                a=stack_char_1.top();
                stack_char_1.pop();
            }
            num_flag=0;
            break;

            case '*':
            case '/':
            char b;
            b=stack_char_1.top();
            while ((b=='*') | (b=='/')) {str_out.push_back(' '); str_out.push_back(b); stack_char_1.pop(); b=stack_char_1.top();}
            stack_char_1.push(str[i]);
            num_flag=0;
            break;

            case '+':
            case '-':
            char c;
            c=stack_char_1.top();
            while ((c=='*') | (c=='/') | (c=='+') | (c=='-')) {str_out.push_back(' '); str_out.push_back(c); stack_char_1.pop(); c=stack_char_1.top();}
            stack_char_1.push(str[i]);
            num_flag=0;
            break;

            case ' ':
            break;

            default:
            return "Error, invalid symbol detected!";
        }
    }
    char buff;
    buff=stack_char_1.top();
    stack_char_1.pop();
    while(buff!=0){
        str_out.push_back(' ');
        str_out.push_back(buff);
        buff=stack_char_1.top();
        stack_char_1.pop();
    }
    return (str_out);
}