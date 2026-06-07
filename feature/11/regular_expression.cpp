#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::string fnames[] = {"foo.txt", "bar.txt",
                            "test", "a0.txt", "AAA.txt"};
    std::regex txt_regex("[a-z]+\\.txt");
    for (const auto &fname : fnames)
        std::cout << fname << ": " << std::regex_match(fname, txt_regex) << std::endl;

    try {
        std::regex base_regex("([a-z]+)\\.txt");
        std::smatch base_match;
        for (const auto &fname : fnames)
        {
            if (std::regex_match(fname, base_match, base_regex))
            {
                std::cout << fname << " match: 1 size: " << base_match.size() << '\n';
                if (base_match.size() == 2)
                {
                    std::string base = base_match[1].str();
                    std::cout << "sub-match[0]: " << base_match[0].str() << '\n'
                              << fname << " sub-match[1]: " << base << '\n';
                }
            }
        }
    } catch (const std::regex_error& e) {
        std::cerr << "regex_error caught: " << e.what() << '\n';
        return 1;
    }
    return 0;
}