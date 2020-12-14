#include <iostream>
#include <string>
#include <cstring>

std::string algorithm(char str_in[]);
int calc (char str_in[]);

int main(){
char str[100];
int res;
std::string result;
std::cout << "Please enter a mathematical expression here: ";
std::cin.getline(str, 100);
result=algorithm(str);
std::cout << "The reverse Polish notation is:"<< result << std::endl;
strcpy(str, result.c_str());
try{
res=calc(str);
std::cout << "The result is " << res << std::endl;
}
catch(const char* warn){
    std::cout << warn << std::endl;
}
system("pause");
return 0;
}