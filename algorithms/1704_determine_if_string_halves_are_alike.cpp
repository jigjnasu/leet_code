/*
  Leetcode.com
  Problem No : 1704
  Problem : Determine if String Halves Are Alike
  Author : cpp.rakesh@gmail.com
  Date: 26/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    bool halvesAreAlike(std::string s) {
        std::size_t i = 0;
        std::size_t j = s.size() >> 1;
        int total = 0;
        for (; i < s.size() >> 1; ++i, j++) {
            if (vowel(s[i])) ++total;
            if (vowel(s[j])) --total;
        }
        return total == 0;
    }

private:
    bool vowel(char c) {
        return c == 'a' || c == 'e' ||
            c == 'i' || c == 'o' ||
            c == 'u' || c == 'A' ||
            c == 'E' || c == 'I' ||
            c == 'O' || c == 'U';
    }
};

int main() {
    Solution s;
    printf("%d\n", s.halvesAreAlike("book"));
    printf("%d\n", s.halvesAreAlike("textbook"));
    printf("%d\n", s.halvesAreAlike("MerryChristmas"));
    printf("%d\n", s.halvesAreAlike("AbCdEfGh"));
    printf("%d\n", s.halvesAreAlike("gfLpdQfBhLSNWKBvRWpNlRWTSMQYTSyPFTwWHptvnJHFWQDQLdYyHzKJjYrpHbNQyPFWpKhChZXsvYfPBVMpRSfLZwHMBqsbPhZBhwfmjDqgXVkZrtyXbpXWVLRnpGPWjvKNHmxqxPSlvxxsxsnbQvKJDwKtWgFDrjsgvTScXYPsMBgkWktkdthwsQdCpddrgksxlZMYDcPyvMLqztnYGQbrKcKPWqtjdklXZBvNbZfNdNRmbDGpxybGdzghpSmGvmZGpJlfwTbLhQXZSfgSJTNvrQGdWyQgJjngKLXNpkMtFWgpcrYHZHJdgDfmkfplDYjWRmBNyFNzgGbRcGBQXWcskPpXPlBkdsVwRMNZCLvkdXwDrlcTTNPPMvjPChWHQPJMPSLSzQLlkQWrmLLnknVdWKrYZRymTQTRDbsgtFjZQjMNdrZVqQdBdywVqSWkkHHmbrwnlzXwYCpbfJSxBPdwDjKQFgYPChQWdJTHRVYRDrLtswMnTNQCjZNsqZBpXjZxWKblqZFxtZgHCjYsbqJZFjQJZlFptgMXVDykQpHlmPzxpKnQNtYDJNhHZkMLVCXJjgRGYwCbNGmkqgRkYjzpBMJHRLkbsgXpMkMWCDncmGXBxzZsSrGshcYKClqTyZPcGBJthqXjVlJWNYtPgXkFQSxXxGwsvbgPQQZQfllFfQbXMCkqXtTxDlSkgBGfVSSfWCwbzgFnLlMKLQgccrQSyxRyqyXvCzCBGdzPhxLnvJMyDhpWXWNFXwcwHCCMsccvrxbtsjcThqsLMrgkxlLLGKCbtdHqvBKjxlmntDrvCKxwpMrWZycsvDjCRjPXQPZxmvHnxGWpBqkJCkcqfmyRHPSgGxxkHgSLXNsfVxQRwbftyCxvzHrCzXKXfghSwTMpDzBhmjXLdxFCfpSggVkTVFPQTJCrCwfyVLNQGSLJKVRKtHCwHMNyclLNHHZTzbLJdtkQRzrPVgXSLhJKVZlqYVzPsmwZYPmqKhQC"));

    return 0;
}
