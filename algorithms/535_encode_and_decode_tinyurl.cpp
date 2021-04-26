/*
  Leetcode.com
  Problem No : 535
  Problem : Encode and Decode TinyURL
  Author : cpp.rakesh@gmail.com
  Date: 26/04/2021
*/

#include <bits/stdc++.h>

const int SIZE = 6;
const std::string TINY_URL = "http://tinyurl.com/";

class Solution {
public:

    // Encodes a URL to a shortened URL.
    std::string encode(std::string longUrl) {
        std::string url, code;
        if (url2code.find(longUrl) == url2code.end()) {
            std::string code = generate_code();
            while (code2url.find(code) != code2url.end())
                code = generate_code();
            url2code[longUrl] = code;
            code2url[code] = longUrl;
            url = TINY_URL + code;
        } else
            url = url2code[longUrl];
        return url;
    }

    // Decodes a shortened URL to its original URL.
    std::string decode(std::string shortUrl) {
        std::string url;
        if (shortUrl.size() == TINY_URL.size() + SIZE) {
            const std::string code = shortUrl.substr(shortUrl.size() - SIZE, SIZE);
            if (code2url.find(code) != code2url.end())
                url = code2url[code];
        }
        return url;
    }

private:
    const std::string set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::unordered_map<std::string, std::string> url2code, code2url;

    std::string generate_code() {
        std::string code;
        for (int i = 0; i < SIZE; ++i)
            code += set[random() % set.size()];
        return code;
    }

    int random() {
        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0,1e+9);
        return dist(eng);
    }
};

void test() {
    const std::vector<std::string> urls = {
        "https://hello_from/rakesh_kumar/from_india/born_to_learn/hello",
        "https://kabhi_kabhi/mere_dil/mai_khyal/aata_hai",
        "https://saawan_ka/mahina_pawan/kare_shor/jiyra_re_jhome",
        "https://kabhi_bekashi/ne_maara/kabhi_bebasi_ne/maaaara",
        "https://mere_mehboob/qyamat_hogi/aaj_ruswa/teri_galio_mai"};
    Solution s;
    for (auto& url : urls)
        assert(url == s.decode(s.encode(url)));
}

int main() {
    test();

    return 0;
}
