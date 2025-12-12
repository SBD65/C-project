# Derleyiciyi seçiyoruz (gcc)
CC = gcc

# Derleme bayrakları:
# -Wall: Tüm uyarıları aç (hataları görmek için çok önemli)
# -g: Hata ayıklama (debug) bilgilerini ekle (lldb veya gdb kullanırsan işine yarar)
CFLAGS = -Wall -g

# Hedef programın adı
TARGET = kutuphane_sistemi

# Varsayılan hedef: 'make' yazınca burası çalışır
all: $(TARGET)

# 1. Adım: Çalıştırılabilir dosyayı oluşturma (Linkleme)
$(TARGET): main.o Proje1.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o Proje1.o

# 2. Adım: main.o dosyasını oluşturma
# main.c veya Proje1.h değişirse burası tekrar çalışır
main.o: main.c Proje1.h
	$(CC) $(CFLAGS) -c main.c

# 3. Adım: Proje1.o dosyasını oluşturma
# Proje1.c veya Proje1.h değişirse burası tekrar çalışır
Proje1.o: Proje1.c Proje1.h
	$(CC) $(CFLAGS) -c Proje1.c

# Temizlik komutu: 'make clean' yazınca derlenmiş dosyaları siler
clean:
	rm -f *.o $(TARGET)
