#include <iostream>
#include <fstream>

int ft_strlen(char *str){
    int     i = 0;

    while(str[i]){
        i++;
    }
    return (i);
}

std::string ft_replace(std::string src, std::string find, std::string update){
    std::string result;
    long unsigned int   i = 0;
    long unsigned int   j;

    while (i < src.length()){
        j = 0;
        while (src[i + j] && src[i + j] == find[j]){
            j++;
        }
        if (j == (find.length())){
            result = result + update;
            i += j;
        } else {
            result = result + src[i];
            i++;
        }
    }
    return (result);
}

int main(int argc, char *argv[]){

    std::ifstream   infile;
    std::ofstream   outfile;
    std::string     line;

    if (argc != 4){
        std::cout << "./ex04 <filename> <query word> <replace word>\n";
        return (1);
    }

    if (ft_strlen(argv[1]) == 0){
        std::cout << "filename cannot be empty\n";
        return (1);
    }
    std::string inname(argv[1]);
    inname = inname + ".replace";
    char *outname = &inname[0];

    if (ft_strlen(argv[2]) == 0){
        std::cout << "query word cannot be empty\n";
        return (1);
    }

    infile.open(argv[1]);
    if (!infile){
        std::cout << "Cannot open filename\n";
        return (2);
    }
    
    outfile.open(outname, std::ios::trunc);
    while(std::getline(infile, line)){
        outfile << ft_replace(line, argv[2], argv[3]) << std::endl;
    }

    infile.close();
    outfile.close();
    return (0);
}