// RUN: %clang -S %s -o - | FileCheck %s -check-prefix=ALLOWED
// RUN: not %clang -std=c89 -S %s -o - 2>&1 | FileCheck %s -check-prefix=DENIED
int \uaccess = 0;
// ALLOWED: "{{_?}}곎ss":
// ALLOWED-NOT: "\uaccess":
// DENIED: warning: universal character names are only valid in C99 or C++; treating as '\' followed by identifier [-Wunicode]
// DENIED: error: expected identifier or '('
