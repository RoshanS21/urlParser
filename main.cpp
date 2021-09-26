#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

int main(int argc, char* argv[])
{
    std::string x,y;
    std::string input1 = "https://www.geeksforgeeks.org/fundamentals-of-algorithms/?ref=shm";
    std::string input2 = "https://cs.utdallas.adu:80/people.html?name=Robert";
    std::string input3 = "https://cs.utdallas.edu:80/directory/faculty/people.html?name=Robert";
    std::string input4 = "httpss://cs.utdallas.edu:80/directory/faculty/people.html?name=Robert";
    
    std::string url = input3;
    std:: cout << "URL: " << url << std::endl;

    // URL comoponents
    std::vector<std::string> protocols = {"http", "https", "ftp", "ftps"};
    // Domain: <x>.<y>.<z>
    std::vector<std::string> hosts = {"com", "net", "edu", "biz", "gov"};

    size_t pos = url.find("://");
    std::string protocol = url.substr(0, pos);
    if ( pos != std::string::npos && !(std::find(protocols.begin(), protocols.end(), protocol) != protocols.end()) )
    {
        std::cout << "Error:" << std::endl;
        std::cout << "\t" << protocol << " is not a valid protocol." << std::endl;
        std::cout << "Exiting!" << std::endl;
        exit(0);
    }
    url.erase(0, pos + 3);

    // Let's parse the rest using regex.
    std::regex urlRegex("^(.+)?[.](.+)?[.](.+)?:([0-9]*)?/(.*)$");
    std::smatch smatch;
    if (std::regex_match(url, smatch, urlRegex, std::regex_constants::match_default))
    {
        // for (size_t i = 0; i < smatch.size(); i++)
        // {
        //     std::ssub_match sub_match = smatch[i];
        //     std::string match = sub_match.str();
        //     std::cout << "match " << i << ": " << match << std::endl;
        // }
        // print
        std::cout << "protocol: " << protocol << std::endl;
        std::cout << "x: " << smatch[1] << std::endl;
        std::cout << "y: " << smatch[2] << std::endl;
        std::cout << "z/Domain: " << smatch[3] << std::endl;
        std::cout << "port: " << smatch[4] << std::endl;
        std::cout << "Remainder: " << smatch[5] << std::endl;
        std::cout << std::endl; 
    }
    return 0;
}