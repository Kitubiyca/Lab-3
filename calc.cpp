#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cmath>

int calc (char str_in[]){
    std::string str;
    str=str_in;
    std::stack <char> stack_char_1;
    std::string num_buff_str;
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
            stack_char_1.push(str[i]);
            //std::cout << "num " << str[i] << std::endl;
            break;

            case ' ':
            stack_char_1.push(' ');
            //std::cout << "spacebar" << std::endl;
            break;

            case '+':
            case '-':
            case '*':
            case '/':
            stack_char_1.pop();
            char num_buff;
            num_buff=stack_char_1.top();
            int grade, num_1, num_2, res;
            grade=0; num_1=0; num_2=0;
            while((num_buff!=' ') & (num_buff!='-')){
                stack_char_1.pop();
                num_2+=(num_buff-'0')*pow(10, grade);
                grade++;
                num_buff=stack_char_1.top();
            }
            if (num_buff=='-'){ num_2*=-1; stack_char_1.pop(); num_buff=stack_char_1.top();}
            grade=0;
            stack_char_1.pop();
            num_buff=stack_char_1.top();
            while((num_buff!=' ') & (num_buff!='-')){
                stack_char_1.pop();
                num_1+=(num_buff-'0')*pow(10, grade);
                grade++;
                num_buff=stack_char_1.top();
            }
            if (num_buff=='-'){ num_1*=-1; stack_char_1.pop(); num_buff=stack_char_1.top();}
            char num_buff_ch[20];
                if (str[i]=='+') res=num_1+num_2;
                if (str[i]=='-') res=num_1-num_2;
                if (str[i]=='*') res=num_1*num_2;
                if (str[i]=='/'){ if (num_2) res=num_1/num_2; else throw "Error! Zero divider revealed!";}
            //std::cout << num_1 << " " << str[i] << " " << num_2 << " = " << res << std::endl;
            if (res<0){ res*=-1; stack_char_1.push('-');}
            itoa(res, num_buff_ch, 10);
            num_buff_str=num_buff_ch;
            for(int num_i=0; num_buff_str[num_i]!=0; num_i++) stack_char_1.push(num_buff_str[num_i]);
            break;

            default:
            throw "Unexpected error";

        }
    }
    char buff=stack_char_1.top();
    int out_num=0, grade_out=0;
    while ((buff!=' ') & (buff!='-')){
        //std::cout << "writing " << buff << std::endl;
        //std::cout << "out_num stage " << out_num << std::endl;
        stack_char_1.pop();
        out_num+=(buff-'0')*pow(10, grade_out);
        grade_out++;
        buff=stack_char_1.top();
    }
    if (buff=='-') out_num*=-1;
    return out_num;
}