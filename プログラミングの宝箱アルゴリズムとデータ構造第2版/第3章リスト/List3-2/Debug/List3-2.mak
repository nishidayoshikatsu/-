#-------------------------------------------------------
# BCC Developer 1.2.21
# Copyright (C) 2003 jun_miura@hi-ho.ne.jp
#-------------------------------------------------------
.autodepend
CC=bcc32
RC=brc32
CFLAG=-WC  -3 -Od -w- -AT -pc -H- -k -b -v -y  -DDEBUG
OUTDIR=-nDebug
CINCS=
TARGET=Debug\List3-2.exe
SRC1=C:\Users\吉克\Desktop\編入勉強プログラム\プログラミングの宝箱アルゴリズムとデータ構造第2版\第3章リスト\List3-2\List3-2.cpp
OBJ1=Debug\List3-2.obj

TARGET: $(TARGET)

$(TARGET): $(OBJ1)
    $(CC) $(CFLAG) -e$(TARGET) $(OBJ1)

$(OBJ1): $(SRC1)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC1)
