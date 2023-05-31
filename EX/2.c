//請為編譯器範例加上 do BLOCK while EXP 語法
//參考了ChatGPT

#include <assert.h>
#include "compiler.h"

int E();
void STMT();
void IF();
void BLOCK();
void DO_WHILE(); // 新增的函式

int tempIdx = 0, labelIdx = 0;

#define nextTemp() (tempIdx++)
#define nextLabel() (labelIdx++)

int isTempIr = 0;
char tempIr[100000], *tempIrp = tempIr;

#define emit(...) ({ \
  if (isTempIr) { \
    sprintf(tempIrp, __VA_ARGS__); \
    tempIrp += strlen(tempIrp); \
  } else { \
    printf(__VA_ARGS__); \
  } \
})

int isNext(char *set) {
  char eset[SMAX], etoken[SMAX];
  sprintf(eset, " %s ", set);
  sprintf(etoken, " %s ", tokens[tokenIdx]);
  return (tokenIdx < tokenTop && strstr(eset, etoken) != NULL);
}

int isEnd() {
  return tokenIdx >= tokenTop;
}

char *next() {
  return tokens[tokenIdx++];
}

char *skip(char *set) {
  if (isNext(set)) {
    return next();
  } else {
    printf("skip(%s) got %s fail!\n", set, next());
    assert(0);
  }
}

int F() {
  int f;
  if (isNext("(")) {
    next();
    f = E();
    next();
  } else {
    f = nextTemp();
    char *item = next();
    if (isdigit(*item)) {
      emit("t%d = %s\n", f, item);
    } else {
      if (isNext("++")) {
        next();
        emit("%s = %s + 1\n", item, item);
      }
      emit("t%d = %s\n", f, item);
    }
  }
  return f;
}

int E() {
  int i1 = F();
  while (isNext("+ - * / & | ! < > = <= >= == !=")) {
    char *op = next();
    int i2 = E();
    int i = nextTemp();
    emit("t%d = t%d %s t%d\n", i, i1, op, i2);
    i1 = i;
  }
  return i1;
}

void ASSIGN() {
  char *id = next();
  skip("=");
  int e = E();
  skip(";");
  emit("%s = t%d\n", id, e);
}

void WHILE() {
  int whileBegin = nextLabel();
  int whileEnd = nextLabel();
  emit("(L%d)\n", whileBegin);
  skip("while");
  skip("(");
  int e = E();
  emit("if not T%d goto L%d\n", e, whileEnd);
  skip(")");
  STMT();
  emit("goto L%d\n", whileBegin);
  emit("(L%d)\n", whileEnd);
}

void IF() {
  skip("if");
  skip("(");
  E();
  skip(")");
  STMT();
  if (isNext("else")) {
    skip("else");
    STMT();
  }
}

void STMT() {
  if (isNext("while"))
    return WHILE();
  else if (isNext("if"))
    IF();
  else if (isNext("{"))
    BLOCK();
  else if (isNext("do"))
    DO_WHILE();
  else
    ASSIGN();
}

void STMTS() {
  while (!isEnd() && !isNext("}")) {
    STMT();
  }
}

void BLOCK() {
  skip("{");
  STMTS();
  skip("}");
}

void PROG() {
  STMTS();
}

// 新增的函式
void DO_WHILE() {
  skip("do");
  int doBegin = nextLabel();
  int doEnd = nextLabel();
  emit("(L%d)\n", doBegin);
  BLOCK();
  skip("while");
  skip("(");
  int e = E();
  skip(")");
  emit("if T%d goto L%d\n", e, doBegin);
  emit("(L%d)\n", doEnd);
  skip(";");
}

void parse() {
  printf("============ parse =============\n");
  tokenIdx = 0;
  PROG();
}
