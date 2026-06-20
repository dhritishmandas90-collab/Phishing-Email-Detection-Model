#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 5000

void toLowerCase(char str[]) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int containsKeyword(char text[], char keyword[]) {
    return strstr(text, keyword) != NULL;
}

int main() {

    char email[MAX_TEXT];

    char *phishingKeywords[] = {
        "verify account",
        "urgent",
        "click here",
        "login now",
        "bank",
        "password",
        "update account",
        "free money",
        "winner",
        "congratulations",
        "limited time",
        "credit card",
        "security alert"
    };

    int keywordCount = sizeof(phishingKeywords) / sizeof(phishingKeywords[0]);

    printf("===================================\n");
    printf(" PHISHING EMAIL DETECTION SYSTEM\n");
    printf("===================================\n\n");

    printf("Paste Email Content:\n\n");

    fgets(email, MAX_TEXT, stdin);

    toLowerCase(email);

    int score = 0;

    for(int i = 0; i < keywordCount; i++) {
        if(containsKeyword(email, phishingKeywords[i])) {
            score += 10;
        }
    }

    if(strstr(email, "http://") || strstr(email, "https://")) {
        score += 20;
    }

    if(strstr(email, ".ru") || strstr(email, ".xyz")) {
        score += 15;
    }

    printf("\n----- Analysis Report -----\n");

    printf("Risk Score: %d\n", score);

    if(score >= 40) {
        printf("Classification: PHISHING EMAIL\n");
    }
    else if(score >= 20) {
        printf("Classification: SUSPICIOUS EMAIL\n");
    }
    else {
        printf("Classification: SAFE EMAIL\n");
    }

    FILE *report = fopen("phishing_report.txt", "w");

    if(report != NULL) {
        fprintf(report, "Phishing Email Detection Report\n");
        fprintf(report, "Risk Score: %d\n", score);

        if(score >= 40)
            fprintf(report, "Classification: PHISHING EMAIL\n");
        else if(score >= 20)
            fprintf(report, "Classification: SUSPICIOUS EMAIL\n");
        else
            fprintf(report, "Classification: SAFE EMAIL\n");

        fclose(report);
    }

    printf("\nReport saved as phishing_report.txt\n");

    return 0;
}
