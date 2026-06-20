# Phishing Email Detection Model (C)

## Overview
This project is a simple phishing email detector written in C.

It analyzes email text for:
- Suspicious keywords
- URLs
- Risk indicators

The program calculates a risk score and classifies emails as:
- Safe
- Suspicious
- Phishing

## Features
- Keyword-based phishing detection
- URL detection
- Risk score calculation
- Email classification
- Report generation

## Compilation

### Linux
```bash
gcc phishing_detector.c -o detector
./detector
```

### Windows
```bash
gcc phishing_detector.c -o detector.exe
detector.exe
```

## Sample Input
URGENT!

Your bank account has been suspended.

Click here:
https://fake-bank.xyz/login

Verify your password immediately.

## Output
Risk Score: 65

Classification: PHISHING EMAIL

## Disclaimer
For educational purposes only.
