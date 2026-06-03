#include <stdio.h>

int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num % 2;
        num /= 2;
    }
    return count;
}

void findMinMaxNumbers(int query, int m) {
    int minDiff = 32, maxDiff = -1;
    int minNumber, maxNumber;

    // অ্যারে ছাড়াই ক্যান্ডিডেট সংখ্যা প্রস্তুত করা
    int candidate;
    int countQuery = countSetBits(query);

    // মিনিমাম এবং ম্যাক্সিমাম পার্থক্যের জন্য উম্মুক্ষ ভেরিয়েবল ইনিসিয়েট করুন
    minNumber = maxNumber = 0; // ডিফল্ট মান

    for (int i = 0; i < m; i++) {
        scanf("%d", &candidate);

        // ক্যান্ডিডেট সংখ্যার বাইনারি প্রতিস্থানের প্রিন্ট
        for (int j = 31; j >= 0; j--) {
            printf("%d", (candidate >> j) & 1);
        }
        printf("\n");

        // মিনিমাম এবং ম্যাক্সিমাম পার্থক্য আপডেট করুন
        int countCandidate = countSetBits(candidate);
        int diff = countQuery - countCandidate;

        if (diff >= 0 && diff < minDiff) {
            minDiff = diff;
            minNumber = candidate;
        }

        if (diff >= maxDiff) {
            maxDiff = diff;
            maxNumber = candidate;
        }
    }

    // কুয়েরি সংখ্যার বাইনারি প্রতিস্থানের প্রিন্ট
    for (int j = 31; j >= 0; j--) {
        printf("%d", (query >> j) & 1);
    }
    printf("\n");

    // প্রয়োজনীয় সংখ্যা প্রিন্ট
    printf("সর্বনিম্ন পার্থক্যযুক্ত সংখ্যা: %d\n", minNumber);
    printf("সর্বাধিক পার্থক্যযুক্ত সংখ্যা: %d\n", maxNumber);
}

int main() {
    int t;
    scanf("%d", &t);

    for (int caseNum = 1; caseNum <= t; caseNum++) {
        int query, m;
        scanf("%d %d", &query, &m);

        printf("কেস %d\n", caseNum);

        findMinMaxNumbers(query, m);
    }

    return 0;
}