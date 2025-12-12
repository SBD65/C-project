#ifndef PROJE1_H
#define PROJE1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
    char* ad;           // Kitap adi (dinamik bellek)
    char* yazar;        // Yazar adi (dinamik bellek)
    unsigned short kod; // Hangi kategoriye ait oldugu
    float fiyat;        // Kitabin fiyati
    int yil;            // Basim yili
} Kitap;

typedef struct {
    char* ad;               // Kategori adi
    unsigned short kod;     // Kategori kodu
    Kitap* kategoriKitaplar;// Kategorideki kitaplar dizisi
    int kitapSayisi;        // Dizideki anlik mevcut kitap
    int kapasite;           // Dizinin o anki max kapasitesi
} Kategori;



// Olusturma Fonksiyonlari
Kategori kategoriOlustur(char* ad, unsigned short kod);
Kitap kitapOlustur(char* ad, char* yazar, unsigned short kod, float fiyat, int yil);

// Ekleme Islemleri
void KitapEkle(Kategori *kategoriDizi, int *kategoriSayisi, Kitap yeniKitap);

// Yazdirma Islemleri
void KitapBilgileriniYazdir(Kitap *kitap);
void KategoriBilgileriniYazdir(Kategori *kategori);
void TumKategorileriYazdir(Kategori *kategoriDizi, int kategoriSayisi);

// Hesaplama ve Listeleme Islemleri
int FiyatOrtalamasiHesapla(Kategori *kategori);
void OrtalamaUstuKitaplariListele(Kategori *kategori);
void EnPahaliKitaplariYazdir(Kategori *kategoriDizi, int kategoriSayisi);

// Guncelleme Islemleri
void EskiKitapFiyatGuncelle(Kategori *kategoriDizi, int kategoriSayisi, int yil, float yeniFiyat);

// Dosya Islemleri
void DiziyDosyayaYaz(Kategori *kategoriDizi, int kategoriSayisi);
void DosyadanDiziyeAktar(Kategori **kategoriDiziPtr, int *kategoriSayisiPtr);

#endif // !PROJE1_H
