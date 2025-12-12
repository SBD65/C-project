#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Proje1.h"

int main(int argc, const char * argv[]) {
    
    // --- 1. VERİ OLUŞTURMA (ALLOCATION) ---
    int kategoriSayisi = 1;
    Kategori *kategoriDizi = (Kategori*)malloc(kategoriSayisi * sizeof(Kategori));
    DosyadanDiziyeAktar(&kategoriDizi, &kategoriSayisi);
    Kitap k=kitapOlustur("xxx", "x", 101, 10, 2005);
    KitapEkle(kategoriDizi, &kategoriSayisi, k);
    printf("-main-%s\n",kategoriDizi[0].kategoriKitaplar[kategoriDizi[0].kitapSayisi-1].ad);//debug
    KitapBilgileriniYazdir(&k);
    KategoriBilgileriniYazdir(&kategoriDizi[0]);
    OrtalamaUstuKitaplariListele(kategoriDizi);
    
    EnPahaliKitaplariYazdir(kategoriDizi, kategoriSayisi);
    EskiKitapFiyatGuncelle(kategoriDizi, kategoriSayisi, 2000, 25);
    DiziyDosyayaYaz(kategoriDizi, kategoriSayisi);
    
    TumKategorileriYazdir(kategoriDizi, kategoriSayisi);
    free(kategoriDizi);
    return EXIT_SUCCESS;
}

