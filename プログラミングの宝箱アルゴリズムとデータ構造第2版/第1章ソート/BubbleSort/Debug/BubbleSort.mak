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
TARGET=Debug\BubbleSort.exe
SRC1=C:\Users\�g��\Desktop\�ғ��׋��v���O����\�v���O���~���O�̕󔠃A���S���Y���ƃf�[�^�\����2��\��1�̓\�[�g\BubbleSort\BubbleSort.cpp
OBJ1=Debug\BubbleSort.obj

TARGET: $(TARGET)

$(TARGET): $(OBJ1)
    $(CC) $(CFLAG) -e$(TARGET) $(OBJ1)

$(OBJ1): $(SRC1)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC1)
